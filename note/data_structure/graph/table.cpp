//table------�ڽӱ�
//������
struct Edge {
	int u, v, w, next;
	//u: ������
	//v: �յ�
	//w: ��ֵ��
	//next: ��һ��u�����ıߵı�� 
} e[MAXM]; 

int head[MAXN] = {0};
//head[u]: u�������ĵ�һ���ߵıߺ�

//�ӱ�: ͷ���� 
//num: �ߵı�� 
void addEdge(int u, int v, int w, int num) {
	Edge temp;
	temp.u = u;
	temp.v = v;
	temp.w = w;
	temp.next = h[u];
	h[u] = num;
}

//���� 
void search(int u) {
	for (int i = h[u]; i; i = e[i].next) {
		//������u���������б� 
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
//����

//�ӱ� 
void addEdge(int u, int v, int w) {
	Edge temp;
	temp.u = u;
	temp.v = v;
	temp.w = w;
	e[u].push_back(temp);
}

//���� 
void search(int u) {
	for (int i = 1; i <= e[u].size(); ++i) {
		
	}
	return;
}
