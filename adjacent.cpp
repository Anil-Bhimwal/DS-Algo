#include <bits/stdc++.h>
using namespace std;
void remove(string &s){
    int n= s.size();
    int count=0,i=0,start=0;
    for(;s[i]!='\0';i++){
        if(s[i]==s[i+1]){
            count++;

        }else{

            for(int j=start;j<n-count;j++){
                s[j]=s[j+count+1];
            }

            i=start;

        }
    }
    cout<<s<<endl;

}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string input;
	    cin>>input;
	    remove(input);
	    //cout<<longest(input)<<endl;
	}
	return 0;
}
