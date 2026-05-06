#include <iostream>
#include <queue>
using namespace std;

int main() {

    int n, e;

    cout<<"Enter number of vertices and edges: ";
    cin>>n>>e;

    int graph[10][10]={0};

    cout<<"Enter edges:\n";

    for(int i=0;i<e;i++) {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    int visited[10]={0};

    queue<int> q;

    int start;

    cout<<"Enter starting vertex: ";
    cin>>start;

    visited[start]=1;
    q.push(start);

    cout<<"BFS Traversal: ";

    while(!q.empty()) {

        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int i=0;i<n;i++) {

            if(graph[node][i]==1 && visited[i]==0) {
                visited[i]=1;
                q.push(i);
            }
        }
    }

    return 0;
}