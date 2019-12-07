#include<stdio.h>
#define MAXN 500010

struct Edge {
	int u, v, next;
} e[MAXN];

int n, h[MAXN], v[MAXN], id[MAXN], par[MAXN], top;
char c[MAXN], s[MAXN];
long long ans, k[MAXN], kk[MAXN];

void dfs(int u) {
	int f = 0;
	if (!top) {
		s[++top] = c[u];
		id[top] = u;
	} else if (s[top] == '(' && c[u] == ')') {
		kk[u] = kk[par[id[top]]]+1;
		k[u] += kk[u];
		f = id[top];
		top--;
	} else {
		s[++top] = c[u];
		id[top] = u;
	}
	for (int i = h[u]; i; i = e[i].next) {
		k[e[i].v] = k[u];
		dfs(e[i].v);
	}
	if (!f) top--;
	else {
		s[++top] = c[f];
		id[top] = f;
	}
}

int main() {
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	scanf("%d%s", &n, c+1);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &e[i].u);
		e[i].v = i;
		e[i].next = h[e[i].u];
		h[e[i].u] = i;
		par[e[i].v] = e[i].u;
	}
	dfs(1);
	ans = 1*k[1];
	for (int i = 2; i <= n; ++i) {
		ans ^= (long long)i*k[i];
	}
	printf("%lld", ans);
	return 0;
}
