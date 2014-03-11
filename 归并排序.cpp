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
#pragma comment(linker, "/STACK:102400000,102400000")
#ifndef ONLINE_JUDGE
#define scanf scanf_s
#endif
using namespace std;
typedef long long LL;
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
const double EPS = 1e-8;
const int mod = 1000000007;
const int INF = 1 << 29;
const int MAX_N = 40005;
void Sort(int *A, int l, int r){
	if (r - l + 1 <= 2){
		if (A[l] > A[r]){
			int tmp2 = A[l];
			A[l] = A[r];
			A[r] = tmp2;
		}
		return;
	}
	int mid = (l + r) >> 1;
	Sort(A, l, mid), Sort(A, mid + 1, r);
	int *tmp = new int[r - l + 1];
	int i = l, j = mid + 1;
	int cnt = 0;
	while (i <= mid || j <= r){
		if (i == mid + 1){
			tmp[cnt++] = A[j++];
		}
		else if (j == r + 1){
			tmp[cnt++] = A[i++];
		}
		else{
			if (A[i] > A[j]){
				tmp[cnt++] = A[j++];
			}
			else{
				tmp[cnt++] = A[i++];
			}
		}
	}
	for (i = l, j = 0; i <= r; i++, j++){
		A[i] = tmp[j];
	}
	delete[] tmp;
}
int main(){
	int n;
	while (cin >> n){
		int *A = new int[n];
		for (int i = 0; i < n; i++){
			cin >> A[i];
		}
		Sort(A, 0, n - 1);
		for (int i = 0; i < n; i++){
			cout << A[i] << ' ';
		}
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}