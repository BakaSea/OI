#include<stdio.h>
#define MAXN 100010
#define INF 2147483647
#define EPS 1e-6
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, L, l, r = -INF, a[MAXN];
long long sum[MAXN], b[MAXN];

int main() {
	scanf("%d%d", &n, &L);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] *= 1000;
		r = max(r, a[i]);
	}
	while (l <= r) {
		int mid = (l+r) >> 1;
		long long x = -INF, ms = INF;
		for (int i = 1; i <= n; ++i) b[i] = a[i]-mid;
		for (int i = 1; i <= n; ++i) sum[i] = sum[i-1]+b[i];
		for (int i = L; i <= n; ++i) {
			ms = min(ms, sum[i-L]);
			x = max(x, sum[i]-ms);
		}
		if (x >= 0) l = mid+1;
		else r = mid-1;
	}
	printf("%d", r);
	return 0;
}
