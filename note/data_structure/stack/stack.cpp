//stack------栈 
//先进后出 
int stack[MAXN], top;
//stack: 栈
//top: 栈顶 

//push------进栈 
void push(int x) {
	if (top == n) {
		//栈满 
		return;
	}
	s[++top] = x;
	return;
}

//pop------出栈
void pop(int &x) {
	if (top == 0) {
		//栈空
		return; 
	}
	x = s[top--];
	return;
}

//STL
#include<stack>
using namespace std;

stack<node> s;
//声明  

bool ept = s.empty();
//判断栈是否为空

int size = s.size(); 
//栈的大小

node top = s.top();
//栈顶 

s.pop();
//出栈

s.push(x);
//进栈

