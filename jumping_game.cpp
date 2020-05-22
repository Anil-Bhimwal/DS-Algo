#include <bits/stdc++.h>
using namespace std;

int def(vector<vector<char>> &board, vector<vector<bool>> &visited,int jump, int drow, int dcol, int cr ,int cc){
    if(cr==drow && cc== dcol){
            visited[cr][cc]=1;
        return 1;
    }
    if(jump>board.size()){
        return 0;
    }
    visited[cr][cc]=1;
    bool ans=0, flag= false;
    for(int i=1;i<=jump;i++){


        if(cr+i>board.size()||cr-i<0){
            break;
        }
        //for moving down
        for(int j= cc;j>=0;j--){//moving left
            if(board[cr][j]=='x'){
                if(board[cr+i][j]=='x'&&!visited[cr+i][j]){
                    ans= def(board, visited, i, drow, dcol, cr+i, j );
                    if(ans){
                        return 1;
                    }
                }
            }else{
                break;

            }
        }


        // moving right from current col
        for(int j= cc;j<board[0].size();j++){
            if(board[cr][j]=='x'){
                if(board[cr+i][j]=='x'&&!visited[cr+i][j]){
                    ans= def(board, visited, i, drow, dcol, cr+i, j );
                    if(ans){
                        return 1;
                    }
                }
            }else{
                break;
            }
        }
        // for moving up
         for(int j= cc;j>=0;j--){//moving left
            if(board[cr][j]=='x'){
                if(board[cr-i][j]=='x'&&!visited[cr-i][j]){
                    ans= def(board, visited, i, drow, dcol, cr-i, j );
                    if(ans){
                        return 1;
                    }
                }
            }else{
                break;
            }
        }


        // moving right from current col
        for(int j= cc;j<board[0].size();j++){
            if(board[cr][j]=='x'){
                if(board[cr-i][j]=='x'&&!visited[cr-i][j]){
                    ans= def(board, visited, i, drow, dcol, cr-i, j );
                    if(ans){
                        return 1;
                    }
                }
            }else{
                break;
            }
        }
    }
    //visited[cr][cc]=0;
    return 0;

}
int main() {
	// your code goes here
	int n, m;
	cin>>n>>m;
	vector<vector<char>>board(n, vector<char>(m));
	vector<vector<bool>>visited(n, vector<bool>(m, 0));

	//last row should contain all 'x'
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        cin>>board[i][j];
	    }
	}

	int row,col;
	cin>>row>>col;
	int jump;
	for(jump=1;jump<=50;jump++){
	    if(def(board, visited,jump, row, col,n-1, 0)){
	        break;
	    }else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    visited[i][j]=0;
                }
            }
	    }
	}
	if(jump==51){
	    cout<<"-1"<<endl;
	}else{
	    cout<<jump<<endl;
	}

	return 0;
}
