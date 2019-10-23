#include<stdio.h>
#include<string.h>
#define MAXN 100010
#define INTMIN -2147483647
using namespace std;

int T, n, sum[MAXN], res, l, r;

int main() {
	scanf("%d", &T);
	for (int p = 1; p <= T; ++p) {
		memset(sum, 0, sizeof(sum));
		l = r = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &sum[i]);
		res = sum[1];
		for (int i = 2, index = 1; i <= n; ++i) {
			if (sum[i-1] >= 0) sum[i] += sum[i-1];
			else index = i;
			if (sum[i] > res) {
				res = sum[i];
				l = index;
				r = i;
			}
		}
		printf("Case %d:\n%d %d %d\n", p, res, l, r);
		if (p < T) printf("\n");
	}
	return 0;
}
