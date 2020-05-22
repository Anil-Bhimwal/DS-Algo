int helper(vector<int> &a, vector<int>&b, int i, int d,int oil){
    int n= a.size();
    if(i==d){
        return 0;
    }
    if(oil+a[0]>b[i]){

        int ans1= helper(v1, v2,(i+1)%n, d, oil+a[0]-b[0]);
        if(ans!= -1){
            return ans1+ 1;
        }else{
            return -1;
        }
    }else{
        return -1;
    }

}
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n= A.size();
    if(n==0){
        return 0;
    }
    if(A[0]==0){
        return 0;
    }
     for(int i=0;i<n;i++){
         if(A[i]>B[i]){
             int ans= helper(A, B, i+1, i, A[i]-B[i] );
             res= min(res, ans);
        }
     }
    return res;

}

