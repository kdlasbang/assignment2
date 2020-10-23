#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h> 

int main(int argc, char const *argv[],char const *envp[]) 
{   
    int new_socket, valread;
    char buffer[1024] = {0}; 
    char *hello = "Hello from server"; 
    new_socket = atoi(argv[1]);
    if(setuid(65534)==-1){
            perror("UID Failed");
            exit(EXIT_FAILURE);
        }
    else{
        printf("Child Process start\n");
        printf("UID: %d\n", getuid());
        valread = read( new_socket , buffer, 1024); 
        printf("%s\n",buffer ); 
        send(new_socket , hello , strlen(hello) , 0 ); 
        printf("Hello message sent\n");
        printf("Child process Done\n");
    }
    return 0;
}