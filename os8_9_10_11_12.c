/* Q1 cp and pp os8.c */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int numChildProcesses;
    printf("Enter the number of child processes to be created: ");
    scanf("%d", &numChildProcesses);

    printf("Parent process ID: %d\n", getpid());
    
    for (int i = 0; i < numChildProcesses; i++) {
        pid_t childPid = fork();
        
        if (childPid < 0) {
            printf("Fork failed\n");
            return 1;
        } else if (childPid == 0) {
            printf("Child process ID: %d, Parent process ID: %d\n", getpid(), getppid());
            break;
        }
    }

    return 0;
}

======================================================================
/* Q2 cp and pp os9.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void createProcessTree() {
    pid_t p1, p2, p3, p4, p5, p6, p7, p8, p10, p11;
    
    // Process P1
    p1 = getpid();
    printf("P1 (PID: %d) -> ", p1);
    
    // Process P2
    p2 = fork();
    if (p2 == 0) {
        printf("P2 (PID: %d), ", getpid());
        printf("P2 (PPID: %d), ", getppid());
        // Process P5
        p5 = fork();
        if (p5 == 0) {
            printf("P5 (PID: %d), ", getpid());
            printf("P5 (PPID: %d), ", getppid());
            
            // Process P10
            p10 = fork();
            if (p10 == 0) {
                printf("P10 (PID: %d)\n", getpid());
                printf("P10 (PPID: %d), ", getppid());
                exit(0);
            }
            exit(0);
        }
        
        // Process P6
        p6 = fork();
        if (p6 == 0) {
            printf("P6 (PID: %d)\n", getpid());
            printf("P6 (PPID: %d), ", getppid());
           exit(0);
        }
        
        // Process P7
        p7 = fork();
        if (p7 == 0) {
            printf("P7 (PID: %d)\n", getpid());
            printf("P7 (PPID: %d), ", getppid());
            exit(0);
        }
        
        exit(0);
    }
    
    // Process P3
    p3 = fork();
    if (p3 == 0) {
        printf("P3 (PID: %d), ", getpid());
        printf("P3 (PPID: %d), ", getppid());
        // Process P4
        p4 = fork();
        if (p4 == 0) {
            printf("P4 (PID: %d), ", getpid());
            printf("P4 (PPID: %d), ", getppid());
            // Process P11
            p11 = fork();
            if (p11 == 0) {
                printf("P11 (PID: %d)\n", getpid());
                printf("P11 (PPID: %d), ", getppid());
                exit(0);
            }
            
            exit(0);
        }
        
        // Process P8
        p8 = fork();
        if (p8 == 0) {
            printf("P8 (PID: %d)\n", getpid());
            printf("P8 (PPID: %d), ", getppid());
            exit(0);
        }
        
        exit(0);
    }
}

int main() {
    createProcessTree();
    return 0;
}
======================================================================
/* Q3 cp and pp os10.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t parent_pid = getpid();

    pid_t child1_pid, child2_pid, child3_pid, child4_pid;

    child1_pid = fork();

    if (child1_pid == 0) {
        // Child 1
        printf("Child 1 (PID: %d) created\n", getpid());
        exit(0);
    }

    child2_pid = fork();

    if (child2_pid == 0) {
        // Child 2
        printf("Child 2 (PID: %d) created\n", getpid());
        exit(0);
    } 
    
    child3_pid = fork();

    if (child3_pid == 0) {
        // Child 3
        printf("Child 3 (PID: %d) created\n", getpid());
        exit(0);
    }

    child4_pid = fork();

    if (child4_pid == 0) {
        // Child 4
        printf("Child 4 (PID: %d) created\n", getpid());
        exit(0);
    }

    if (getpid() == parent_pid) {
        // Parent process
        waitpid(child3_pid, NULL, 0); // Wait for Child 3 to terminate
        printf("Child 3 (PID: %d) terminated\n", child3_pid);

        waitpid(child2_pid, NULL, 0); // Wait for Child 2 to terminate
        printf("Child 2 (PID: %d) terminated\n", child2_pid);

        waitpid(child1_pid, NULL, 0); // Wait for Child 1 to terminate
        printf("Child 1 (PID: %d) terminated\n", child1_pid);

        waitpid(child4_pid, NULL, 0); // Wait for Child 4 to terminate
        printf("Child 4 (PID: %d) terminated\n", child4_pid);

        printf("Parent process (PID: %d) terminated\n", getpid());
        exit(0); // Terminate the parent process
    }

    return 0;
}
    
======================================================================
/* Q4 zombie process (1) os11.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Child process
        printf("Child process (PID: %d) started\n", getpid());
        printf("Child process (PID: %d) exiting\n", getpid());
        exit(0);
    } else if (child_pid > 0) {
        // Parent process
        printf("Parent process (PID: %d)\n", getpid());
        sleep(3); // Wait for the child process to become a zombie
    } else {
        // Error occurred while forking
        printf("Fork error\n");
        exit(1);
    }

    return 0;
}
======================================================================
/* Q4 zombie process prevent (2) os12.c */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid > 0) {
        // Parent process
        wait(NULL); // wait for child process exit and prevent the occurrence of zombie
    } else if (child_pid == 0) {
        // Child process
        printf("Child process: I am the child process!\n");
        printf("Child process: Exiting...\n");
    } else {
        // Forking failed
        printf("Fork failed!\n");
        return 1;
    }

    return 0;
}
=========================================================================
/* Q5 orphan process os13.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Child process
        printf("Child process (PID: %d) started\n", getpid());
        sleep(5); // Sleep for 5 seconds to ensure parent exits first
        printf("Child process (PPID: %d) after parent exit\n", getppid()); // Print PPID
        exit(0);
    } else if (child_pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) created child process (PID: %d)\n", getpid(), child_pid);
        sleep(3); // Sleep for 3 seconds to simulate work and then exit
        printf("Parent process (PID: %d) exiting\n", getpid());
        exit(0);
    } else {
        // Error occurred while forking
        printf("Fork error\n");
        exit(1);
    }

    // Uncomment this line to wait for the child process to exit (optional)
    // wait(NULL);

    return 0;
}
