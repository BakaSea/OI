#include<stdio.h>
#include<algorithm>
#include<string>
#define MAXN 100010
using namespace std;

inline int read() {
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = (x << 3)+(x << 1)+c-48, c = getchar();
	return x;
}

int n, m, x[MAXN];

int check(int d) {
	int k = 1, p = x[1]+d;
	for (int i = 2; i <= n; ++i) {
		if (x[i] < p) continue;
		k++;
		p = x[i]+d;
	}
	return k >= m;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) x[i] = read();
	sort(x+1, x+n+1);
	int l = 0, r = x[n]-x[1];
	while (l <= r) {
		int mid = (l+r) >> 1;
		if (check(mid)) l = mid+1;
		else r = mid-1;
	}
	printf("%d", r);
	return 0;
}
