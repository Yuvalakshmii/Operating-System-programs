/* consider that two processes a and b shares a variable x where 
initial value is 10.Assume that process a performs an increment 
operation on x and b performs an decrement operation on x.
Both process are running concurrently.Write a c program to implement 
the solution to achueve synchronization between the two processs and 
also avoidrace condition. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Shared variables
int x = 10;
int turn = 0;
int flag[2] = {0, 0}; // Flags to indicate readiness

// Function for process A (increment operation)
void* processA(void* arg) {
    int j = 0;
    while (1) {
        flag[j] = 1; // Process A is ready
        turn = 1 - j; // Allow process B to execute

        while (flag[1 - j] && turn == 1 - j) {
            // Wait if process B is ready and it's B's turn
        }

        // Critical Section: Increment x
        x++;
        printf("Process A: Incremented x to %d\n", x);

        flag[j] = 0; // Process A is out of the critical section
        // Remainder Section: Additional actions after critical section
    }
    return NULL;
}

// Function for process B (decrement operation)
void* processB(void* arg) {
    int i = 1;
    while (1) {
        flag[i] = 1; // Process B is ready
        turn = i; // Allow process A to execute

        while (flag[1 - i] && turn == i) {
            // Wait if process A is ready and it's A's turn
        }

        // Critical Section: Decrement x
        x--;
        printf("Process B: Decremented x to %d\n", x);

        flag[i] = 0; // Process B is out of the critical section
        // Remainder Section: Additional actions after critical section
    }
    return NULL;
}

int main() {
    pthread_t threadA, threadB;

    // Create threads for process A and process B
    pthread_create(&threadA, NULL, processA, NULL);
    pthread_create(&threadB, NULL, processB, NULL);

    // Wait for both threads to finish
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    return 0;
}
