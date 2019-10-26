#include<stdio.h>

int n, m, cnt;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, xs = 0; i <= n; ++i) {
		scanf("%d", &x);
		if (xs+x > m) {
			xs = 0;
			cnt++;
		}
		xs += x;
	}
	printf("%d", cnt+1);
	return 0;
}
