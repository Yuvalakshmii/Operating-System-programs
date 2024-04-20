/* in a software company,a team of 5 memebers are working on a project.
To make each memeber in the team to be aware of the current status of 
the project,they store the information nin a common file.The file is a 
shareable resource where more than 1 team member can read the file,when
 reading is performed,no other team member is allowed to update the file
  also when any one team member is updating his information,no other member
   should update or read the file .write a program in c to implement the 
   solution using semaphore to maintaing the consistency of 
the file by acheiving synchronisation among the team members*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_MEMBERS 5

// Shared data
char* file;
sem_t read_sem, write_sem;
int readers_count;

void* reader(void* arg) {
    int member_id = *(int*) arg;

    // Reading phase
    sem_wait(&read_sem);
    readers_count++;
    if (readers_count == 1) {
        sem_wait(&write_sem);
    }
    sem_post(&read_sem);

    // Read the file
    printf("Team member %d is reading the file: %s\n", member_id, file);

    // Reading phase end
    sem_wait(&read_sem);
    readers_count--;
    if (readers_count == 0) {
        sem_post(&write_sem);
    }
    sem_post(&read_sem);

    pthread_exit(NULL);
}

void* writer(void* arg) {
    int member_id = *(int*) arg;

    // Writing phase
    sem_wait(&write_sem);

    // Write to the file
    sprintf(file, "Status update from team member %d", member_id);
    printf("Team member %d updated the file.\n", member_id);

    // Writing phase end
    sem_post(&write_sem);

    pthread_exit(NULL);
}

int main() {
    pthread_t members[NUM_MEMBERS];
    int member_ids[NUM_MEMBERS];

    // Initialize shared data
    file = (char*) malloc(100 * sizeof(char));
    readers_count = 0;
    sem_init(&read_sem, 0, 1);
    sem_init(&write_sem, 0, 1);

    // Create reader threads
    for (int i = 0; i < NUM_MEMBERS; i++) {
        member_ids[i] = i + 1;
        pthread_create(&members[i], NULL, reader, &member_ids[i]);
    }

    // Create writer thread
    pthread_create(&members[NUM_MEMBERS], NULL, writer, &member_ids[NUM_MEMBERS]);

    // Wait for all threads to finish
    for (int i = 0; i <= NUM_MEMBERS; i++) {
        pthread_join(members[i], NULL);
    }

    // Cleanup
    free(file);
    sem_destroy(&read_sem);
    sem_destroy(&write_sem);

    return 0;
}
