#include<stdio.h>

int k[10001], m[10001], v, n, c, f[10001] = {0};

int main() {
	scanf("%d%d%d", &v, &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &k[i], &m[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = c; j >= 0; j--) {
			if (j >= m[i] && f[j-m[i]]+k[i] > f[j]){
				f[j] = f[j-m[i]]+k[i];
			}
		}
	}
	if (f[c] < v) {
		printf("Impossible");
		return 0;
	}
	for (int i = 0; i <= c; i++) {
		if (f[i] >= v) {
			printf("%d", c-i);
			return 0;
		}
	}
    return 0;
}
