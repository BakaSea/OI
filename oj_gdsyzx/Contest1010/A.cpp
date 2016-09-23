#include<stdio.h>
#include<queue>
#define MAX 200000
using namespace std;
 
int n, k, line[MAX] = {0};
 
void bfs() {
    line[n] = 1;
    queue<int> q;
    while (!q.empty()) q.pop();
    q.push(n);
    while (!q.empty()) {
        int x = q.front();
        int xx = x+1;
        if (xx <= MAX && !line[xx]) {
            line[xx] = line[x]+1;
            q.push(xx);
        }
        xx = x-1;
        if (xx >= 0 && !line[xx]) {
            line[xx] = line[x]+1;
            q.push(xx);
        }
        xx = x*2;
        if (xx <= MAX && !line[xx]) {
            line[xx] = line[x]+1;
            q.push(xx);
        }
        //if (xx == k) return;
        q.pop();
    }
}
 
int main() {
    scanf("%d%d", &n, &k);
    bfs();
    printf("%d", line[k]-1);
    return 0;
}
