#include <stdio.h>
#include <iostream>
#define MAXN 100010
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
} e[MAXN*2], eq[MAXN*2];

int n, Q, vis[MAXN], h[MAXN], q[MAXN], d[MAXN], par[MAXN];

void addEdge(int *head, Edge *edge, int num, int u, int v) {
	edge[num].u = u;
	edge[num].v = v;
	edge[num].next = head[u];
	head[u] = num;
}

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

void tarjan(int u, int dep) {
	vis[u] = 1;
	d[u] = dep;
	par[u] = u;
	for (int i = q[u]; i; i = eq[i].next) {
		if (vis[eq[i].v]) {
			eq[i].w = eq[i^1].w = d[u]+d[eq[i].v]-2*d[find(eq[i].v)];
		}
	}
	for (int i = h[u]; i; i = e[i].next) {
		if (!vis[e[i].v]) {
			tarjan(e[i].v, dep+1);
			par[e[i].v] = u;
		}
	}
}

int main() {
	n = read();
	for (int i = 1, u, v; i < n; ++i) {
		u = read(), v = read();
		addEdge(h, e, i, u, v);
		addEdge(h, e, i+n, v, u);
	}
	Q = read();
	for (int i = 1, u, v; i <= Q; ++i) {
		u = read(), v = read();
		addEdge(q, eq, i*2, u, v);
		addEdge(q, eq, i*2+1, v, u);
	}
	tarjan(1, 0);
	for (int i = 1; i <= Q; ++i) {
		printf("%d\n", eq[i*2].w);
	}
	return 0;
}
