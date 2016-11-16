//Dijkstra
//��Դ���·��
//���ܴ�����Ȩ
//ʱ�临�Ӷ�: O(n^2)
#include<string.h>
using namespace std;

int g[MAXN][MAXN], dis[MAXN], pre[MAXN];
bool book[MAXN];
//pre: ǰ���ڵ�

//s: ��� 
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

//���·�� 
void print(int x) {
	if (!pre[x]) return;
	print(pre[x]);
	printf("->%d", x);
	return;
}
