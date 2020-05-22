#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct proccess
{
    int at,bt,ct,ta,wt,btt,pr;
    string pro_id;
}schedule;
bool compare(schedule a,schedule b)
{
    return a.at<b.at;
}

bool compare2(schedule a,schedule b)
{
    return a.pr>b.pr;
}

int main()
{
    schedule pro[10];
    int n,i,j,pcom;

    cout<<"Enter the number of process::";
    cin>>n;
    cout<<"Enter the Process id arrival time burst time and priority :::";
    for(i=0;i<n;i++)
    {
        cin>>pro[i].pro_id;
        cin>>pro[i].at;
        cin>>pro[i].bt;
        pro[i].btt=pro[i].bt;
        cin>>pro[i].pr;
    }

    sort(pro,pro+n,compare);
    i=0;
    pcom=0;
    while(pcom<n)
    {
        for(j=0;j<n;j++)
        {
            if(pro[j].at>i)
                break;
        }
        sort(pro,pro+j,compare2);
        if(j>0)
        {
            for(j=0;j<n;j++)
            {
                if(pro[j].bt!=0)
                    break;
            }
            if(pro[j].at>i)
                i=pro[j].at;
            pro[j].ct=i+1;
            pro[j].bt--;
        }

        i++;
        pcom=0;
        for(j=0;j<n;j++)
        {
            if(pro[j].bt==0)
                pcom++;
        }
    }
    cout<<"Process Id  "<<" Arrival Time  "<<" Burst Time  "<<" Completion Time   "<<" Turn Around Time "<<" Waiting Time  "<<"Priority "<<endl;
    for(i=0;i<n;i++)
    {
        pro[i].ta=pro[i].ct-pro[i].at;
        pro[i].wt=pro[i].ta-pro[i].btt;
        cout<<"    "<<pro[i].pro_id<<"\t\t"
        <<pro[i].at<<"\t\t"
        <<pro[i].btt<<"\t\t"
        <<pro[i].ct<<"\t\t"
        <<pro[i].ta<<"\t\t"
        <<pro[i].wt<<"\t\t"
        <<pro[i].pr;
        cout<<endl;
    }
    int total_wt=0,total_tat=0;
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + pro[i].wt;
        total_tat = total_tat + pro[i].ta;
    }

    cout << "\nAverage waiting time = "
    << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
    << (float)total_tat / (float)n;

    return 0;
}
