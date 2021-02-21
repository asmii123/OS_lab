/*Priority Schedduling Algorithm*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct process
{
    int pid;
    int bt;
    int wt;
    int tt;
    int prior;
}

p[10],temp;

int main()
{
    int i,j,n,totwt,tottt;
    float avg1,avg2;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        p[i].pid=i;
        printf("Enter the Burst Time: ");
        scanf("%d",&p[i].bt);
        printf("Enter the priority: ");
        scanf("%d",&p[i].prior);
    }

    for(i=1;i<n;i++) {
        for(j=i+1;j<=n;j++) {
            if(p[i].prior>p[j].prior)
            {
                temp.pid=p[i].pid;
                p[i].pid=p[j].pid;
                p[j].pid=temp.pid;
                temp.bt=p[i].bt;
                p[i].bt=p[j].bt;
                p[j].bt=temp.bt;
                temp.prior=p[i].prior;
                p[i].prior=p[j].prior;
                p[j].prior=temp.prior;
            }
        }
    }

    p[i].wt=0;
    p[1].tt=p[1].bt+p[1].wt;
    i=2;

    while(i<=n)
    {
        p[i].wt=p[i-1].bt+p[i-1].wt;
        p[i].tt=p[i].bt+p[i].wt;
        i++;
    }

    i=1;
    totwt=tottt=0;
    printf("\n Process \t BT \t WT \t TT");

    while(i<=n)
    {
        printf("\n%d\t\t %d\t %d\t %d\t",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
        totwt=p[i].wt+totwt;
        tottt=p[i].tt+tottt;
        i++;
    }
    
    avg1=(float)totwt/n;
    avg2=(float)tottt/n;
    printf("\n Avg. Waiting Time=%f \t Avg. Turnaround Time=%f\t",avg1,avg2);
    return 0;
}

