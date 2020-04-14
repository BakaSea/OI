#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 50010
#define MAXL 21
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

inline int read() {
	int ch = getchar(), x = 0, f = 1;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}

struct Edge {
	int u, v, w, next;
	bool operator < (const Edge &A) const {
		return w > A.w;
	}
} e0[MAXN], e[MAXN*2];

int n, m, q, h[MAXN], par[MAXN][MAXL], f[MAXN], cnt, vis[MAXN], dep[MAXN], d[MAXN][MAXL];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void addEdge(int num, int u, int v, int w) {
	e[num].u = u;
	e[num].v = v;
	e[num].w = w;
	e[num].next = h[u];
	h[u] = num;
}

void dfs(int u, int depth) {
	vis[u] = 1;
	dep[u] = depth;
	for (int i = h[u]; i; i = e[i].next) {
		if (!vis[e[i].v]) {
			par[e[i].v][0] = u;
			d[e[i].v][0] = e[i].w;
			dfs(e[i].v, depth+1);
		}
	}
}

void init() {
	for (int k = 1; k < MAXL; ++k) {
		for (int i = 1; i <= n; ++i) {
			par[i][k] = par[par[i][k-1]][k-1];
			d[i][k] = min(d[i][k-1], d[par[i][k-1]][k-1]);
		}
	}
}

int lca(int u, int v) {
	int ans = 1e9;
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = MAXL-1; i >= 0; --i) {
		if (dep[par[u][i]] >= dep[v]) {
			ans = min(ans, d[u][i]);
			u = par[u][i];
		}
	}
	if (u == v) return ans;
	for (int i = MAXL-1; i >= 0; --i) {
		if (par[u][i] != par[v][i]) {
			ans = min(ans, d[u][i]);
			ans = min(ans, d[v][i]);
			u = par[u][i];
			v = par[v][i];
		}
	}
	ans = min(ans, d[u][0]);
	ans = min(ans, d[v][0]);
	return ans;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; ++i) {
		e0[i].u = read(), e0[i].v = read(), e0[i].w = read();
	}
	for (int i = 1; i <= n; ++i) f[i] = i;
	sort(e0+1, e0+m+1);
	for (int i = 1; i <= m; ++i) {
		if (find(e0[i].u) != find(e0[i].v)) {
			f[find(e0[i].u)] = find(e0[i].v);
			addEdge(++cnt, e0[i].u, e0[i].v, e0[i].w);
			addEdge(++cnt, e0[i].v, e0[i].u, e0[i].w);
		}
	}
	memset(d, 127, sizeof(d));
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i, 1);
		}
	}
	init();
	q = read();
	for (int i = 1, u, v; i <= q; ++i) {
		u = read(), v = read();
		if (find(u) != find(v)) printf("-1\n");
		else printf("%d\n", lca(u, v));
	}
	return 0;
}
