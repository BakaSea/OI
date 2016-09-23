#include<stdio.h>
#include<iostream>
using namespace std;

int v[25], w[25], n, m, f[25][30003] = {0};

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &v[i], &w[i]);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = f[i-1][j];
			if (j >= v[i]) f[i][j] = max(f[i-1][j], f[i-1][j-v[i]]+w[i]*v[i]);
		}
	}
	printf("%d", f[m][n]);
    return 0;
}
