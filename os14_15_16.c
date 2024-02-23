#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg) {
    // Get the thread ID using pthread_self()
    pthread_t tid = pthread_self();

    // Print the unique thread ID and message
    printf("Thread %ld: %s\n", (long)tid, (char *)arg);

    // Simulate some work to demonstrate thread execution
    sleep(1); // Sleep for 1 second

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int status;

    // Create the first thread with the message "First Thread"
    status = pthread_create(&thread1, NULL, thread_function, "First Thread");
    if (status != 0) {
        perror("pthread_create failed");
        exit(0);
    }

    // Create the second thread with the message "Second Thread"
    status = pthread_create(&thread2, NULL, thread_function, "Second Thread");
    if (status != 0) {
        perror("pthread_create failed");
        exit(0);
    }

    // Wait for both threads to finish
    status = pthread_join(thread1, NULL);
    if (status != 0) {
        perror("pthread_join failed");
        exit(0);
    }

    status = pthread_join(thread2, NULL);
    if (status != 0) {
        perror("pthread_join failed");
        exit(0);
    }

    //printf("Main thread: Both threads have finished.\n");

    return 0;
}
======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *thread_function(void *arg) {
    char *full_string = (char *)arg;

    printf("Thread (ID: %ld): Received string: %s\n", pthread_self(), full_string);

    // Extract and print name and register number
    char *name_end = strstr(full_string, ":");
    if (!name_end) {
        printf("Error: Invalid string format\n");
        return NULL;
    }

    *name_end = '\0'; // Temporarily terminate name string
    printf("Name: %s\n", full_string);

    char *register_number = name_end + 1;
    printf("Register number: %s\n", register_number);

    return NULL;
}

int main() {
    char full_string[100];

    printf("Enter your name and register number separated by a colon (e.g., John Doe:12345): ");
    fgets(full_string, sizeof(full_string), stdin);

    // Remove trailing newline from user input
    full_string[strcspn(full_string, "\n")] = '\0';

    pthread_t thread;
    int status = pthread_create(&thread, NULL, thread_function, full_string);
    if (status != 0) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }

    status = pthread_join(thread, NULL);
    if (status != 0) {
        perror("pthread_join failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
====================================================================
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread (ID: %ld) started\n", pthread_self());

    // Simulate some work
    for (int i = 0; i < 5; i++) {
        printf("Thread: Iteration %d\n", i + 1);
    }

    printf("Thread (ID: %ld) terminating using pthread_exit\n", pthread_self());
    pthread_exit(NULL);  // Explicitly terminate the thread
}

int main() {
    pthread_t thread;

    int status = pthread_create(&thread, NULL, thread_function, NULL);
    if (status != 0) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }

    printf("Main thread continuing...\n");

    // Do some work in the main thread
    for (int i = 0; i < 3; i++) {
        printf("Main thread: Iteration %d\n", i + 1);
    }

    printf("Main thread waiting for thread to finish...\n");

    status = pthread_join(thread, NULL);  // Wait for the thread to terminate
    if (status != 0) {
        perror("pthread_join failed");
        exit(EXIT_FAILURE);
    }

    printf("Main thread exiting\n");
    return 0;
}
====================================================================================
