#include <iostream>
#include <climits>
using namespace std;

int main() {

    int n;

    cout<<"Enter number of vertices: ";
    cin>>n;

    int graph[10][10];

    cout<<"Enter adjacency matrix:\n";

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];

    int start;

    cout<<"Enter source vertex: ";
    cin>>start;

    int dist[10], visited[10]={0};

    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;

    dist[start]=0;

    for(int count=0;count<n-1;count++) {

        int min=INT_MAX, u;

        for(int i=0;i<n;i++) {

            if(!visited[i] && dist[i]<=min) {
                min=dist[i];
                u=i;
            }
        }

        visited[u]=1;

        for(int v=0;v<n;v++) {

            if(!visited[v] && graph[u][v] &&
               dist[u]!=INT_MAX &&
               dist[u]+graph[u][v]<dist[v]) {

                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    cout<<"Vertex\tDistance\n";

    for(int i=0;i<n;i++)
        cout<<i<<"\t"<<dist[i]<<endl;

    return 0;
}