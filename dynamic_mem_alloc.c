/* given various memory partitions of sizes 20kb,40kb,60kb,50kb,30kb and 25kb
in order.Write a c program to implement various dynamic memory allocation alg
orithms to allocate the following processes of various sizes such as 
35kb,21kb,46kb,15kb in order.Apply 3 algorithms in c(first fit,best fit,
worst fit. */

#include <stdio.h>
#include <stdbool.h>

// Memory partition sizes
int partitions[] = {20, 40, 60, 50, 30, 25};
int numPartitions = sizeof(partitions) / sizeof(partitions[0]);

// Process sizes
int processes[] = {35, 21, 46, 15};
int numProcesses = sizeof(processes) / sizeof(processes[0]);

// Memory allocation algorithms
void firstFit() {
    int allocation[numProcesses];
    bool allocated[numPartitions];

    // Initialize allocation array
    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1;
    }

    // Initialize allocated array
    for (int i = 0; i < numPartitions; i++) {
        allocated[i] = false;
    }

    // Iterate through each process
    for (int i = 0; i < numProcesses; i++) {
        // Find the first partition that can accommodate the process
        for (int j = 0; j < numPartitions; j++) {
            if (partitions[j] >= processes[i] && !allocated[j]) {
                // Allocate the process to the partition
                allocation[i] = j;
                allocated[j] = true;
                break;
            }
        }
    }

    // Print allocation
    printf("First Fit Allocation:\n");
    for (int i = 0; i < numProcesses; i++) {
        if (allocation[i] != -1) {
            printf("Process %d allocated to Partition %d\n", i + 1, allocation[i] + 1);
        } else {
            printf("Process %d could not be allocated\n", i + 1);
        }
    }
}

void bestFit() {
    int allocation[numProcesses];
    bool allocated[numPartitions];

    // Initialize allocation array
    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1;
    }

    // Initialize allocated array
    for (int i = 0; i < numPartitions; i++) {
        allocated[i] = false;
    }

    // Iterate through each process
    for (int i = 0; i < numProcesses; i++) {
        int bestFitIdx = -1;
        int bestFitSize = -1;

        // Find the partition with the smallest size that can accommodate the process
        for (int j = 0; j < numPartitions; j++) {
            if (partitions[j] >= processes[i] && !allocated[j]) {
                if (bestFitIdx == -1 || partitions[j] < bestFitSize) {
                    bestFitIdx = j;
                    bestFitSize = partitions[j];
                }
            }
        }

        // Allocate the process to the partition
        if (bestFitIdx != -1) {
            allocation[i] = bestFitIdx;
            allocated[bestFitIdx] = true;
        }
    }

    // Print allocation
    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < numProcesses; i++) {
        if (allocation[i] != -1) {
            printf("Process %d allocated to Partition %d\n", i + 1, allocation[i] + 1);
        } else {
            printf("Process %d could not be allocated\n", i + 1);
        }
    }
}

void worstFit() {
    int allocation[numProcesses];
    bool allocated[numPartitions];

    // Initialize allocation array
    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1;
    }

    // Initialize allocated array
    for (int i = 0; i < numPartitions; i++) {
        allocated[i] = false;
    }

    // Iterate through each process
    for (int i = 0; i < numProcesses; i++) {
        int worstFitIdx = -1;
        int worstFitSize = -1;

        // Find the partition with the largest size that can accommodate the process
        for (int j = 0; j < numPartitions; j++) {
            if (partitions[j] >= processes[i] && !allocated[j]) {
                if (worstFitIdx == -1 || partitions[j] > worstFitSize) {
                    worstFitIdx = j;
                    worstFitSize = partitions[j];
                }
            }
        }

        // Allocate the process to the partition
        if (worstFitIdx != -1) {
            allocation[i] = worstFitIdx;
            allocated[worstFitIdx] = true;
        }
    }

    // Print allocation
    printf("\nWorst Fit Allocation:\n");
    for (int i = 0; i < numProcesses; i++) {
        if (allocation[i] != -1) {
            printf("Process %d allocated to Partition %d\n", i + 1, allocation[i] + 1);
        } else {
            printf("Process %d could not be allocated\n", i + 1);
        }
    }
}

int main() {
    firstFit();
    bestFit();
    worstFit();

    return 0;
}
