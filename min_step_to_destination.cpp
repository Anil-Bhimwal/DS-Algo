#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
const int inf= 1e7;
bool found= false;
int row, col;
int  destination(vector<vector<char>>&input, int x1, int y1, int x2, int y2,
                 vector<vector<bool>>& vis){

    if(x1>=row||x1<0){
        return inf;
    }
    if(y1>=col||y1<0){
        return inf;
    }


    if(x1==x2 && y1==y2){
        found= true;
        return 1e7;
    }
    if(input[x1][y1]=='t')
    {
        dp[x1][y1]= inf;
        vis[x1][y1]= 1;
        return inf;
    }

    int &ans= dp[x1][y1];
    if(vis[x1][y1])
        return ans;

     //case 1:
    if(found==true){
        return min(ans, destination(input, x1+1,y1, x2,y2,vis)+1);
    }else{
       ans= min(ans, destination(input, x1+1,y1, x2,y2,vis)+1);
    }


    //case 2
    if(found==true){
        return min(ans, destination(input, x1, y1+1, x2, y2,vis )+1);
    }else{
       ans= min(ans, destination(input, x1, y1+1, x2, y2,vis )+1);
    }

    //case 3:
    if(found==true){
        return min(ans, destination(input, x1, y1-1, x2, y2,vis )+1);

    }else{
           ans= min(ans, destination(input, x1, y1-1, x2, y2,vis )+1);
    }

    //case 4:
    if(found==true){
        return min(ans, destination(input, x1-1, y1, x2, y2,vis )+1);
    }else{
           ans= min(ans, destination(input, x1-1, y1, x2, y2,vis )+1);
    }



    vis[x1][y1]= 1;
    return ans;


}
int main() {

    cin>>row>>col;
    vector<vector<char>> input(row);
    for(int i=0;i<row;i++){
        input[i].resize(col);
        for(int j=0;j<col;j++){
            char ch ;
            cin>>ch;
            input[i].push_back(ch);
        }
    }

    int x1, x2, y1,y2;
    cin>>x1>>y1>>x2>>y2;
    vector<vector<bool>> vis;
    vis.resize(row, vector<bool>(col, 0));


    dp.resize(row, vector<int>(col, INT_MAX));
    cout<<destination(input, x1,y1, x2,y2,vis);
    return 0;

	// Write your code here
}
