//Dijkstra
//求单源最短路径
//不能处理负边权
//时间复杂度: O(n^2)
#include<string.h>
using namespace std;

int g[MAXN][MAXN], dis[MAXN], pre[MAXN];
bool book[MAXN];
//pre: 前驱节点

//s: 起点 
void dijkstra(int s) {
	memset(dis, 0x7f, sizeof(dis));
	memset(book, 0, sizeof(book));
	dis[s] = pre[s] = 0;
	book[s] = 1;
	for (int i = 1, u; i <= n; ++i) {
		for (int j = 1, minn = 0x7fffffff; j <= n; ++j) {
			if (!book[j] && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (int j = 1; j <= n; ++j) {
			if (!book[u] && dis[u]+g[u][j] < dis[j]) {
				dis[j] = dis[u]+g[u][j];
				pre[j] = u;
			}
		}
	}
	return;
} 

//输出路径 
void print(int x) {
	if (!pre[x]) return;
	print(pre[x]);
	printf("->%d", x);
	return;
}
