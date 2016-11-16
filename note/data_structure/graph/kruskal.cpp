//kruskal------克鲁斯卡尔
//并查集求最小生成树
#include<algorithm>
#include<string.h>
using namespace std;

struct Edge {
	int u, v, w;
} e[MAXM];

int par[MAXN], n, m;
//par: 记录点所在的集合 
//e: 边 
//n: 点的个数
//m: 边的个数 

//并查集求点所在的集合 
int find(int x) {
	return (par[x] != x) ? (par[x] = find(par[x])) : par[x];
}

int cmp(const Edge &a, const Edge &b) {
	return a.w < b.w;
}

//算法主体 
int kruskal() {
	//初始化并查集 
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
	}
	int tot = 0;
	//将所有边从小到大排序 
	sort(e+1, e+m+1, cmp);
	//计数器 k 
	int k = 0;
	for (int i = 1; i <= m; ++i) {
		//u点所在集合 
		int x = find(e[i].u);
		//v点所在集合 
		int y = find(e[i].v); 
		//如果u, v还未相连 
		if (x != y) {
			//合并u, v所在集合=>把边(u, v)加入最小生成树 
			par[x] = y;
			tot += e[i].w;
			k++;
			//如果k=n-1, 最小生成树已经生成 
			if (k == n-1) break;
		}
	}
	return tot;
}
