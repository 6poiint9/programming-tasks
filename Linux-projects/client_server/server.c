#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SOCKET_PATH "/tmp/socket_path"
#define FIFO_C2S "/tmp/fifo_c2s"
#define FIFO_S2C "/tmp/fifo_s2c"
#define BUFFER_SIZE 100

int server_fd;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void cleanup_exit(int signum) {
    close(server_fd);
    unlink(SOCKET_PATH);
    unlink(FIFO_C2S);
    unlink(FIFO_S2C);
    pthread_mutex_destroy(&lock);
    printf("👋 Server shut down gracefully!\n");
    exit(0);
}

int main(int argc, char *argv[])
{
  signal(SIGINT, cleanup_exit); // handler-fkt 

  int use_socket = 1;

  if (argc > 1 && strcmp(argv[1], "-np") == 0)
    use_socket = 0;

  if (use_socket) { 
    int client_fd; // file descriptor
    struct sockaddr_un addr; 
    char buffer[BUFFER_SIZE]; 

    server_fd = socket(AF_UNIX, SOCK_STREAM, 0); 
  // socket(int domain, int type, int protocol)
    if (server_fd == -1) {
      perror("socket"); // perror prints to stderr 
      exit(EXIT_FAILURE); 
    }
  
    // Setting up the socket-address structure:    
    memset(&addr, 0, sizeof(struct sockaddr)); // initilize memory -> set bytes to 0
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path)-1); // set file sun_path
 
    // unlink before binding -> avoid errror
    unlink(SOCKET_PATH);
    //bind(int fd, const struct sockaddr *addr, socklen_t len)    
    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(struct sockaddr_un)) == -1) {
      perror("bind error"); 
      close(server_fd); 
      exit(EXIT_FAILURE); 
    } 
  
    // now passive -> file-descriptor, backlog (maximum number of clients waiting)
    // start listening 
    if (listen(server_fd, 5) == -1) {
      perror("listen");
      close(server_fd); 
      exit(EXIT_FAILURE); 
    }
    printf("Server listening 👂 on %s\n", SOCKET_PATH);
    printf("Server started. Press Ctrl+C to quit 🚫\n"); 

    // loop to accept clients 
    while(1) {
      client_fd = accept(server_fd, NULL, NULL); 
      if (client_fd == -1) {
        perror("accept");
        continue; // zum nächsten client gehen  
      }
      // lock before accesing recourses 
      pthread_mutex_lock(&lock);
      // => only one mutex to prevent deadlock 

      printf("Socket: Accepted new client connection ✅\n"); 
   
  
      // read client message 
      ssize_t s_read = read(client_fd, buffer, BUFFER_SIZE - 1); 
      if (s_read > 0) {
        buffer[s_read] = '\0'; 
        printf("Socket received 👍: type=TEXT, content=%s, size=%zu\n", buffer,s_read); 
  
        // respond 
        const char *response = "Hello from Server! 😉"; 
        write(client_fd, response, strlen(response));
        printf("Response sent back to client 🕊️\n");
      } else if (s_read == -1) {
        perror("read"); 
      }
        close(client_fd); // close client-connection when done
    
      // unlock after sharing 
        pthread_mutex_unlock(&lock); // prevent deadlock, leaks 
      } 
  }
  else {
       printf("Server using named pipes mode 🧵\n");

        mkfifo(FIFO_C2S, 0666);
        mkfifo(FIFO_S2C, 0666);

        char buffer[BUFFER_SIZE];

        while (1) {
            int fd_read = open(FIFO_C2S, O_RDONLY);
            if (fd_read == -1) { perror("open read"); continue; }

            pthread_mutex_lock(&lock);
            ssize_t bytes_read = read(fd_read, buffer, BUFFER_SIZE - 1);
            close(fd_read);

            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                printf("FIFO received 🧵: %s\n", buffer);

                int fd_write = open(FIFO_S2C, O_WRONLY);
                const char *response = "Hello from Server via FIFO!";
                write(fd_write, response, strlen(response));
                close(fd_write);
                printf("FIFO response sent 🧵\n");
            }

            pthread_mutex_unlock(&lock);
        }
    }
    
  return 0;
}

