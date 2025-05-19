#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SOCKET_PATH "/tmp/socket_path"
#define FIFO_C2S "/tmp/fifo_c2s"
#define FIFO_S2C "/tmp/fifo_s2c"
#define BUFFER_SIZE 100

int main(int argc, char *argv[])
{
  int use_socket = 1;
  const char *message = "Hello from client!";
 
  
  for (int i = 1; i < argc; ++i) {
      if (strcmp(argv[i], "-np") == 0) use_socket = 0;
      else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) message = argv[++i];
  }
  
  if (use_socket) {
    int client_fd; 
    struct sockaddr_un addr; 

    char buffer[BUFFER_SIZE]; 
   
    client_fd = socket(AF_UNIX, SOCK_STREAM, 0); 
    if (client_fd == -1) {
      perror("socket"); 
      exit(EXIT_FAILURE); 
    }

    // set up address
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1); 
  
    if (connect(client_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
      perror("connect");
      close(client_fd);
      exit(EXIT_FAILURE);
    }
    printf("Connected to socket server 😊\n"); 
  
    // send message 
    if (write(client_fd, message, strlen(message)) == -1) {
      perror("write");
      close(client_fd);
      exit(EXIT_FAILURE);
    }
    printf("Message sent 🫡: type=TEXT, content=%s, size=%zu\n", message, strlen(message));

    ssize_t bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read > 0) {
      buffer[bytes_read] = '\0';
      printf("Server replied 🥳: type=TEXT content=%s, size=%zd\n",buffer, bytes_read);
    } else if (bytes_read == 0) {
        printf("Server closed the connection.\n");
    } else {
      perror("read");
    }
  
    close(client_fd); 
  } 
  else {
    printf("Client using named pipes mode 🧵\n");

        int fd_write = open(FIFO_C2S, O_WRONLY);
        if (fd_write == -1) {
            perror("open write");
            exit(EXIT_FAILURE);
        }
        write(fd_write, message, strlen(message));
        close(fd_write);
        printf("Message sent 🧵: %s\n", message);

        char buffer[BUFFER_SIZE];
        int fd_read = open(FIFO_S2C, O_RDONLY);
        ssize_t bytes_read = read(fd_read, buffer, BUFFER_SIZE - 1);
        close(fd_read);

        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("Server replied 🧵: %s\n", buffer);
        }
  }
  return 0;
}




