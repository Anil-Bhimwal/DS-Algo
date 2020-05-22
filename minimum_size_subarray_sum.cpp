#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;
    int *nums= new int[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int result = n;
    int start=0;
     int sum=0;
     int i=0;
      bool flag = false;
    while(i<=n){
            if(sum>=s){

                flag=true; //mark if there flag such a subarray
                if(start==i-1){
                        return 1;
                 }

                result = min(result, i-start);
                 // cout<<"minimum length for "<<start<<":"<<result<<endl;
                 sum=sum-nums[start];
                //cout<<sum<<endl;
                 start++;
            }else{
                sum = sum+nums[i];
                i++;
            }
        }

    if(flag){
        cout<<"minimum length: "<<result<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
}
