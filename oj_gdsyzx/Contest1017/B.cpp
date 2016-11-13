#include<stdio.h>
#include<queue>
#include<algorithm>
#define MAXN 400000+10
using namespace std;
 
struct node {
    int a, b;
	long long c;
     
    bool operator < (const node &A) const {
        return c > A.c;
    }
};
 
priority_queue<node> q;
long long a[MAXN], b[MAXN], c[MAXN];
int n;
 
int main() {
    while (!q.empty()) q.pop();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; ++i) {
        node temp;
        temp.a = i;
        temp.b = 1;
        temp.c = a[i]+b[1];
        q.push(temp);
    }
    for (int i = 1; i <= n; ++i) {
        node temp = q.top();
        q.pop();
        printf("%lld ", temp.c);
        temp.c = a[temp.a]+b[++temp.b];
        q.push(temp);
    }
    return 0;
}
