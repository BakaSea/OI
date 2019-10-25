#include<stdio.h>
#include<algorithm>
#include<math.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct Fountain {
	double l, r;
	bool operator < (const Fountain &A) const {
		if (l != A.l) return l < A.l;
		return r < A.r;
	}
} a[15010];

int n, L, W, T;

int main() {
	scanf("%d", &T);
	while (T--) {
		int tot = 0, cnt = 0;
		scanf("%d%d%d", &n, &L, &W);
		for (int i = 1, pos, radio; i <= n; ++i) {
			scanf("%d%d", &pos, &radio);
			if (radio < W*1.0/2) continue;
			cnt++;
			a[cnt].l = pos*1.0-sqrt(radio*radio*1.0-(W*1.0/2)*(W*1.0/2));
			a[cnt].r = pos*1.0+sqrt(radio*radio*1.0-(W*1.0/2)*(W*1.0/2));
		}
		a[cnt+1].l = L; a[cnt+1].r = L+1;
		sort(a+1, a+cnt+2);
		double p = 0, rm = 0;
		for (int i = 1; i <= cnt+1; ++i) {
			rm = max(rm, a[i-1].r);
			if (p < a[i].l) {
				if (i == 1) break;
				p = rm;
				if (p < a[i].l) break;
				tot++;
			}
		}
		if (!tot || p < L) printf("-1\n");
		else printf("%d\n", tot);
	}
	return 0;
}
