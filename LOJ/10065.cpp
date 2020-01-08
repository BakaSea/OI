#include<stdio.h>
#include<math.h>
#include<algorithm>
#define MAXN 510
#define MAXM MAXN*MAXN
using namespace std;

struct Edge {
	int u, v, next;
	double w;
	bool operator < (const Edge &A) const {
		return w < A.w;
	}
} e[MAXM];

int n, k, x[MAXN], y[MAXN], h[MAXN], par[MAXN], m, cnt;
double ans[MAXM];

double dist(int x1, int y1, int x2, int y2) {
	return sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2));
}

void addEdge(int u, int v, double w, int num) {
	e[num].u = u;
	e[num].v = v;
	e[num].w = w;
	e[num].next = h[u];
	h[u] = num;
}

int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			addEdge(i, j, dist(x[i], y[i], x[j], y[j]), ++m);
			addEdge(j, i, dist(x[i], y[i], x[j], y[j]), ++m);
		}
	}
	for (int i = 1; i <= n; ++i) par[i] = i;
	sort(e+1, e+m+1);
	for (int i = 1; i <= m; ++i) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u != v) {
			par[u] = v;
			ans[++cnt] = e[i].w;
			if (cnt == n-1) break;
		}
	}
	if (cnt == n-1) printf("%.2lf", ans[cnt-k+1]);
	else printf("0.00");
	return 0;
}
