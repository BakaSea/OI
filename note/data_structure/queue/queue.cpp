//queue------队列
//先进先出
int q[MAXN], head, tail;
//q: 队列
//head: 队头
//tail: 队尾

//push------入队 
void push(int x) {
	if (tail == MAXN-1) {
		//队满
		return; 
	}
	q[++tail] = x;
	return;
}

//pop------出队
void pop(int &x) {
	if (head > tail) {
		//队空
		return; 
	}
	x = q[head++];
	return;
}

//STL
#include<queue>
using namespace std;

queue<node> q;
//声明

node head = q.front();
//队头

bool ept = q.empty();
//判断队是否为空

int size = q.size();
//队的长度 

q.push(x);
//入队

q.pop();
//出队
 
