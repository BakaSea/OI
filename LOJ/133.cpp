#include<stdio.h>

int n, m, opt, a, b, c, d;
long long t[5000][5000];

void modify(int x, int y, int d) {
	for (int i = x; i <= n; i += -i&i) {
		for (int j = y; j <= m; j += -j&j) {
			t[i][j] += d;
		}
	}
}

long long query(int x, int y) {
	long long sum = 0;
	for (int i = x; i; i -= -i&i) {
		for (int j = y; j; j -= -j&j) {
			sum += t[i][j];
		}
	}
	return sum;
}

int main() {
	scanf("%d%d", &n, &m);
	while (scanf("%d%d%d%d", &opt, &a, &b, &c) != EOF) {
		if (opt == 1) modify(a, b, c);
		else {
			scanf("%d", &d);
			printf("%lld\n", query(c, d)-query(a-1, d)-query(c, b-1)+query(a-1, b-1));
		}
	}
	return 0;
}
