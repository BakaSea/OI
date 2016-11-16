//Floyed-Warshall------弗洛伊德
//求多源最短路径
//适用于出现负边权
//时间复杂度: O(n^3)
#include<string.h>
using namespace std;

int g[MAXN][MAXN], dis[MAXN][MAXN], pre[MAXN][MAXN];
//pre: 前驱节点 

void floyed() {
	memset(pre, 0, sizeof(pre));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			pre[i][j] = i;
			pre[j][i] = j;
		}
	}
	memcpy(dis, g, sizeof(g));
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dis[i][j] > dis[i][k]+dis[k][j]) {
					dis[i][j] = dis[i][k]+dis[k][j];
					pre[i][j] = pre[k][j];
				}
			}
		}
	}
	return;
}

//输出路径 
//s: 起点 
void print(int s, int x) {
	if (!pre[s][x]) return;
	print(s, pre[s][x]);
	printf("->%d", x);
	return;
}
