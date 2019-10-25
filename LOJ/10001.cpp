#include<stdio.h>
#include<algorithm>
using namespace std;

struct Quest {
	int b, e, t;
	bool operator < (const Quest &A) const {
		return e < A.e;
	}
} q[5010];

int n, h, a[30010], tot;

int main() {
	scanf("%d%d", &n, &h);
	for (int i = 1; i <= h; ++i) scanf("%d%d%d", &q[i].b, &q[i].e, &q[i].t);
	sort(q+1, q+h+1);
	for (int i = 1, k; i <= h; ++i) {
		k = 0;
		for (int j = q[i].b; j <= q[i].e; ++j) {
			if (a[j]) k++;
			if (k == q[i].t) break;
		}
		if (k < q[i].t) {
			for (int j = q[i].e; j >= q[i].b; --j) {
				if (!a[j]) {
					a[j] = 1;
					k++;
					tot++;
					if (k == q[i].t) break;
				}
			}
		}
	}
	printf("%d", tot);
	return 0;
}
