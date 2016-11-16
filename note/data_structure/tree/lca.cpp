//tarjan
//dfs+并查集求最近公共祖先(LCA)
struct Edge {
	int u, v, w, next;
} e[MAXM], q[MAXQ];
//e: 图的邻接表
//q: 询问的边
//q.w: 记录u, v的公共祖先

int he[MAXN], hq[MAXQ], par[MAXN];
//he: 图的边的头
//hq: 询问的边的头
//par: 点的并查集 

int find(int x) {
	return (par[x] != x) ? (par[x] = find(par[x])) : par[x];
}

void tarjan(int u) {
	p[u] = u;
	for (int i = hq[u]; i; i = q[i].next) {
		if (par[q[i].v]) q[i].w = find(q[i].v);
	}
	for (int i = he[u]; i; i = e[i].next) {
		if (!par[e[i].v]) {
			tarjan(e[i].v);
			par[e[i].v] = e[i].w;
		}
	}
}
