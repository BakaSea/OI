//queue------����
//�Ƚ��ȳ�
int q[MAXN], head, tail;
//q: ����
//head: ��ͷ
//tail: ��β

//push------��� 
void push(int x) {
	if (tail == MAXN-1) {
		//����
		return; 
	}
	q[++tail] = x;
	return;
}

//pop------����
void pop(int &x) {
	if (head > tail) {
		//�ӿ�
		return; 
	}
	x = q[head++];
	return;
}

//STL
#include<queue>
using namespace std;

queue<node> q;
//����

node head = q.front();
//��ͷ

bool ept = q.empty();
//�ж϶��Ƿ�Ϊ��

int size = q.size();
//�ӵĳ��� 

q.push(x);
//���

q.pop();
//����
 
