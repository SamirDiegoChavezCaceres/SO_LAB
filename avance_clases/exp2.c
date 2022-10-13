#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int crear(char* programa, char** argumentos) {
    pid_t pid_hijo;
    pid_hijo = fork();
    if(pid_hijo!=0) {
        printf("Soy padre = %d  --  %d\n", getpid(), pid_hijo);
        sleep(20);
        return pid_hijo;
    }
    else { //comienza hijo
        printf("|Soy padre = %d\n", getppid());
        printf("|Soy hijo = %d\n", getpid());
        execvp(programa, argumentos);
        fprintf(stderr, "se dio un error");
        abort();
    }
}
int main() {
    char* argumentos[] = {"ls", "-lh", "/", NULL};
    crear("ls", argumentos);
    return 0;
}