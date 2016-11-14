//priority_queue------优先队列
//堆，元素在队中顺序存储 

//STL
#include<queue>
using namespace std;

priority_queue<node> q;
//声明

node top = q.top();
//队头

int size = q.size();
//队的大小

bool ept = q.empty();
//判断队是否为空

q.push(x);
//入队

q.pop();
//出队 
