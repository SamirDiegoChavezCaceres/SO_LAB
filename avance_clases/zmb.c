#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int crear(char* programa, char** argumentos) {
    pid_t pid_hijo;
    pid_hijo = fork();
    if(pid_hijo<0) {
        fprintf(stderr, "se dio un error");
    }
    else if (pid_hijo>0){ //comienza padre
        printf("= %d \n", getpid());
        sleep(5);
        printf("despierta\n");
    } 
    else { //comienza hijo
        sleep(30);
        printf("terminado\n");
        printf("= %d \n", getppid());
        printf("= %d \n", getpid());
    }
}
int main() {
    char* argumentos[] = {"ls", "-lh", "/", NULL};
    crear("ls", argumentos);
    return 0;
}