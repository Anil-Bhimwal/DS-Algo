#include<bits/stdc++.h>
using namespace std;
char game(vector<vector<char>> &input , int x, int y, char ch, int nots){
    int n=input.size();
    if(x>=n){
        return '4';
    }
    if(y>=n||y<0){
        return '4';
    }
    char newchar=input[x][y];
    if(input[x][y]==ch){
        if(nots==2){
           return ch;
        }
    newchar=ch;
        if(input[x][y]=='.')
            nots=0;
    }
    else if(input[x][y]=='.'){
        newchar= '.';
        nots= 0;
    }
    else{
        nots= 0;
        newchar= input[x][y];

    }


    char ans=game(input , x+1,y,newchar, nots+1);
    if(ans!='4')
        return ans;
    else //case 2:
    {
        ans=game(input, x+1,y-1,newchar, nots+1);
        if(ans!='4')
            return ans;
        else {
            //case 3:

            ans= game(input, x,y+1,newchar, nots+1);
            if(ans!='4'){
                return ans;
            }else{
                ans= game(input, x+1, y+1,newchar, nots+1);
                if(ans!='4'){
                    return ans;
                }
                else{
                    return '4';
                }

            }

        }
    }


}
int main() {
    int n;
    cin>>n;
    vector<vector<char>>input(n);
    for(int i=0;i<n;i++){
       // input[i].resize(n);
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            input[i].push_back(ch);
        }
    }
    char ans= game(input,0,0,'.',0);
    if(ans!='4'){
        cout<<ans<<endl;
    }else
    cout<<"ongoing"<<endl;
	// Write your code here
}
