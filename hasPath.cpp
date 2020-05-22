#include<iostream>
using namespace std;
/*void dfs(int **adjmat,bool* visited, int V, int start)
{

    cout<<start<<" ";
    visited[start]=true;
    for(int i=0;i<V;i++)
    {
        if(!visited[i]&&adjmat[start][i]==1)
        {
            dfs(adjmat,visited,V,i);
        }
    }
}*/

bool hasPath(int **adjmat,bool *visited, int V,int v1,int v2)
{
    if(adjmat[v1][v2]==1)
    {
        return true;
    }
    visited[v1]=true;
    for(int i=0;i<V;i++)
    {
        if(!visited[i]&&adjmat[v1][i]==1)
        {
            bool ans=hasPath(adjmat,visited, V, i,v2);
            if(ans==true)
                return true;
        }

    }
    return false;
}
int main()
{
	int V,E;
	cout<<"enter V and E"<<endl;
	cin>>V>>E;
	int **adjmat=new int*[V];
	for(int i=0;i<V;i++)
	{
		adjmat[i]=new int[V];
		for(int j=0;j<V;j++)
        {
            adjmat[i][j]=0;
        }
	}
	for(int i=0;i<E;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adjmat[v1][v2]=1;
        adjmat[v2][v1]=1;
    }
    bool*visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
   // dfs(adjmat,visited,V,0);
   //has path
   int v1, v2;
   cin>>v1,v2;
   bool ans=hasPath(adjmat,visited,V,v1,v2);
   if(ans)
    cout<<"true"<<endl;
   else
    cout<<"flase"<<endl;
}
