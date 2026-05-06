#include <iostream>
using namespace std;

void countSort(int arr[], int n) {

    int max = arr[0];

    for(int i=1;i<n;i++)
        if(arr[i]>max)
            max=arr[i];

    int count[max+1]={0};

    for(int i=0;i<n;i++)
        count[arr[i]]++;

    int index=0;

    for(int i=0;i<=max;i++) {
        while(count[i]--) {
            arr[index++]=i;
        }
    }
}

int main() {

    int n;

    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    countSort(arr,n);

    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}