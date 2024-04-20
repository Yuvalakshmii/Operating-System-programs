#include <stdio.h>

typedef struct {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

int main() {
    Process processes[10];
    int i, j, smallest, count = 0, time, n;
    double avgWaitingTime = 0, avgTurnaroundTime = 0, end;

    printf("Enter the number of Processes:\n");
    scanf("%d", &n);

    printf("Enter arrival time\n");
    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        scanf("%d", &processes[i].arrivalTime);
    }

    printf("Enter burst time\n");
    for (i = 0; i < n; i++)
        scanf("%d", &processes[i].burstTime);

    for (i = 0; i < n; i++) {
        processes[i].waitingTime = processes[i].burstTime;
    }

    processes[9].burstTime = 9999;

    //completion
    for (time = 0; count != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && processes[i].burstTime < processes[smallest].burstTime && processes[i].burstTime > 0)
                smallest = i;
        }
        processes[smallest].burstTime--;
        if (processes[smallest].burstTime == 0) {
            count++;
            end = time + 1;
            processes[smallest].waitingTime = end - processes[smallest].arrivalTime - processes[smallest].waitingTime;
            processes[smallest].turnaroundTime = end - processes[smallest].arrivalTime;
            printf("Customer %d completed at time %lf\n", processes[smallest].id, end);
        }
    }

    // display table
    printf("Customer\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].id, processes[i].waitingTime, processes[i].turnaroundTime);
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("\n\nAverage waiting time = %lf\n", avgWaitingTime / n);
    printf("Average Turnaround time = %lf", avgTurnaroundTime / n);
    return 0;
}
