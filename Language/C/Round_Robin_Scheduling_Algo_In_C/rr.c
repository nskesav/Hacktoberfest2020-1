#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "makefile.h"
void main(int argc, char *argv[])
{
	int n,i,quanta;
	float avg_wt,avg_tat;
	int bt[20],p[20];
	printf("\nEnter the Number of Jobs (MAX 20):");
	scanf("%d",&n);
	for(i = 0; i<n ; i++)
	{
		printf("Enter the BURST Time for %d Process:  ",i+1);
		scanf("%d",&bt[i]);	
		p[i] = i+1;
	}
	printf("Enter the Time Quantum:  ");
	scanf("%d",&quanta);
	rrcalculate(n,bt,p,&avg_wt,&avg_tat,quanta);   
	printf("\n");
    	printf("\nAverage Waiting Time=%f",avg_wt);
    	printf("\nAverage Turnaround Time=%f\n",avg_tat);
}	 

