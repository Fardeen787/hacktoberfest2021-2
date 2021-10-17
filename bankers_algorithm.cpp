#include<iostream>
#define size 10
using namespace std;
int main()
{
    int max_Need[size][size],alloc[size][size],rem_Need[size][size],avail[size],completed[size],safe[size],req[size];
    int p,r,i,j,count=0,process;

    printf("No of process requied :");
    scanf("%d",&p);

    printf("No of recourcess requied :");
    scanf("%d",&r);

    for(i=0;i<p;i++)
    {
        completed[i]=0;
    }

    printf("Enter the max_Need [matrix] for each process");
    for(int i=0;i<p;i++)
    {
        printf("\n For Each process %d:",(i+1));
        for(int j=0;j<r;j++)
        {
            scanf("%d",&max_Need[i][j]);
        }
    }

    printf("Enter the Allocated resources of each process");
    for(int i=0;i<p;i++)
    {
         printf("\n For Each process %d:",(i+1));
        for(int j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

     printf("Enter the Available resources of process");
     for(j=0;j<r;j++)
     {
        scanf("%d",&avail[j]);

     }





     for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            rem_Need[i][j]=max_Need[i][j]-alloc[i][j];
        }
    }

    do
     {
     process=-1;
     for(i=0;i<p;i++)
     {
       if(completed[i]==0)
        {
             process=i;

         for(j=0;j<r;j++)
         {
             if(avail[j]<rem_Need[i][j])
             {
                 process=-1;
                 break;
             }
         }
        }
        if(process!=-1)
        break;
     }

     if(process!=-1)
     {
         printf("Process %d Completes\n",(process+1));
         safe[count]=process+1;
         count++;

         for(int j=0;j<r;j++)
         {
             avail[j]=avail[j]+alloc[process][j];
             alloc[process][j]=0;
             max_Need[process][j]=0;
             rem_Need[process][j]=0;
             completed[process]=1;
         }

     }

     }while(count!=p && process!=-1);
     cout<<endl;
     cout<<"Safe Sequence of processes=\n";
     for(int i=0;i<p;i++)
     {
         cout<<safe[i]<<" ";
     }
}


