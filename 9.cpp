#include <iostream>
#include <climits>
using namespace std;

int main() {

    int n;

    cout<<"Enter number of vertices: ";
    cin>>n;

    int cost[10][10];

    cout<<"Enter cost matrix:\n";

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];

    int visited[10]={0};

    visited[0]=1;

    int edges=0, mincost=0;

    while(edges<n-1) {

        int min=INT_MAX;
        int a=-1,b=-1;

        for(int i=0;i<n;i++) {

            if(visited[i]) {

                for(int j=0;j<n;j++) {

                    if(!visited[j] && cost[i][j]) {

                        if(cost[i][j]<min) {
                            min=cost[i][j];
                            a=i;
                            b=j;
                        }
                    }
                }
            }
        }

        cout<<a<<" - "<<b<<" = "<<min<<endl;

        visited[b]=1;

        mincost+=min;

        edges++;
    }

    cout<<"Minimum Cost = "<<mincost;

    return 0;
}