#include<stdio.h>

int n, t, mi[2001][2], tmx;

int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &mi[i][0]);
		mi[i][1] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i-1; j++) {
			int k = (mi[j][1]-1)%(2*t);
			if (k < t && mi[i][0] < mi[j][0] && mi[j][1]+1 > mi[i][1]) {
				mi[i][1] = mi[j][1]+1;
			}
			if (k >= t && mi[i][0] > mi[j][0] && mi[j][1]+1 > mi[i][1]) {
				mi[i][1] = mi[j][1]+1;
			}
		}
	}
	tmx = 0;
	for (int i = 1; i <= n; i++) {
		if (tmx < mi[i][1]) tmx = mi[i][1];
	}
	printf("%d", tmx);
    return 0;
}
