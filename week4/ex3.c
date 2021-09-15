#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int BUFFER_LEN = 256;

int main() {
    char line[BUFFER_LEN];
    char* argv[256];
    char* path= "/bin/";
    char progpath[256];
    int argc;

    while (1) {
        printf(">> ");
        if (!fgets(line, BUFFER_LEN, stdin)) { break; }

        if(strcmp(line, "exit\n")==0) { break; }

        int ret = system(line);
        if (WIFSIGNALED(ret) &&
            (WTERMSIG(ret) == SIGINT || WTERMSIG(ret) == SIGQUIT))
                break;
    }
    return 0;
}
