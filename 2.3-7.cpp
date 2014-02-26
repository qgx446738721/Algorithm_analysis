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
#include<set>
#include<climits>
#include<fstream>
#ifndef ONLINE_JUDGE
#define scanf scanf_s
#endif
using namespace std;
typedef long long LL;
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
const double EPS = 1e-8;
const int INF = 1 << 29;
const int MAX_N = 100005;
void Quick_Sort(int *arry, int l, int r){
	int key = arry[l];
	if (l>=r){
		return;
	}
	if (l == r - 1){
		if (arry[l] > arry[r]){
			arry[l] = arry[r];
			arry[r] = key;
		}
		return;
	}
	int i = l, j = r;
	while (i < j){
		while (i < j){
			if (arry[j] < key){
				arry[i] = arry[j];
				break;
			}
			j--;
		}
		while (i < j){
			if (arry[i]>key){
				arry[j] = arry[i];
			}
			i++;
		}
	}
	arry[i] = key;
	Quick_Sort(arry, l, i - 1);
	Quick_Sort(arry, i + 1, r);
}
int Find(int arry[], int x, int l, int r){
	while (l < r){
		if (l == r - 1){
			if (arry[l] == x){
				return l;
			}
			else if (arry[r] == x){
				return r;
			}
			return -1;
		}
		int mid = (l + r) >> 1;
		if (arry[mid] < x){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	if (arry[l] == x){
		return l;
	}
	return -1;
}
int main(){
	int N;
	int *arry;
	cout << "Please input the length of S" << endl;
	while (cin >> N){
		arry = new int[N];
		for (int i = 0; i < N; i++){
			cin >> arry[i];
		}
		Quick_Sort(arry, 0, N - 1);
		cout << "Please Inout the number X" << endl;
		int x, pos;
		cin >> x;
		for (int i = 0; i < N; i++){
			pos = Find(arry, x - arry[i], i + 1, N - 1);
			if (pos != -1){
				cout << arry[i] << ' ' << arry[pos] << endl;
			}
		}
		cout << "Please input the length of S" << endl;
	}
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}
