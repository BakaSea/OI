#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAXN 510
#define MAXM 10010
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

struct Edge {
	int u, v, next, is;
	long long w;
	bool operator < (const Edge &A) const {
		return w < A.w;
	}
} e[MAXM], g[2*MAXM];

int n, m, par[MAXN], h[MAXN], vis[MAXN];
long long cnt, maxe[MAXN][MAXN], ans = (long long)1 << 62;

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

void addEdge(int u, int v, long long w, int num) {
	g[num].u = u;
	g[num].v = v;
	g[num].w = w;
	g[num].next = h[u];
	h[u] = num;
}

int dfs(int u, int v, int cur, long long w) {
	vis[cur] = 1;
	if (cur == v) {
		maxe[u][v] = maxe[v][u] = w;
		return 1;
	}
	for (int i = h[cur]; i; i = g[i].next) {
		if (!vis[g[i].v] && dfs(u, v, g[i].v, max(w, g[i].w))) return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
	for (int i = 1; i <= n; ++i) par[i] = i;
	sort(e+1, e+m+1);
	for (int i = 1, k = 0; i <= m; ++i) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u != v) {
			k++;
			cnt += e[i].w;
			e[i].is = 1;
			par[u] = v;
			addEdge(e[i].u, e[i].v, e[i].w, k);
			addEdge(e[i].v, e[i].u, e[i].w, k+n);
			if (k == n-1) break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			memset(vis, 0, sizeof(vis));
			dfs(i, j, i, 0);
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (!e[i].is && e[i].w != maxe[e[i].u][e[i].v]) {
			ans = min(ans, cnt+e[i].w-maxe[e[i].u][e[i].v]);
		}
	}
	printf("%lld", ans);
	return 0;
}
