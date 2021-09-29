#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* stream = fopen("input.csv", "r");
    int at[10], at2[10], bt[10], ct[10], seq[10], re[10], wt[10], tat[10];
    int n = 0, i, j, pos, min, max = 0, k = 0;
    float av_tat = 0, av_wt = 0;
    char line[256];
    const char* tok;

    while (fgets(line, 256, stream)) {
        char* tmp = strdup(line);
        tok = strtok(line, ",");
        at[n] = atoi(tok);
        at2[n] = at[n];
        tok = strtok(NULL, ",\n");
        bt[n] = atoi(tok);
        free(tmp);
        n++;
    }

    int start = at[0];
    for(i = 1; i < n; i++) {
        if(start > at[i]) { start = at[i]; }
    }
    
    for(i = 0; i < n; i++) {
        if(max < at[i]) { max = at[i]; }
    }
    max++;

    for(i = 0; i < n; i++, k++) {
        min=max;
        for(j = 0; j < n; j++) {  
            if (at[j] != -1) {
                if(at[j] < min) {
                    min = at[j];
                    pos = j;
                }
            }
        }
        seq[k] = pos;
        if (start < at[pos]) {
            re[pos] = start;
            start = at[pos];
            start += bt[pos];
            at[pos] = -1;
            ct[pos] = start;
        } else {
            re[pos] = start;
            start += bt[pos];
            at[pos] = -1;
            ct[pos] = start;
        }
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at2[i];
        wt[i] = tat[i] - bt[i];
        av_tat += tat[i];
        av_wt += wt[i];
    }

    stream = fopen("ex1.txt", "w");
    fprintf(stream, "P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (i = 0; i < n; i++) {
        fprintf(stream, "P%-8d%-8d%-8d%-8d%-8d%-8d\n", i + 1, at2[i], bt[i], ct[i], tat[i], wt[i]);   
    }
    
    fprintf(stream, "Average Turnaround Time = %f\n", av_tat/n);
    fprintf(stream, "Average Waiting Time = %f\n", av_wt/n);

    return 0;
}
