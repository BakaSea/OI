#include<stdio.h>

int n, q;
long long a[1000010];

void modify(int i, int x) {
	for (; i <= n; i += -i&i) a[i] += x;
}

long long query(int i) {
	long long sum = 0;
	for (; i; i -= -i & i) sum += a[i];
	return sum;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		modify(i, x);
		modify(i+1, -x);
	}
	for (int i = 1, opt, x, y, z; i <= q; ++i) {
		scanf("%d%d", &opt, &x);
		if (opt == 1) {
			scanf("%d%d", &y, &z);
			modify(x, z);
			modify(y+1, -z);
		} else printf("%lld\n", query(x));
	}
	return 0;
}
