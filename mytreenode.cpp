#include<vector>
#include<queue>
#include<iostream>
using namespace std;
#include"TreeNode.h>

// making a function to take input levelwise

TreeNode<int>* takeinput()takeInput(){
queue<TreeNode<int>*> pending_node;
cout<<"enter the root:";
int root_data;
cin>>root_data;
TreeNode<int>*root=new TreeNode
}

int count(TreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	int ans = 0;
	for(int i = 0;i < root->children.size(); i++){
		TreeNode<int>* child = root->children[i];
		ans += count(child);
	}
	return ans + 1;
}
