#include <bits/stdc++.h>
#include<string>
using namespace std;

string removeDuplicatesFromString(string str)
{
    long long int counter = 0;

    long long int i = 0;
    long long int size = str.size();

    long long int x;

    long long int length = 0;

    while (i < size)
    {
        x = str[i] - 97;

        if ((counter & (1 << x)) == 0)
        {

            str[length] = 'a' + x;

            counter = counter | (1 << x);

            length++;
        }
        i++;
    }

    return str.substr(0, length);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int arr[n];
        for(long long int i=0;i<n;i++)
        cin>>arr[i];

        sort(arr,arr+n,greater<long long int>());
        /*long long int largest=arr[0];
        //cout<<largest;
            while(largest>0)
            {
                long long int d=largest%10;
                num[d]=-1;
                largest=largest/10;
            }
            long long int sum=arr[0];*/
    long long int final_sum=0;
    for(int j=0;j<n;j++)
    {
        long long int num[10]={0,1,2,3,4,5,6,7,8,9};
        long long int sum=0;
        for(long long int i=j;i<n;i++)
        {
            bool flag=1;
            long long int data=arr[i];
            //cout<<data<<" ";
            string s=to_string(data);
            string str=removeDuplicatesFromString(s);
            long long int new_data=stoi(str);
            while(new_data>0)
            {
                long long int d=new_data%10;
                if(num[d]!=-1)
                {
                    num[d]=-1;
                    new_data=new_data/10;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                sum+=arr[i];
        }
        //cout<<sum<<" ";
        final_sum=max(final_sum,sum);
    }
        //for(int i=0;i<10;i++)
        //cout<<num[i]<<" ";
        cout<<final_sum<<endl;
    }
    return 0;
}
