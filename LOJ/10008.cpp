#include<stdio.h>
#include<algorithm>
using namespace std;

struct Homework {
	int t, w;
	bool operator < (const Homework &A) const {
		if (w != A.w) return w > A.w;
		return t < A.t; 
	}
} a[1000010];

int n, v[700010], tot, maxT;

int find(int x) {
	return v[x] == x ? x : v[x] = find(v[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].t, &a[i].w);
		maxT = maxT < a[i].t ? a[i].t : maxT;
	}
	for (int i = 1; i <= maxT; ++i) v[i] = i;
	sort(a+1, a+n+1);
	for (int i = 1, u; i <= n; ++i) {
		u = find(a[i].t);
		if (u) {
			v[u] = u-1;
			tot += a[i].w;
		}
	}
	printf("%d", tot);
	return 0;
}
