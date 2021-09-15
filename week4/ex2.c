#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main() {
    for (int i = 0; i < 3; i++) {
        fork();
        sleep(5);
    }
    return 0;
}
