#include<bits/stdc++.h>
using namespace std;
int func(int *arr, unordered_map<int,int> &m, int n,int sum){
    if(n==0){

        return sum;
    }

    //not include the number
    int sum1= func(arr+1, m,n-1,sum);

    // include the number

    int num= arr[0];

    vector<int> v;
    bool flag=true;
    while(num != 0){

        int r= num%10;

        if(m[r]!=arr[0]&&m[r]!=-1){

            for(int i=0;i<v.size();i++){
               m[v[i]]=-1;
            }
            flag= false;
            break;
        }
        else{
            v.push_back(r);
            m[r]= arr[0];
        }
        num /=10;
    }
    int sum2;
    if(flag==true){

        sum2= func(arr+1, m, n-1,sum+arr[0]);

    }

    else
         sum2= func(arr+1, m, n-1,sum);
    num=arr[0];
    while(num!=0){
        int r= num%10;
        if(m[r]==arr[0])
        m[r]=-1;
        num/=10;
    }
    //cout<<"sum2"<<sum2<<endl;
    return max(sum1, sum2);

}

int main(){
   int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr= new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<int, int> m;
        for(int i=0;i<10;i++){
            m[i]=-1;
        }
        cout<<func(arr, m ,n,0);
    }
}
