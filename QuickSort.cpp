#include<iostream>
#include<cstdio>
using namespace std;
void QuickSort(int *A, int l, int r){
	if (l == r - 1){
		if (A[l] > A[r]) swap(A[l], A[r]);
		return;
	}
	if (l >= r) return;
	int key = A[l], L = l, R = r;
	while (l<r){
		while (key<=A[r] && l<r){
			r--;
		}
		A[l] = A[r];
		while (key>=A[l] && l<r){
			l++;
		}
		A[r] = A[l];
	}
	A[l] = key;
	QuickSort(A, L, l-1), QuickSort(A, l+1, R);
}
int main(){
	int n;
	while (cin >> n){
		int *A = new int[n];
		for (int i = 0; i < n; i++){
			cin >> A[i];
		}
		QuickSort(A, 0, n - 1);
		for (int i = 0; i < n; i++){
			printf("%s%d",(i==0)?"":" ", A[i]);
		}
		delete[] A;
		puts("");
	}
    return 0;
}
