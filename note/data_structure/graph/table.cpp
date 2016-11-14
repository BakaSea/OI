//table------邻接表
//点多边少
struct Edge {
	int u, v, w, next;
	//u: 出发点
	//v: 终点
	//w: 价值量
	//next: 下一条u所连的边的编号 
} e[MAXM]; 

int head[MAXN] = {0};
//head[u]: u点所连的第一条边的边号

//加边: 头插入 
//num: 边的编号 
void addEdge(int u, int v, int w, int num) {
	Edge temp;
	temp.u = u;
	temp.v = v;
	temp.w = w;
	temp.next = h[u];
	h[u] = num;
}

//遍历 
void search(int u) {
	for (int i = h[u]; i; i = e[i].next) {
		//遍历与u相连的所有边 
	}
	return;
}

//STL
#include<vector>
using namespace std;

struct Edge {
	int u, v, w;
};

vector<Edge> e[MAXN];
//声明

//加边 
void addEdge(int u, int v, int w) {
	Edge temp;
	temp.u = u;
	temp.v = v;
	temp.w = w;
	e[u].push_back(temp);
}

//遍历 
void search(int u) {
	for (int i = 1; i <= e[u].size(); ++i) {
		
	}
	return;
}
