#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

char map[401][401];
int cnt[51][51];

void draw(int x,int y) {
	map[x+2][y+0] = '+';
	map[x+3][y+0] = '-';
	map[x+4][y+0] = '-';
	map[x+5][y+0] = '-';
	map[x+6][y+0] = '+';
	map[x+1][y+1] = '/';
	map[x+2][y+1] = ' ';
	map[x+3][y+1] = ' ';
	map[x+4][y+1] = ' ';
	map[x+5][y+1] = '/';
	map[x+6][y+1] = '|';
	map[x+0][y+2] = '+';
	map[x+1][y+2] = '-';
	map[x+2][y+2] = '-';
	map[x+3][y+2] = '-';
	map[x+4][y+2] = '+';
	map[x+5][y+2] = ' ';
	map[x+6][y+2] = '|';
	map[x+0][y+3] = '|';
	map[x+1][y+3] = ' ';
	map[x+2][y+3] = ' ';
	map[x+3][y+3] = ' ';
	map[x+4][y+3] = '|';
	map[x+5][y+3] = ' ';
	map[x+6][y+3] = '+';
	map[x+0][y+4] = '|';
	map[x+1][y+4] = ' ';
	map[x+2][y+4] = ' ';
	map[x+3][y+4] = ' ';
	map[x+4][y+4] = '|';
	map[x+5][y+4] = '/';
	map[x+0][y+5] = '+';
	map[x+1][y+5] = '-';
	map[x+2][y+5] = '-';
	map[x+3][y+5] = '-';
	map[x+4][y+5] = '+';
}

int main() {
	int n,m;
	scanf("%d%d", &m, &n);
	int y = 0;
	int x = n*4+m*2+1;
	memset(map, '.', sizeof(map));
	for (int i = 1; i <= m; i++)
		for (int j = 1;j <= n;j++) {
    		scanf("%d", &cnt[i][j]);
    		y = max(y, (m-i+1)*2+cnt[i][j]*3+1);
    	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= cnt[i][j]; k++)
        		draw((j-1)*4+(m-i)*2+1, y-(3*k+(m-i+1)*2));
	for (int i = 1;i <= y;i++) {
		for (int j = 1;j <= x;j++)
			printf("%c", map[j][i]);
		printf("\n");
	}
	return 0;
}
