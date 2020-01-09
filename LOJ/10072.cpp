#include<stdio.h>
#include<string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define INF 2147483647
using namespace std;

int n, m, d[110][110], g[110][110], pos[110][110], path[110], cnt, ans = INF;

void getPath(int x, int y) {
	if (!pos[x][y]) return;
	getPath(x, pos[x][y]);
	path[++cnt] = pos[x][y];
	getPath(pos[x][y], y);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			g[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; ++i) g[i][i] = 0;
	for (int i = 1, x, y, z; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		g[x][y] = g[y][x] = min(g[x][y], z);
	}
	memcpy(d, g, sizeof(g));
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i < k; ++i) {
			for (int j = i+1; j < k; ++j) {
				if ((long long)d[i][j]+g[j][k]+g[k][i] < ans) {
					ans = d[i][j]+g[j][k]+g[k][i];
					cnt = 0;
					path[++cnt] = i;
					getPath(i, j);
					path[++cnt] = j;
					path[++cnt] = k;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k]+d[k][j]) {
					d[i][j] = d[i][k]+d[k][j];
					pos[i][j] = k;
				}
			}
		}
	}
	if (ans == INF) printf("No solution.");
	else for (int i = 1; i <= cnt; ++i) printf("%d ", path[i]);
	return 0;
}
