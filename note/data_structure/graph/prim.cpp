//Prim
//蓝白点求最小生成树
#include<string.h>
using namespace std;

int g[MAXN][MAXN], minn[MAXN];
bool book[MAXN];
//book: 标记为蓝点还是白点
//minn: 最小边权值 

int prim(int u) {
	int MST = 0;
	memset(minn, 127, sizeof(minn));
	minn[u] = 0;
	memset(book, 0, sizeof(book));
	for (int i = 1, v; i <= n; ++i) {
		v = 0;
		//寻找minn[v]最小蓝点v 
		for (int j = 1, mv = 2e7; i <= n; ++i) {
			if (!book[j] && mv > minn[j]) {
				v = j;
				mv = minn[j];
			}
		}
		//将v标记为白点 
		book[v] = 1;
		MST += minn[v];
		//修改于白点v相连的所有蓝点最小值 
		for (int j = 1; j <= n; ++j) {
			if (g[v][j] < minn[j]) {
				minn[j] = g[v][j];
			}
		}
	}
	return MST;
}
