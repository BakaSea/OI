#include<stdio.h>
#define MOD 998244353

int n, m, f[4000010];
long long res;

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1, u, v, opt; i <= m; ++i) {
		scanf("%d%d%d", &opt, &u, &v);
		if (opt) {
			if (find(u) == find(v)) res = (res*2+1)%MOD;
			else res = res*2%MOD;
		} else f[u] = v;
	}
	printf("%lld", res);
	return 0;
}
