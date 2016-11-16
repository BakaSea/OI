//tarjan
//dfs+���鼯�������������(LCA)
struct Edge {
	int u, v, w, next;
} e[MAXM], q[MAXQ];
//e: ͼ���ڽӱ�
//q: ѯ�ʵı�
//q.w: ��¼u, v�Ĺ�������

int he[MAXN], hq[MAXQ], par[MAXN];
//he: ͼ�ıߵ�ͷ
//hq: ѯ�ʵıߵ�ͷ
//par: ��Ĳ��鼯 

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
