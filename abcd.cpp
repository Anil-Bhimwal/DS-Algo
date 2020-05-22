#include<bits/stdc++.h>
using namespace std;
    /*string longestPalindrome(string s) {
        if(s.size()<=0){
            return "";
        }
        if(s.size()==1)
            return s;
        string out1="";
        string out2="";
        string out3="";
        // cout<<s.substr(1,s.size()-2)<<endl;
        // return s;
        if(s.size()>1&&s[0]==s[s.size()-1])
         out1= s.substr(0,1)+longestPalindrome(s.substr(1,s.size()-2))+s.substr(s.size()-1);

         out2=
         longestPalindrome(s.substr(1,s.size()-1));
         out3 =longestPalindrome(s.substr(0,s.size()-1));


        if(out2.size()>out3.size()){
            if(out1.size()>max(out2.size(),out3.size())){
                return out1;
            }
            else{
                return out2;
            }
        }
        else{
            if(out1.size()>max(out2.size(),out3.size())){
                return out1;
            }
            else{
                return out3;
            }
        }
    }*/
    int main(){
        string s;
        cin>>s;
        //cout<<longestPalindrome(s);
        int n= s.size();
        cout<<s.substr(0,n)<<endl;
        cout<<s.substr(1,n-2)<<endl;
        cout<<s.substr(0,n-1)<<endl;
        cout<<s.substr(1,n-1);
    }
