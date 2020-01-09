#include<stdio.h>

int n, g[310][310], d[310], v[310];

int prim() {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) d[i] = 2147483647;
	for (int i = 0, k; i <= n; ++i) {
		int minn = 2147483647;
		for (int j = 0; j <= n; ++j) {
			if (!v[j] && minn > d[j]) {
				minn = d[j];
				k = j;
			}
		}
		v[k] = 1;
		cnt += d[k];
		for (int j = 0; j <= n; ++j) {
			if (!v[j] && d[j] > g[k][j]) {
				d[j] = g[k][j];
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		g[0][i] = g[i][0] = x;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &g[i][j]);
		}
	}
	printf("%d", prim());
	return 0;
}
