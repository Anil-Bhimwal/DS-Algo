#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10001];
int * topoSort(vector<int> graph[],int N);
void helper(int start,vector<int> graph[],bool *visited,stack<int>&st)
{
    visited[start]=true;
    vector<int>a = graph[start];
    for(int i=0;i<a.size();i++)
    {
        if(!visited[a.at(i)])
        {
            helper(a.at(i),graph,visited,st);
        }
    }
    st.push(start);
}
int * topoSort(vector<int> graph[], int N)
{
    stack<int> st;
   bool *visited=new bool[N];
   for(int i=0;i<N;i++)
   {
       visited[i]=false;
   }
   for(int i=0;i<N;i++)
   {
       if(!visited[i])
       {
           helper(i,graph,visited,st);
       }
   }
   for(;!st.empty();)
   {
       cout<<st.top()<<" ";
       st.pop();
   }

   
}

int main()
{
int T;
cin>>T;
while(T--)
{
    memset(graph,0,sizeof graph);
    int N,E;
    cin>>E>>N;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    topoSort(graph,N);
    /*bool valid =true;
    for(int i=0;i<N;i++)
    {
        int n=graph[res[i]].size();
        for(int j=0;j<graph[res[i]].size();j++)
        {
            for(int k=i+1;k<N;k++)
            {
                if(res[k]==graph[res[i] ] [j] )
                    n--;
            }
        }
        if(n!=0)
        {
            valid =false;
            break;
        }
    }
    if(valid==false)
        cout<<0<<endl;
    else
        cout<<1<<endl;
}
}*/

}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You need to complete this function */

