#include<stdio.h>
#include<math.h>
#define INF 2147483647
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int n, m, h[30], r[30], ans = INF, vmin[30], smin[30];

void dfs(int dep, int s, int v) {
	int rup = min(sqrt(n-v), r[dep+1]-1);
	if (dep == 1) {
		for (int i = rup; i >= dep; --i) {
			if (!((n-v)%(i*i)) && (n-v)/(i*i) < h[dep+1]) {
				if (dep == m) s = i*i;
				ans = min(ans, s+2*(n-v)/i);
			}
		}
		return;
	}
	for (int i = rup; i >= dep; --i) {
		int sup = min((n-v)/(i*i), h[dep+1]-1);
		if (dep == m) s = i*i;
		for (int j = sup; j >= dep; --j) {
			if (v+i*i*j+vmin[dep-1] <= n && s+i*j*2+smin[dep-1] < ans && 2*(n-v-i*i*j)/i+s < ans) {
				r[dep] = i;
				h[dep] = j;
				dfs(dep-1, s+i*j*2, v+i*i*j);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		vmin[i] = vmin[i-1]+i*i*i;
		smin[i] = smin[i-1]+2*i*i;
	}
	h[m+1] = r[m+1] = INF;
	dfs(m, 0, 0);
	if (ans != INF) printf("%d", ans);
	else printf("0");
	return 0;
}
