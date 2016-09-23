#include<stdio.h>
#define MAX 2147483640

int n, a[10001], f[10001][2], tmx;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		f[i][1] = 0;
		f[i][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] < a[j] && f[j][0]+1 > f[i][1]) {
				f[i][1] = f[j][0]+1;
			}
			if (a[i] > a[j] && f[j][1]+1 > f[i][0]) {
				f[i][0] = f[j][1]+1;
			}
		}
	}
	tmx = 0;
	for (int i = 1; i <= n; i++) {
		if (tmx < f[i][0]) tmx = f[i][0];
		if (tmx < f[i][1]) tmx = f[i][1];
	}
	printf("%d", tmx);
    return 0;
}
