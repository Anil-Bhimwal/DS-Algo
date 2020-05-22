#include <bits/stdc++.h>
using namespace std;
void longest(string s){
    int n= s.size();
    bool L[n][n];
    memset(L, 0, sizeof(L));
    for(int i=0;i<n;i++){
        L[i][i]= 1;
    }
    //for length =2
    int maxlength=1,start=0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            L[i][i+1]=1;
            start=i;
            maxlength=2;
        }
    }
    for (int cl=3; cl<=n; cl++)
    {
        for (int i=0; i<n-cl+1; i++)
        {
            int j = i+cl-1;
            if (L[i+1][j-1] && s[i] == s[j])
            {
                L[i][j] = true;

                if (cl > maxlength)
                {
                    start = i;
                    maxlength = cl;
                }
            }
        }
    }
    for(int i=start;i<=start+maxlength-1;i++){
        cout<<s[i];
    }
    cout<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string input;
	    cin>>input;
	    longest(input);
	    //cout<<longest(input)<<endl;
	}
	return 0;
}
