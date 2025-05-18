#include <stdio.h>
#include <stdlib.h> // file  operations

#include <unistd.h> // read(), write() and close()
#include <sys/socket.h> // socket(), bind()...
#include <sys/un.h>
#include <string.h>

// socket pile path 
#define SOCKET_PATH "/tmp/socket_path"

#define BUFFER_SIZE 100 

int main()
{
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
  const char *message = "Hello from client!";
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

  return 0;
}




