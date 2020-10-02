#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "makefile.h"
void rrcalculate(int n,int *bt,int *p,float *avg_wt,float *avg_tat,int quanta)
{
	int i,j,temp,pos,tat[20],wt[20],t=0;
	float total = 0;
	int rem_bt[20];
	for(i=0;i<n;i++)
		rem_bt[i] = bt[i];
	while (1) 
	{ 
		int done = 1; 
		for (int i = 0 ; i < n; i++) 
		{ 
			if (rem_bt[i] > 0) 
			{ 
				done = 0; 
				if (rem_bt[i] > quanta) 
				{ 
					t += quanta; 
					rem_bt[i] -= quanta; 
				} 
				else
				{ 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i];  
					rem_bt[i] = 0; 
				} 
			} 
		} 
		if (done == 1) 
		break; 
	} 
	for(i=0;i<n;i++)
	{
       	total+=wt[i];
   	}
      	*avg_wt=total/n;      
  	total=0;
	printf("\nJOB\t     Burst Time\t      Waiting Time\t   Turnaround Time");
	for(i=0;i<n;i++)
  	{
  		tat[i]=bt[i]+wt[i];   
  		total+=tat[i];
  	 	printf("\n%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
  	}
  	*avg_tat=total/n; 
}

