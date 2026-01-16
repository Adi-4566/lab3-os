#include <stdio.h>

int main() {
    int n, i, j, time, total = 0, count;
    int qt; // time quantum
    int burst[20], temp[20];
    int wait[20], turnaround[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        temp[i] = burst[i]; // copy burst time to temp array
    }

    printf("Enter time quantum: ");
    scanf("%d", &qt);

    time = 0; // current time
    count = 0;

    while(1) {
        int done = 1;
        for(i = 0; i < n; i++) {
            if(temp[i] > 0) {
                done = 0;
                if(temp[i] > qt) {
                    time += qt;
                    temp[i] -= qt;
                } else {
                    time += temp[i];
                    wait[i] = time - burst[i];
                    temp[i] = 0;
                }
            }
        }
        if(done) break;
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        turnaround[i] = burst[i] + wait[i];
        total += wait[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst[i], wait[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total / n);

    total = 0;
    for(i = 0; i < n; i++)
        total += turnaround[i];

    printf("Average Turnaround Time: %.2f\n", (float)total / n);

    return 0;
}
