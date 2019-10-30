#include<stdio.h>
#include<math.h>
using namespace std;

int n, par[60], x[60], y[60];

int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

int check(int t) {
	for (int i = 1; i <= n; ++i) par[i] = i;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if ((abs(x[i]-x[j])+abs(y[i]-y[j])+1)/2 <= t) par[find(i)] = find(j);
		}
	}
	for (int i = 1, u = find(1); i <= n; ++i) {
		int v = find(i);
		if (u != v) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
	int l = 0, r = 2147483647;
	while (l < r) {
		int mid = (l+r) >> 1;
		if (check(mid)) r = mid;
		else l = mid+1;
	}
	printf("%d", r);
	return 0;
}
