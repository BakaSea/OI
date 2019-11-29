#include<stdio.h>
#include<string.h>
using namespace std;

int n, m, a[110], b[110];

void dfs(int step) {
	if (step > m) return;
	if (a[step] == n) {
		m = step;
		for (int i = 1; i <= step; ++i) b[i] = a[i];
		return;
	}
	for (int i = step; i; --i) {
		if (a[i]+a[step] <= n) {
			a[step+1] = a[i]+a[step];
			dfs(step+1);
		}
	}
}

int main() {
	while (~scanf("%d", &n) && n) {
		m = n;
		memset(a, 0, sizeof(a));
		a[1] = 1;
		dfs(1);
		for (int i = 1; i <= m; ++i) printf("%d ", b[i]);
		printf("\n");
	}
	return 0;
}
