#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

void DFS(int node) {

    cout<<node<<" ";
    visited[node]=1;

    for(int i=0;i<n;i++) {

        if(graph[node][i]==1 && visited[i]==0) {
            DFS(i);
        }
    }
}

int main() {

    int e;

    cout<<"Enter number of vertices and edges: ";
    cin>>n>>e;

    cout<<"Enter edges:\n";

    for(int i=0;i<e;i++) {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    int start;

    cout<<"Enter starting vertex: ";
    cin>>start;

    cout<<"DFS Traversal: ";
    DFS(start);

    return 0;
}