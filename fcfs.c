
#include <stdio.h>

struct Customer {
    int id;
    int arrivalTime;
    int serviceTime;
    int startTime;
    int endTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(struct Customer* customers, int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < customers[i].arrivalTime) {
            currentTime = customers[i].arrivalTime;
        }
        customers[i].startTime = currentTime;
        customers[i].endTime = currentTime + customers[i].serviceTime;
        customers[i].waitingTime = currentTime - customers[i].arrivalTime;
        customers[i].turnaroundTime = customers[i].waitingTime + customers[i].serviceTime;
        currentTime = customers[i].endTime;
    }
}

void sortByArrivalTime(struct Customer* customers, int n) {
    struct Customer temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (customers[j].arrivalTime > customers[j + 1].arrivalTime) {
                temp = customers[j];
                customers[j] = customers[j + 1];
                customers[j + 1] = temp;
            }
        }
    }
}

void displayOrder(struct Customer* customers, int n) {
    printf("Customer Order:\n");
    for (int i = 0; i < n; i++) {
        printf("Customer %d ", customers[i].id);
    }
    printf("\n");
}

void displayTimes(struct Customer* customers, int n) {
    printf("Customer\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", customers[i].id, customers[i].waitingTime, customers[i].turnaroundTime);
    }
}

int main() {
    int n;
    printf("Enter the number of customers: ");
    scanf("%d", &n);

    struct Customer customers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter AT Customer %d: ", i + 1);
        scanf("%d", &customers[i].arrivalTime);
        printf("Enter BT for Customer %d: ", i + 1);
        scanf("%d", &customers[i].serviceTime);
        customers[i].id = i + 1;
    }

    sortByArrivalTime(customers, n);
    calculateTimes(customers, n);
    displayOrder(customers, n);
    displayTimes(customers, n);

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += customers[i].waitingTime;
        totalTurnaroundTime += customers[i].turnaroundTime;
    }
    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnaroundTime = (float)totalTurnaroundTime / n;
    printf("Average WT: %.2f\n", averageWaitingTime);
    printf("Average TT: %.2f\n", averageTurnaroundTime);

    return 0;
}
