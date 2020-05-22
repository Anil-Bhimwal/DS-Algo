#include <bits/stdc++.h>
using namespace std;
#include<unordered_map>
#include<climits>

int main() {
	unordered_map< char , int> mapi;
	int len;
	int max=INT_MIN;
	string input;
	cin>>input;
	int start=0, currs=0,i;
	mapi[input[0]]=0;
	for( i=1;i<input[i]!='\0';i++){
	    if(mapi.find(input[i]) == mapi.end()){
            mapi[input[i]]=i;
	    }else{
	        if(mapi[input[i]]<currs){
	            //cuurent wali string k left m h to phle hi include kiya ja chuka h
	            mapi[input[i]]=i;
	        }else{
	            //repeating case
	            len= i-currs;

	            if(max<len){
	                max=len;
	                start=currs;
	            }
	            currs=mapi[input[i]] + 1;
	            mapi[input[i]]=i;
	        }

	    }
	}
	if(max<i-currs){
        max= i-currs;
        start= currs;
	}
	for(int i=start;i<start+max;i++){
	    cout<<input[i];
	}
	return 0;
}
