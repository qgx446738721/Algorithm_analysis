#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<ctime>
#include<climits>
#include<fstream>
using namespace std;
typedef long long LL;
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
const double EPS = 1e-8;
const int INF = 1 << 29;
const int MAX_N = 1010;
void InsertSort(int *A,int n){
    int key = A[n];
    if(n!=1){
        InsertSort(A, n-1);
    }
    int i;
    for (i=n-1; i>=0; i--) {
        if (A[i]>key) {
            A[i+1]=A[i];
        }
        else{
            break;
        }
    }
    A[i+1]=key;
}
int main(){
    int arry[10];
    while (true) {
        for (int i=0; i<10; i++) {
            cin>>arry[i];
        }
        InsertSort(arry, 9);
        for (int i=0; i<10; i++) {
            cout<<arry[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
