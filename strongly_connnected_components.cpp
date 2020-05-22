#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int>* adj;

    void dfs(int v, bool* visited, stack<int> &s){
        visited[v]= true;

        list<int>::iterator i;
        for(i= adj[v].begin();i!= adj[v].end();i++){
            if(!visited[*i]){
                dfs(*i, visited, s);
            }
        }
        s.push(v);
    }



    void dfs2(int v, bool *visited){
        visited[v]=true;
        cout<<v<<" ";

        list<int>:: iterator i;
        for(i= adj[v].begin();i!= adj[v].end();i++){
            if(visited[*i]==false){
                dfs2(*i, visited);
            }
        }
    }
public:
    //constructor
    Graph(int v){
        this->V=v;
        adj= new list<int>[v];
    }

    void addEdge(int a, int b){
        adj[a].push_back(b);
    }

    Graph transpose(){
        Graph g(V);

        list<int> :: iterator i;
        for(int v=0;v<V;v++){
            for(i=adj[v].begin();i!=adj[v].end();i++){
                g.adj[*i].push_back(v);
            }
        }
        return g;
    }


    void scc(){
        stack<int> s;

        bool* visited= new bool[V];

        for(int i=0;i<V;i++){
            visited[i]=false;
        }

        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs(i, visited, s);
            }
        }

        Graph gt= transpose();

        for(int i = 0; i < V; i++)
        visited[i] = false;

        while(!s.empty()){
            int num= s.top();
            s.pop();
            if(visited[num]=false){
                gt.dfs2(num, visited);
                cout<<endl;
            }

        }


    }


};
int main(){
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.scc();
}
