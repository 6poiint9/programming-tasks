#include <stdio.h>
#include <stdlib.h> // file  operations

#include <unistd.h> // read(), write() and close()
#include <sys/socket.h> // socket(), bind()...
#include <sys/un.h>
#include <string.h>

#include <pthread.h>   
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // initilize mutex 

#include <signal.h>

// sokcet file path 
#define SOCKET_PATH "/tmp/socket_path"

#define BUFFER_SIZE 100 // buffer 100 bytes 

int server_fd;  

void cleanup_exit(int signum) {
  close(server_fd);
  unlink(SOCKET_PATH);
  pthread_mutex_destroy(&lock); // cleanup mutex 
  printf("👋 Server shut down gracefully!\n");
  exit(0); 
}

int main()
{
  int client_fd; // file descriptor
  struct sockaddr_un addr; 
  char buffer[BUFFER_SIZE]; 
   
  signal(SIGINT, cleanup_exit); // handler-fkt 

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
      printf("Socket received 👍: type=TEXT, content=%s, size=13\n", buffer); 
  
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
 
  return 0;
}

