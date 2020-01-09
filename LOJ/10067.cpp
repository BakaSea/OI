#include<stdio.h>
#include<algorithm>
#define MAXN 100010
using namespace std;

struct Edge {
	int u, v;
	long long w;
	bool operator < (const Edge &A) const {
		return w < A.w;
	}
} e[MAXN];

int n, par[MAXN];
long long ans, sum[MAXN];

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
	sort(e+1, e+n);
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		sum[i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		int u = find(e[i].u), v = find(e[i].v);
		ans += (sum[u]*sum[v]-1)*(e[i].w+1)+e[i].w;
		par[u] = v;
		sum[v] += sum[u];
	}
	printf("%lld", ans);
	return 0;
}
