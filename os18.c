consider a billing counter in a shopping or in department store where customer has to wait in a queue to bill their products and make the payment. The 1st customer in line gets the bill done first and 
then next customer in the queue gets the chance to make the payment and so on. Determine suitable scheduling algorithm and write c program to implement scheduling algorithm.
  (i) Display Gantt char and calculate average waiting time and turn around time taken by customer.  Also display waiting time and turn around time taken by each customer. 
  (ii) Consider that when billing is done for one customer and at same time , another customer arrives in the queue with minimum 1 product for billing then hance should be given for customer with minimum product.
  (iii) Suppose if some priority is given to custoers based on factors such as regular customer, sadaxo acrt payment and bulk product cusomer,etc. A customer card wil be given which shows the priority as platinum, gold and silver. 
      During billig the preference will be given to customers base on card priority. Write a c program to implement above scenarios by identifying appropriate scheduling algorithm.

2. In a quiz competition, there are 4 teams paricipating on a quiz, there are several rounds conducted in each round, when a question is asked each team will be given 2 minutes time to answer and if they fail then chance will be given to next team. 
  Likewiswe all teams get 2 minutes to answer. Write a program to implemnet a CPU scheduling algorithm to calculate average turnaround time and average waiting time taken by teams in competition. Display all results in detail.

  #include <stdio.h>

#define MAX_TEAMS 10
#define TIME_PER_QUESTION 2  // Minutes

struct Team {
    int team_number;
    int questions_answered;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int num_teams, num_rounds, i, j;

    printf("Enter the number of teams: ");
    scanf("%d", &num_teams);

    if (num_teams > MAX_TEAMS) {
        printf("Error: Maximum number of teams allowed is %d\n", MAX_TEAMS);
        return 1;
    }

    printf("Enter the number of rounds: ");
    scanf("%d", &num_rounds);

    struct Team teams[MAX_TEAMS];

    // Initialize team data
    for (i = 0; i < num_teams; i++) {
        teams[i].team_number = i + 1;
        teams[i].questions_answered = 0;
        teams[i].waiting_time = 0;
        teams[i].turnaround_time = 0;
    }

    // Simulate the quiz competition
    for (i = 0; i < num_rounds; i++) {
        for (j = 0; j < num_teams; j++) {
            // Skip teams that have already answered all questions
            if (teams[j].questions_answered == num_rounds) {
                continue;
            }

            // Team answers the question (simulated)
            printf("\nRound %d, Team %d: Answer (2 minutes)\n", i + 1, teams[j].team_number);

            // Update waiting time for other teams
            for (int k = 0; k < num_teams; k++) {
                if (k != j) {
                    teams[k].waiting_time += TIME_PER_QUESTION;
                }
            }

            teams[j].questions_answered++;
        }
    }

    // Calculate turnaround time for each team
    for (i = 0; i < num_teams; i++) {
        teams[i].turnaround_time = teams[i].waiting_time + (num_rounds * TIME_PER_QUESTION);
    }

    // Calculate average waiting and turnaround times
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (i = 0; i < num_teams; i++) {
        avg_waiting_time += teams[i].waiting_time;
        avg_turnaround_time += teams[i].turnaround_time;
    }
    avg_waiting_time /= num_teams;
    avg_turnaround_time /= num_teams;

    // Display results
    printf("\n** Quiz Competition Results (Round Robin Scheduling) **\n");
    printf("Team\t Questions Answered\t Waiting Time (min)\t Turnaround Time (min)\n");
    printf("-----\t--------------------\t-----------------\t-----------------\n");
    for (i = 0; i < num_teams; i++) {
        printf("%d\t\t %d\t\t\t %d\t\t\t %d\n", teams[i].team_number, teams[i].questions_answered, teams[i].waiting_time, teams[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %.2f minutes\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f minutes\n", avg_turnaround_time);

    return 0;
}
==================================================
  #include <stdio.h>

void waiting_time(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void turn_around_time(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void avg_time(int processes[], int n, int at[], int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    waiting_time(processes, n, bt, wt);
    turn_around_time(processes, n, bt, wt, tat);

    printf("Processes\t Arrival time\t Burst time\t Waiting time\t Turnaround time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", processes[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %.2f\n", (float)total_tat / (float)n);

    // Gantt chart
    printf("\nGantt Chart:\n");

        for (int i = 0; i < n; i++) {
            printf("P%d ", processes[i]);
            
        }
        printf("\n");
  
}

int main() {
    int processes[] = {1, 2};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5};
    int arrival_time[] = {0, 0};
    avg_time(processes, n, arrival_time, burst_time);
    return 0;
}
