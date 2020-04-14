#include <stdio.h>
#include <iostream>
#define MAXN 40010
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

int n, m, rt, h[MAXN], q[MAXN], vis[MAXN], par[MAXN];

void addEdge(int *head, Edge *edge, int num, int u, int v) {
	edge[num].u = u;
	edge[num].v = v;
	edge[num].next = head[u];
	head[u] = num;
}

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

void tarjan(int u) {
	vis[u] = 1;
	par[u] = u;
	for (int i = q[u]; i; i = eq[i].next) {
		if (vis[eq[i].v]) {
			eq[i].w = eq[i ^ 1].w = find(eq[i].v);
		}
	}
	for (int i = h[u]; i; i = e[i].next) {
		if (!vis[e[i].v]) {
			tarjan(e[i].v);
			par[e[i].v] = u;
		}
	}
}

int main() {
	n = read();
	for (int i = 1, u, v; i <= n; ++i) {
		u = read(), v = read();
		if (v == -1) rt = u;
		else {
			addEdge(h, e, i, u, v);
			addEdge(h, e, i+n, v, u);
		}
	}
	m = read();
	for (int i = 1, u, v; i <= m; ++i) {
		u = read(), v = read();
		addEdge(q, eq, i*2, u, v);
		addEdge(q, eq, i*2+1, v, u);
	}
	tarjan(rt);
	for (int i = 1; i <= m; ++i) {
		if (eq[i*2].w == eq[i*2].u) printf("1\n");
		else if (eq[i*2].w == eq[i*2].v) printf("2\n");
		else printf("0\n");
	}
	return 0;
}
