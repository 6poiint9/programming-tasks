#include <stdio.h>
#include <stdlib.h> // file  operations

#include <unistd.h> // read(), write() and close()
#include <sys/socket.h> // socket(), bind()...
#include <sys/un.h>
#include <string.h>

// sokcet file path 
#define SOCKET_PATH "/tmp/socket_path"



//#include <errno.h>        // errno and error codes


int main()
{
  int server_fd; // file descriptor
  struct sockaddr_un addr; 
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
   

   
  return 0;
}

