#include<stdio.h>
#include<iostream>
using namespace std;

int n, turn, stu[101][3], tmx;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &stu[i][0]);
		stu[i][1] = stu[i][2] = 1;
	}
	tmx = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i-1; j >= 1; j--) {
			if (stu[j][0] < stu[i][0]) {
				stu[i][1] = max(stu[j][1]+1, stu[i][1]);
			}
		}
	}
	for (int i = n-1; i >= 1; i--) {
		for (int j = i+1; j <= n; j++) {
			if (stu[j][0] < stu[i][0]) {
				stu[i][2] = max(stu[j][2]+1, stu[i][2]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		tmx = max(stu[i][1]+stu[i][2]-1, tmx);
	}
	printf("%d", n-tmx);
    return 0;
}
