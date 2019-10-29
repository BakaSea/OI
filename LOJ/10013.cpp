#include<stdio.h>
#define MAXN 10010
#define eps 1e-8
#define max(a, b) ((a) > (b) ? (a) : (b))

int T, n, a[MAXN], b[MAXN], c[MAXN];

double cal(double x) {
	double k = -2147483647;
	for (int i = 1; i <= n; ++i) k = max(k, a[i]*1.0*x*x+b[i]*1.0*x+c[i]*1.0);
	return k;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d%d%d", &a[i], &b[i], &c[i]);
		double l = 0, r = 1000;
		while (r-l > eps) {
			double lmid = l+(r-l)/3, rmid = r-(r-l)/3;
			if (cal(lmid) < cal(rmid)) r = rmid;
			else l = lmid;
		}
		printf("%.4lf\n", cal(r));
	}
	return 0;
}
