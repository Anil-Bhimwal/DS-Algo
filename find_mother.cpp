#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int> *adj;

    void dfs(int v, bool *visited){
        visited[v]= true;
        list<int> :: iterator i;
        for(i= adj[v].begin();i!= adj[v].end();i++){
            if(!visited[*i]){
                dfs(*i, visited);
            }
        }
    }
    public:
    Graph(int V){
        this->V=V;
        adj= new list<int>[V];
    }

    void addEdge(int a, int b){
        adj[a].push_back(b);
    }

    int findMother(){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i]= false;
        }

       int v=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i , visited);
                v=i;
            }
        }

        for(int i=0;i<V;i++){
            visited[i]= false;
        }

        dfs(v, visited);

        for(int i=0;i<V;i++){
           if( visited[i]= false){
               return -1;
           }
        }
        return v;

     }

};
int main(){
     Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
    cout<<g.findMother();
}
