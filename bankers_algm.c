/*In a competition, 5 students were participating for final round .T
he students were provided with necesssary resources such as 3 crayon
 boxes,14 sketch pens,12 glitter pens and 12 water colours.Write a c
  program to implement banker's algorithm for the given below matrix
   representation and display the following:
1.Need matrix
2.Safe sequence in which the processes may complete their execution
3.If student 1 is requesting  4 sketch pens and 2 glitter pens.Check whether it can be granted or not
*/

#include <stdio.h>

int main() {
    int k = 0, a = 0, b = 0, instance[5], availability[5], allocated[10][5], need[10][5], MAX[10][5], process, P[10], no_of_resources, cnt = 0, i, j, op[10];
   
    printf("\nEnter the number of resources: ");
    scanf("%d", &no_of_resources);
   
    printf("\nEnter the maximum instances for each resource:\n");
    for (i = 0; i < no_of_resources; i++) {
        availability[i] = 0;
        printf("%c = ", (i + 97));
        scanf("%d", &instance[i]);
    }
   
    printf("\nEnter the number of processes: ");
    scanf("%d", &process);
   
    printf("\nEnter the allocation matrix:\n");
    for (i = 0; i < process; i++) {
        P[i] = i;
        printf("P[%d]  ", P[i]);
        for (j = 0; j < no_of_resources; j++) {
            scanf("%d", &allocated[i][j]);
            availability[j] += allocated[i][j];
        }
    }
   
    printf("\nEnter the MAX matrix:\n");
    for (i = 0; i < process; i++) {
        printf("P[%d]  ", i);
        for (j = 0; j < no_of_resources; j++)
            scanf("%d", &MAX[i][j]);
    }

    // Calculate the need matrix
    for (i = 0; i < process; i++) {
        b = P[i];
        for (j = 0; j < no_of_resources; j++) {
            need[b][j] = MAX[b][j] - allocated[b][j];
        }
    }

    printf("\nNEED matrix\n");
for (i=0;i <process;i++) {
for (j=0;j<  no_of_resources ;j++)
printf("%d ", need[i][j]);
         printf("\n");
}
   

    // Banker's Algorithm
    while (a != -1) {
        a = -1;
        for (i = 0; i < process; i++) {
            b = P[i];
            cnt = 0;
            for (j = 0; j < no_of_resources; j++) {
                if (need[b][j] <= availability[j]) {
                    cnt++;
                }
            }
            if (cnt == no_of_resources) {
                op[k++] = b;
                for (j = 0; j < no_of_resources; j++)
                    availability[j] += allocated[b][j];
            } else {
                P[++a] = b;
            }
        }
    }

    printf("\nSafe sequence: ");
    for (i = 0; i < k; i++) {
        printf("P[%d] ", op[i]);
    }
    printf("\n");

    int student1 = 0; // Index of Student 1 (assuming it's 0)
    int requestR1 = 4;
    int requestR2 = 2;
    int requestR3 = 0;
    int requestR4 = 0;

   
    int canGrant = 1;

    for (j = 0; j < no_of_resources; j++) {
        if (requestR1 > need[student1][j] || requestR2 > need[student1][j]) {
            canGrant = 0; // Request exceeds need
            break;
        }
        if (requestR1 > availability[j] || requestR2 > availability[j]) {
            canGrant = 0; // Request exceeds available resources
            break;
        }
    }

    if (canGrant) {
        // Temporarily allocate resources
        for (j = 0; j < no_of_resources; j++) {
            availability[j] -= requestR1;
            availability[j] -= requestR2;
            allocated[student1][j] += requestR1;
            allocated[student1][j] += requestR2;
            need[student1][j] -= requestR1;
            need[student1][j] -= requestR2;
        }
        printf("Request granted! Updated allocation and need matrices.\n");
    } else {
        printf("Request cannot be granted. It would lead to an unsafe state.\n");
    }

    return 0;
}
