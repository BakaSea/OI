#include<stdio.h>

int n, m, a[100010], l, r;

int check(int x) {
	int k = 1;
	for (int i = 1, tot = 0; i <= n; ++i) {
		if (tot+a[i] > x) {
			k++;
			if (k > m) return 0;
			tot = a[i];
		} else tot += a[i];
	}
	return k <= m;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		l = l > a[i] ? l : a[i];
		r += a[i];
	}
	while (l < r) {
		int mid = (l+r) >> 1;
		if (check(mid)) r = mid;
		else l = mid+1;
	}
	printf("%d", r);
	return 0;
}
