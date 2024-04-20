#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_func(void *arg) {
    //pthread_t tid = pthread_self();

    printf("Thread %ld: %s\n", (long)pthread_self(), (char *)arg);
    sleep(1);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    #define HANDLE_ERROR(msg) do { perror(msg); exit(0); } while (0)

    if (pthread_create(&t1, NULL, thread_func, "First Thread")) {
        HANDLE_ERROR("pthread_create failed");
    }

    if (pthread_create(&t2, NULL, thread_func, "Second Thread")) {
        HANDLE_ERROR("pthread_create failed");
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
======================================================================
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define HANDLE_ERROR(msg) do {perror(msg); exit(0); } while(0)

void *thread_function(void *arg) {

    char *str=arg;
    printf("Thread (ID: %ld): Received string: %s\n",(long)pthread_self(), str);

    char *name = strtok(str, ",");
    char *regno = strtok(NULL, ",");

    printf("Name: %s\nRegister number: %s\n",name, regno);

    return NULL;
}

int main() {
    char str[100];

    printf("Enter your name,register number: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    pthread_t t;
    if (pthread_create(&t, NULL, thread_function, str)) HANDLE_ERROR("pthread_create failed");
    if (pthread_join(t, NULL)) HANDLE_ERROR("pthread_join failed");
    return 0;
}
====================================================================
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int isTerminated = 0;

void *thread_function(void *arg) {
    printf("Thread (ID: %ld) started\n", (long)pthread_self());
    while (!isTerminated) {
        printf("Thread is running...\n");
    }

    printf("Thread is terminating...\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, thread_function, NULL);

    sleep(1);

    isTerminated = 1;

    pthread_join(thread, NULL);

    printf("Main thread exiting\n");
    return 0;
}

====================================================================================
