#include <stdio.h>

int main() {
    int n, i, j;
    int burst[20], priority[20], wait[20], turnaround[20];
    int total_wait = 0, total_turnaround = 0;
    int temp, tempP;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Enter priority for process %d (lower number = higher priority): ", i + 1);
        scanf("%d", &priority[i]);
    }

    // Sort processes based on priority (Bubble Sort)
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(priority[j] > priority[j + 1]) {
                // Swap priority
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
                // Swap burst times to keep alignment
                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time
    wait[0] = 0; // first process has 0 waiting time
    for(i = 1; i < n; i++) {
        wait[i] = wait[i - 1] + burst[i - 1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        turnaround[i] = burst[i] + wait[i];
        total_wait += wait[i];
        total_turnaround += turnaround[i];
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst[i], priority[i], wait[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wait / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);

    return 0;
}
