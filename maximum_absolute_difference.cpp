#include<bits/stdc++.h>
using namespace std;
int maxArr(vector<int> &A) {
     int max1 = INT_MIN, min1 = INT_MAX;
    int max2 = INT_MIN, min2 = INT_MAX;

    for (int i = 0; i < A.size(); i++) {

        // Updating max and min variables
        // as described in algorithm.
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);
    }

    // Calculating maximum absolute difference.
    return max(max1 - min1, max2 - min2);
}
int main(){
    vector<int>input;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        input.push_back(num);
    }
    cout<<maxArr(input);
    return 0;
}
