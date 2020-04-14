#include <stdio.h>
#include <ctype.h>
#define MAXN 50010
#define MAXL 21
#define max(a, b) ((a) > (b) ? (a) : (b))

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}

int n, m, a[MAXN], f[MAXN][MAXL], LOG[MAXN];

void preInit() {
	LOG[1] = 0, LOG[2] = 1;
	for (int i = 3; i < MAXN; ++i) LOG[i] = LOG[i/2]+1;
}

void init() {
	for (int k = 1; k < MAXL; ++k) {
		for (int i = 1; i+(1 << k)-1 <= n; ++i) {
			f[i][k] = max(f[i][k-1], f[i+(1 << (k-1))][k-1]);
		}
	}
}

int query(int l, int r) {
	int k = LOG[r-l+1];
	return max(f[l][k], f[r-(1 << k)+1][k]);
}

int find(int x) {
	if (x < a[1]) return -1;
	if (x > a[n]) return -2;
	int l = 1, r = n;
	while (l < r) {
		int mid = (l+r) >> 1;
		if (x <= a[mid]) r = mid;
		else l = mid+1;
	}
	return r;
}

int main() {
	preInit();
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		f[i][0] = read();
	}
	init();
	m = read();
	for (int i = 1; i <= m; ++i) {
		int l = read(), r = read();
		int ll = find(l), rr = find(r);
		if ((ll < 0 || a[ll] != l) && (rr < 0 || a[rr] != r)) printf("maybe\n");
		else if (ll == -1 || a[ll] != l) {
			if (ll == -1) ll = 1;
			int q = f[rr][0];
			rr--;
			if (ll > rr) printf("maybe\n");
			else {
				int k = query(ll, rr);
				if (k >= q) printf("false\n");
				else printf("maybe\n");
			}
		} else if (rr == -2 || a[rr] != r) {
			if (rr == -2) rr = n;
			else rr--;
			int q = f[ll][0];
			ll++;
			if (ll > rr) printf("maybe\n");
			else {
				int k = query(ll, rr);
				if (k >= q) printf("false\n");
				else printf("maybe\n");
			}
		} else {
			if (f[ll][0] < f[rr][0]) printf("false\n");
			else if (l+1 == r) printf("true\n");
			else {
				int q = f[rr][0];
				ll++, rr--;
				if (ll > rr) printf("maybe\n");
				else {
					int k = query(ll, rr);
					if (k >= q) printf("false\n");
					else {
						if (rr-ll+2 == r-l) printf("true\n");
						else printf("maybe\n");
					}
				}
				
			}
		}
	}
	return 0;
}
