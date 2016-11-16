//kruskal------��³˹����
//���鼯����С������
#include<algorithm>
#include<string.h>
using namespace std;

struct Edge {
	int u, v, w;
} e[MAXM];

int par[MAXN], n, m;
//par: ��¼�����ڵļ��� 
//e: �� 
//n: ��ĸ���
//m: �ߵĸ��� 

//���鼯������ڵļ��� 
int find(int x) {
	return (par[x] != x) ? (par[x] = find(par[x])) : par[x];
}

int cmp(const Edge &a, const Edge &b) {
	return a.w < b.w;
}

//�㷨���� 
int kruskal() {
	//��ʼ�����鼯 
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
	}
	int tot = 0;
	//�����бߴ�С�������� 
	sort(e+1, e+m+1, cmp);
	//������ k 
	int k = 0;
	for (int i = 1; i <= m; ++i) {
		//u�����ڼ��� 
		int x = find(e[i].u);
		//v�����ڼ��� 
		int y = find(e[i].v); 
		//���u, v��δ���� 
		if (x != y) {
			//�ϲ�u, v���ڼ���=>�ѱ�(u, v)������С������ 
			par[x] = y;
			tot += e[i].w;
			k++;
			//���k=n-1, ��С�������Ѿ����� 
			if (k == n-1) break;
		}
	}
	return tot;
}
