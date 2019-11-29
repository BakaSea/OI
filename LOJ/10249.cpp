#include<stdio.h>
#include<algorithm>
using namespace std;

int n, m, v[510], a[2010], b[1010];

int dfs(int k, int l, int r, int sl, int sr) {
	if (l == r) {
		if(a[2*n]-sl-sr < 1 || a[2*n]-sl-sr > 500 || !v[a[2*n]-sl-sr]) return 0;
		b[l] = a[2*n]-sl-sr;
		for (int i = 1; i <= n; ++i) printf("%d ", b[i]);
		return 1;
	}
	if (1 <= a[k]-sl && a[k]-sl <= 500 && v[a[k]-sl]) {
		b[l] = a[k]-sl;
		if (dfs(k+1, l+1, r, a[k], sr)) return 1;
	}
	if (1 <= a[k]-sr && a[k]-sr <= 500 && v[a[k]-sr]) {
		b[r] = a[k]-sr;
		if (dfs(k+1, l, r-1, sl, a[k])) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2*n; ++i) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1, x; i <= m; ++i) {
		scanf("%d", &x);
		v[x] = 1;
	}
	sort(a+1, a+2*n+1);
	dfs(1, 1, n, 0, 0);
	return 0;
}
