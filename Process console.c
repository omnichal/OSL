#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) { 
    pid_t pid;
    int n = argc - 1;
    char arr[] = {"/home/student/BinarySearch.out"};
    char *a[n];
    for (int i = 1; i < n + 1; i++) {
        a[i - 1] = argv[i];
    }
    
    pid = fork();
    if (pid == 0) {
        printf("Child id: %d\n", getpid());
        execvp(arr, a);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("Fork failed");
        return 1;
    }

    return 0;
}
