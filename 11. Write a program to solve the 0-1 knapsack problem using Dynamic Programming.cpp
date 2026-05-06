#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    int n;

    cout<<"Enter number of items: ";
    cin>>n;

    int weight[n], profit[n];

    cout<<"Enter weights:\n";
    for(int i=0;i<n;i++)
        cin>>weight[i];

    cout<<"Enter profits:\n";
    for(int i=0;i<n;i++)
        cin>>profit[i];

    int W;

    cout<<"Enter capacity: ";
    cin>>W;

    int dp[n+1][W+1];

    for(int i=0;i<=n;i++) {

        for(int w=0;w<=W;w++) {

            if(i==0 || w==0)
                dp[i][w]=0;

            else if(weight[i-1]<=w)
                dp[i][w]=max(
                    profit[i-1]+dp[i-1][w-weight[i-1]],
                    dp[i-1][w]
                );

            else
                dp[i][w]=dp[i-1][w];
        }
    }

    cout<<"Maximum Profit = "<<dp[n][W];

    return 0;
}

output
Enter number of items: 3
Enter weights:
10 20 30
Enter profits:
60 100 120
Enter capacity: 50
Maximum Profit = 220
