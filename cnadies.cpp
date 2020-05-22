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
    int n ,k;
    cin>>n>>k;
      int* candies = new int[n];
    for(int j=0;j<n;j++){
      cin>>candies[j];
    }
    int start =0, end =findMaximum(candies,n);
    int count=0;
    for(;start<end;){
      int mid = (start+end)/2;
      for(int l=0;l<n;l++){
        int num_of_candies_per_kid= candies[l]/k;
        while(num_of_candies_per_kid>= mid){
          num_of_candies_per_kid-= mid;
          count++;
        }
        
      }
      if(count>k)
        {
          start=mid+1;
          count=0;
        }
        else if(count<k){
          end=mid-1;
          count=0;
        }
        else{
          cout<< mid<<endl;
          count=0;
        }
    }
  }
  return 0;
	// Write your code here
}
