#include<stdio.h>

int n, k, tot;

void dfs(int step, int pre, int sum) {
	if (step == k) {
		if (n-sum >= pre) tot++;
		return;
	}
	for (int i = pre; i <= (n-sum)/(k-step+1); ++i) dfs(step+1, i, sum+i);
}

int main() {
	scanf("%d%d", &n, &k);
	dfs(1, 1, 0);
	printf("%d", tot);
	return 0;
}
