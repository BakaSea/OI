#include<stdio.h>
#define MAXN 1000010

struct Edge {
	int u, v, next;
} e[2*MAXN];

int n, m, r, a[MAXN], h[MAXN], vis[MAXN], idx[MAXN], cnt, last[MAXN];
long long w[MAXN];

void addEdge(int u, int v, int i) {
	e[i].u = u;
	e[i].v = v;
	e[i].next = h[u];
	h[u] = i;
}

void dfs(int u) {
	vis[u] = 1;
	idx[u] = ++cnt;
	for (int i = h[u]; i; i = e[i].next) {
		if (!vis[e[i].v]) {
			dfs(e[i].v);
		}
	}
	last[u] = cnt;
}

void modify(int i, int x) {
	for (; i <= n; i += -i&i) w[i] += x;
}

long long query(int i) {
	long long sum = 0;
	for (; i; i -= -i&i) sum += w[i];
	return sum;
}

int main() {
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1, x; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		addEdge(u, v, i);
		addEdge(v, u, i+n);
	}
	dfs(r);
	for (int i = 1; i <= n; ++i) modify(idx[i], a[i]);
	for (int i = 1, opt, a, x; i <= m; ++i) {
		scanf("%d%d", &opt, &a);
		if (opt == 1) {
			scanf("%d", &x);
			modify(idx[a], x);
		} else printf("%lld\n", query(last[a])-query(idx[a]-1));
	}
	return 0;
} 
