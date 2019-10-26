#include<stdio.h>
#include<algorithm>
using namespace std;

struct Game {
	int t, w;
	bool operator < (const Game &A) const {
		if (w != A.w) return w > A.w;
		return t > A.t;
	}
} a[510];

int n, v[510], m;

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i].t);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i].w);
	sort(a+1, a+n+1);
	for (int i = 1, f; i <= n; ++i) {
		f = 0;
		for (int j = a[i].t; j; --j) {
			if (!v[j]) {
				v[j] = 1;
				f = 1;
				break;
			}
		}
		if (!f) m -= a[i].w;
	}
	printf("%d", m);
	return 0;
}
