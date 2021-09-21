#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

char* filename = "ex11.txt";
FILE *fp;

void *printHello(void *threadid) {
    fprintf(fp, "Hello from thread %ld\n", (long) threadid);
    pthread_exit(0);
}


int main() {
    fp = fopen(filename, "w");
    int n_threads = 3;
    pthread_t threads[n_threads];

    for (long t = 0; t < n_threads; t++) {
        fprintf(fp, "Creating thread %ld\n", t);
        pthread_create(&threads[t], NULL, printHello, (void*) t);
        fprintf(fp, "Terminating of thread %ld\n", t);
    }

    pthread_exit(0);
    fclose(fp);
}
