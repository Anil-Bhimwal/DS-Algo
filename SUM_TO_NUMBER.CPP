#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int p=0;p<t;p++){
        int size;
        cin>>size;
        int *arr= new int[size];
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
        int number;
        cout<<"Enter Number:"<<endl;
        cin>>number;
        int curr_sum= arr[0];
        int start=0, i;
        for(i=1;i<=size;i++){
            while(curr_sum> number&&start<i-1){
                curr_sum -= arr[start];
                start++;
            }
            if(curr_sum==number)
                {
                    cout<< "start:"<<start<< "End: "<<i-1<<endl;
                    break;
                }
                if(i<size)
               curr_sum += arr[i];
        }
    }
}
