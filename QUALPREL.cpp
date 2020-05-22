#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int N, K;
        cin>>N>>K;
        int *arr=new int[N];
        for(int j=0;j<N;j++){
            cin>>arr[j];
        }
        sort(arr,arr+N,greater<int>());
        if(K>=N)
        {
            cout<<"wrong value of K"<<endl;
        }
        else{
            int counts=0;
            for(int j=0;j<N;j++)
            {
                if(arr[j]>=arr[K-1])
                {
                    counts++;
                }
            }
            cout<<counts<<endl;
        }

    }
}

