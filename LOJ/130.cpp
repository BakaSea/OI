#include<stdio.h>

int n, q;
long long a[1000010];

void modify(int i, int x) {
	for (; i <= n; i += -i&i) a[i] += x;
}

long long query(int i) {
	long long sum = 0;
	for (; i; i -= -i&i) sum += a[i];
	return sum;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		modify(i, x);
	}
	for (int i = 1, opt, x, y; i <= q; ++i) {
		scanf("%d%d%d", &opt, &x, &y);
		if (opt == 1) modify(x, y);
		else printf("%lld\n", query(y)-query(x-1));
	}
	return 0;
}
