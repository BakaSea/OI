#include<stdio.h>
#include<string.h>
#define MAXN 1001
using namespace std;

int g[MAXN][MAXN], mn[MAXN], w[MAXN], f[MAXN], n, m;

int findx(int x) {
	if (f[x] != x) f[x] = findx(f[x]);
	return f[x];
}

void tarjan(int u) {
	f[u] = u;
	for (int i = 1; i <= n; ++i) {
		if (f[i] && g[u][i] < 1e7) {
			g[u][i] = g[i][u] = g[i][u]*MAXN+findx(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!f[i] && g[u][i] == 1e7) {
			tarjan(i);
			f[i] = u;
		}
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(g, 1, sizeof(g));
		for (int i = 1, u, v, c; i <= m; ++i) {
			scanf("%d%d%d", &u, &v, &c);
			if (c < g[u][v]) {
				g[u][v] = g[v][u] = c;
			}
		}
		memcpy(w, g[1], sizeof(w));
		memcpy(mn, g[1], sizeof(mn));
		for (int i = 1; i <= n; ++i) f[i] = 1;
		f[1] = w[1] = 0;
		for (int i = 2, k; i <= n; ++i) {
			k = 0;
			for (int j = 2; j <= n; ++j) {
				if (f[j]) {
					if (mn[j] < mn[k]) k = j;
					else if (mn[j] == mn[k] && w[f[j]] < w[f[k]]) k = j;
				}
			}
			g[k][f[k]] = g[f[k]][k] = 1e7;
			f[k] = 0;
			for (int j = 2; j <= n; ++j) {
				if (f[j] && (g[k][j] < mn[j] || g[k][j] == mn[j] && w[k] < w[f[j]])) {
					mn[j] = g[k][j];
					w[j] = w[k]+g[k][j];
					f[j] = k;
				}
			}
		}
		tarjan(1);
		int ans = 1e7;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (g[i][j] < 1e7) {
					int temp = w[i]+w[j]-w[g[i][j]%MAXN]*2+g[i][j]/MAXN;
					if (temp < ans) ans = temp;
				}
			}
		}
		if (ans < 1e7) printf("%d\n", ans);
		else printf("No solution.\n");
	}
}
