#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<int> a;
priority_queue<int, vector<int>, greater<int> > b;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		a.push(x);
		b.push(x);
	}
	while(a.size() > 1) {
		int x = a.top();
		a.pop();
		int y = a.top();
		a.pop();
		a.push(x*y+1);
		x = b.top();
		b.pop();
		y = b.top();
		b.pop();
		b.push(x*y+1);
	}
	printf("%d", b.top()-a.top());
	return 0;
}
