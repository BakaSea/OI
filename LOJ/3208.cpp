#include<stdio.h>
#define ULL unsigned long long

ULL pow(ULL x) {
	if (!x) return 1;
	ULL y = pow(x/2);
	if (x%2) return y*y*2;
	return y*y;
}

ULL find(ULL n, ULL k) {
	if (n == 1) return k;
	ULL mid = pow(n-1);
	if (k >= mid) return mid+find(n-1, 2*mid-k-1);
	return find(n-1, k);
}

void print(ULL x, ULL n) {
	if (!n) return;
	print(x >> 1, n-1);
	printf("%d", x & 1);
}

int main() {
	ULL n, k;
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	scanf("%llu%llu", &n, &k);
	ULL ans = find(n, k);
	print(ans, n);
	return 0;
}
