#include<stdio.h>  

 
int main()  
{  
    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    printf(" Total number of teams: ");  
    scanf("%d", &NOP);  
    y = NOP; 
 
for(i=0; i<NOP; i++)  
{  
printf("\n Enter the Arrival and Burst time of the team[%d]\n", i+1);  
printf(" Arrival time is: ");  
scanf("%d", &at[i]);  
printf("Burst time is: \t");  
scanf("%d", &bt[i]);  
temp[i] = bt[i]; 
}  

printf("Enter the Time Quantum for each team: \t");  
scanf("%d", &quant);  
// Display the process No, burst time, Turn Around Time and the waiting time  
printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
for(sum=0, i = 0; y!=0; )  
{  
if(temp[i] <= quant && temp[i] > 0) 
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    count=1;  
    }    
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }  
    if(temp[i]==0 && count==1)  
    {  
        y--;  
        printf("\n %d \t\t\t %d\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        count =0;    
    }  
    if(i==NOP-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}  

avg_wt = wt /NOP;  
avg_tat = tat/NOP;  
printf("\n Average Turn Around Time: %0.f", avg_tat);  
printf("\n Average Waiting Time: %0.f", avg_wt);  

}  
