//stack------ջ 
//�Ƚ���� 
int stack[MAXN], top;
//stack: ջ
//top: ջ�� 

//push------��ջ 
void push(int x) {
	if (top == n) {
		//ջ�� 
		return;
	}
	s[++top] = x;
	return;
}

//pop------��ջ
void pop(int &x) {
	if (top == 0) {
		//ջ��
		return; 
	}
	x = s[top--];
	return;
}

//STL
#include<stack>
using namespace std;

stack<node> s;
//����  

bool ept = s.empty();
//�ж�ջ�Ƿ�Ϊ��

int size = s.size(); 
//ջ�Ĵ�С

node top = s.top();
//ջ�� 

s.pop();
//��ջ

s.push(x);
//��ջ

