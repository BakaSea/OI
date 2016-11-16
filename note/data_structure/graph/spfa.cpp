//SPFA
//��Դ���·��
//���ܴ�����Ȩ
//ʱ�临�Ӷ�: O(kE), k��2
#include<queue>
#include<string.h>
using namespace std;

int g[MAXN][MAXN], dis[MAXN], pre[MAXN];
bool exist[MAXN];
//pre: ǰ���ڵ� 

//s: ��� 
void spfa(int s) {
	queue<int> q;
	while (!q.empty()) q.pop();
	memset(pre, 0, sizeof(pre));
	memset(dis, 127, sizeof(dis));
	memset(exist, 0, sizeof(exist));
	dis[s] = 0;
	exist[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		exist[u] = 0;
		for (int i = 1; i <= n; ++i) {
			if (dis[i] > dis[u]+g[u][i]) {
				dis[i] = dis[u]+g[u][i];
				pre[i] = u;
				if (!exist(i)) {
					q.push(i);
					exist[i] = 1;
				}
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
