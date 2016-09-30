#include<stdio.h>

char info[100000];
int num, w1, w2;

int main() {
	w1 = w2 = 0;
	for (num = 1; ;num++) {
		scanf("%c", &info[num]);
		if (info[num] == 'W') w1++;
		if (info[num] == 'L') w2++;
		if (info[num] == 'E') {
			printf("%d:%d\n", w1, w2);
			break;
		}
		if ((w1 >= 11 || w2 >= 11) && (w1-w2 >= 2 || w2-w1 >= 2)) {
			printf("%d:%d\n", w1, w2);
			w1 = w2 = 0;
		}
		if (!num%20) scanf("%*c");
	}
	printf("\n");
	w1 = w2 = 0;
	for (int i = 1; i <= num; i++) {
		if (info[i] == 'W') w1++;
		if (info[i] == 'L') w2++;
		if (info[i] == 'E') {
			printf("%d:%d\n", w1, w2);
			break;
		}
		if ((w1 >= 21 || w2 >= 21) && (w1-w2 >= 2 || w2-w1 >= 2)) {
			printf("%d:%d\n", w1, w2);
			w1 = w2 = 0;
		}
	}
	return 0;
}
