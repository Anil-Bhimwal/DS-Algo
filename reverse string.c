#include <stdio.h>

void reverse(string &s, int s, int l ){
    while(s<l){
            char temp= input[s];
            input[s]= input[l];
            input[l]= temp;
            s++;
            l--;
        }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string input;
        cin>>input;
        int s=0;
        int l=input.size()-1;
        reverse(input, s, l);
        s=0;
        for(int i=0;input[i]!='\0';i++){
            if(input[i]==' '||input[i]==9||input[i]==\n){
                l=i-1;
                reverse(input, s, l);
                s=i+1;
            }
        }
        cout<<input<<endl;
    }
	//code
	return 0;
}
