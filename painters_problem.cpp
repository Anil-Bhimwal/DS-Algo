#include<iostream>
#include<climits>
using namespace std;
int sum(int arr[], int s, int e){
    int ans= 0;
    for(int i=s;i<=e;i++){
        ans+= arr[i];
    }
    return ans;
}

int main()
{
  int t; cin>>t;
  while(t--)
  {
      int n; cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
      cin>>arr[i];
      int k;
      cin>>k;
      int dp[k+1][n+1];

      for(int i=1;i<=n;i++){
          dp[1][i]= sum(arr, 0, i-1);
      }
      for(int i=1;i<=k;i++){
          dp[i][1]= arr[0];
      }
      for(int i=2;i<=k;i++){
          for(int j=2;j<=n;j++){
              int best= INT_MAX;
              for(int l=i-1;l<=j;l++){
                  best= min(best, max(dp[i-1][l], sum(arr, l, j-1)));
              }
              dp[i][j]= best;
          }
      }
      cout<<dp[k][n]<<endl;
  }

}
