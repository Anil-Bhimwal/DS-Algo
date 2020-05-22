#include<bits/stdc++.h>
using namespace std;
int findMaximum(int input[],int size){
  int max=input[0];
  for(int i=1;i<size;i++){
    if(input[i]>max){
      max=input[i];
    }
  }
  return max;
}
int main() {

  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int n ,k,ans=0;
    cin>>n>>k;
      int* candies = new int[n];
    for(int j=0;j<n;j++){
      cin>>candies[j];
    }
    int start =0, end =findMaximum(candies,n);
    int count=0;
    for(;start<=end;){
      int mid = (start+end)/2;
      for(int l=0;l<n;l++){
        int num_of_kids= candies[l]/mid;
        count+= num_of_kids;
      }
      if(count>=k)
        {
          start=mid+1;
        ans=mid;
          count=0;
        }
        else{
          end=mid-1;
          count=0;
        }

    }
    cout<<ans<<endl;
  }
  return 0;
	// Write your code here
}
