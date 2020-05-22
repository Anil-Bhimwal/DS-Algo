/*Given n non-negative integers a1, a2, ..., an, where each represents a
point at coordinate (i, ai). n vertical lines are drawn such that the two
 endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
  with x-axis forms a container, such that the container contains the most water.
  Your program should return an integer which corresponds to the maximum area of water
   that can be contained ( Yes, we know maximum area instead of maximum volume sounds
weird. But this is 2D plane we are working with for simplicity ).
  */

#include<bits/stdc++.h>
using namespace std;
int area(int x1, int y1, int x2, int y2){
    return (abs(x2-x1)*min(y2,y1));
}
int main(){
    int n;
    cin>>n;
    int *arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maximum= 0;
    int leftHeight=arr[0];
    int rightHeight = arr[n-1];
    int j=n-1;
    int i=0;
    int start=0;
    int endd=n-1;
    for(;i<j;){
        leftHeight=arr[i];
        rightHeight = arr[j];
    int currarea= area(i, arr[i], j, arr[j]);
    if(currarea> maximum){
        maximum= currarea;
        start= i;
        endd=j;
    }
    if(leftHeight> rightHeight){
        j--;
    }
    else{
        i++;
    }
    }
    cout<<start<< ","<<endd<<"area: "<<maximum<<endl;
}
