//Prim
//���׵�����С������
#include<string.h>
using namespace std;

int g[MAXN][MAXN], minn[MAXN];
bool book[MAXN];
//book: ���Ϊ���㻹�ǰ׵�
//minn: ��С��Ȩֵ 

int prim(int u) {
	int MST = 0;
	memset(minn, 127, sizeof(minn));
	minn[u] = 0;
	memset(book, 0, sizeof(book));
	for (int i = 1, v; i <= n; ++i) {
		v = 0;
		//Ѱ��minn[v]��С����v 
		for (int j = 1, mv = 2e7; i <= n; ++i) {
			if (!book[j] && mv > minn[j]) {
				v = j;
				mv = minn[j];
			}
		}
		//��v���Ϊ�׵� 
		book[v] = 1;
		MST += minn[v];
		//�޸��ڰ׵�v����������������Сֵ 
		for (int j = 1; j <= n; ++j) {
			if (g[v][j] < minn[j]) {
				minn[j] = g[v][j];
			}
		}
	}
	return MST;
}
