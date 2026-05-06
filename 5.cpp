#include <iostream>
using namespace std;

void add(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j]=A[i][j]+B[i][j];
}

void subtract(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j]=A[i][j]-B[i][j];
}

void strassen(int A[2][2], int B[2][2], int C[2][2]) {

    int P1[2][2], P2[2][2], P3[2][2], P4[2][2];
    int P5[2][2], P6[2][2], P7[2][2];

    P1[0][0]=(A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
    P2[0][0]=(A[1][0]+A[1][1])*B[0][0];
    P3[0][0]=A[0][0]*(B[0][1]-B[1][1]);
    P4[0][0]=A[1][1]*(B[1][0]-B[0][0]);
    P5[0][0]=(A[0][0]+A[0][1])*B[1][1];
    P6[0][0]=(A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
    P7[0][0]=(A[0][1]-A[1][1])*(B[1][0]+B[1][1]);

    C[0][0]=P1[0][0]+P4[0][0]-P5[0][0]+P7[0][0];
    C[0][1]=P3[0][0]+P5[0][0];
    C[1][0]=P2[0][0]+P4[0][0];
    C[1][1]=P1[0][0]-P2[0][0]+P3[0][0]+P6[0][0];
}

int main() {

    int A[2][2], B[2][2], C[2][2];

    cout<<"Enter Matrix A:\n";
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin>>A[i][j];

    cout<<"Enter Matrix B:\n";
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin>>B[i][j];

    strassen(A,B,C);

    cout<<"Result Matrix:\n";
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}