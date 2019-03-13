#include<iostream>
using namespace std;
int c[5],k=0;
void Waitingtime1(int p[],int n,int bt[],int wt[],int q)
{
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=bt[i];
    }
    int t=0;
    while(1)
    { bool done=true;
        for(int i=0;i<n;i++)
        {
            if(a[i]>0)
            { done=false;
                if(a[i]>q)
                {
                    t+=q;
                    a[i]-=q;
                }
                else
                {
                    t=t+a[i];
                    wt[i]=t-bt[i];
                    a[i]=0;
                }
            }
        }
        if(done==true)
            break;
    }
}

void Turnaroundtime(int p[],int n,int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }
}

void avgtime1(int p[],int n,int bt[],int q)
{
    int wt[n],tat[n],w=0,t=0;

    Waitingtime1(p,n,bt,wt,q);
    Turnaroundtime(p,n,bt,wt,tat);
   cout<<"Process "<<" Burst time "<<" Waiting time "<<" turn around time\n";
   for(int i=0;i<n;i++)
   {
       w=w+wt[i];
       t=t + tat[i];
       cout<<" "<<i+1<< "\t\t" << bt[i]<<"\t  "<<wt[i] <<"\t\t "<< tat[i] <<endl;
   }

   cout<< "Average waiting time= "
       <<(float)w/(float)n;
   cout<<"\nAverage turn around time= "
       <<(float)t/(float)n<<endl;
       c[k]=(float)t/(float)n;
        k++;
}

void Waitingtime(int p[],int n,int bt[],int wt[] )
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1] + bt[i-1];
    }
}




void avgtime(int p[],int n,int bt[])
{
    int wt[n],tat[n],w=0,t=0;

    Waitingtime(p,n,bt,wt);
    Turnaroundtime(p,n,bt,wt,tat);
   cout<<"Process "<<" Burst time "<<" Waiting time "<<" turn around time\n";
   for(int i=0;i<n;i++)
   {
       w=w+wt[i];
       t=t + tat[i];
       cout<<" "<<i+1<< "\t\t" << bt[i]<<"\t  "<<wt[i] <<"\t\t "<< tat[i] <<endl;
   }

   cout<< "Average waiting time= "
       <<(float)w/(float)n;
   cout<<"\nAverage turn around time= "
       <<(float)t/(float)n<<endl;
   c[k]=(float)t/(float)n;
   k++;
}

void sortBurstTime(int bt[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                int temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }

        }
    }
}

int main()
{
    int p[]={1,2,3};
    int burst_time[]={10,14,3};
    cout<<"-----------------------------First Come First Serve---------------------------"<<endl;
    avgtime(p,3,burst_time);
    cout<<"-----------------------------Round Robin----------------------------------------"<<endl;
    avgtime1(p,3,burst_time,5);
    cout<<"----------------------------Shortest Job First---------------------------------"<<endl;
    sortBurstTime(burst_time,3);
    avgtime(p,3,burst_time);

    int min=c[0];
    int z;
    for(int i=1;i<3;i++)
    {
        if(min>c[i])
        {
            min=c[i];
            z=i;
        }
    }
   /* for(int i=0;i<3;i++)
    {
        cout<<c[i]<<endl;
    } */
    if(z==0)
        cout<<"FCFS is best"<<endl;
    else if(z==2)
        cout<<"SJF is best"<<endl;
    else
        cout<<"RR is best"<<endl;



    return 0;
}
