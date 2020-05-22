#include <bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int>* adj;

    int helper(int s, int d, bool* visited, int &count){
        visited[s]= true;
        if(s==d){
            count++;
        }
        else{
            list<int>:: iterator i;
            for(i= adj[s].begin();i!= adj[s].end();i++){
                if(!visited[*i]){
                    helper(*i, d, visited, count);
                }
            }
        }
        visited[s]=false;
    }
    public:
    Graph(int V){
        this->V=  V;
        adj= new list<int>[V];
    }

    void addEdge(int a, int b){
        adj[a].push_back(b);
    }



    int countPaths(int s, int d){
        int count=0;
        bool* visited= new bool[V];
        for(int i=0;i<V;i++){
            visited[i]= false;
        }

         helper(s, d, visited, count);
         return count;
    }



};
int main() {
    int V, E;
    cin>>V>>E;

	Graph g(V);
	for(int i=0;i<E;i++){
	    int v1,v2;
	    cin>>v1>>v2;
	    g.addEdge(v1, v2);
	}

    int s, d;
    cin>>s>>d;
    cout << g.countPaths(s, d);


}
