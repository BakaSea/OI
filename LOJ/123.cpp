#include<stdio.h>
#include<algorithm>
using namespace std;

struct Edge{
	
	int u, v, w;
	
	bool operator < (const Edge &A) const {
		return w < A.w;
	}
	
} e[500010];

int n, m, par[200010];
long long tot;

int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) par[i] = i;
	for (int i = 1; i <= m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	sort(e+1, e+m+1);
	for (int i = 1, k = 0; i <= m; ++i) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u != v) {
			par[u] = v;
			tot += e[i].w;
			k++;
		}
		if (k == n-1) break;
	}
	printf("%lld\n", tot);
	return 0;
}
