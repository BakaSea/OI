#include<stdio.h>
#include<cstdlib>
#define MAXN 30001
using namespace std;
 
int front[MAXN], behind[MAXN], par[MAXN];
 
int find(int x) {
    if (par[x] == x) return x;
    int k = find(par[x]);
    front[x] += front[par[x]];
    return par[x] = k;
}
 
int main() {
    int t;
    for (int i = 1; i < MAXN; ++i) {
        par[i] = i;
        behind[i] = 1;
    }
    scanf("%d%*c", &t);
    for (int i = 1, a, b; i <= t; ++i) {
        char c;
        scanf("%c%d%d%*c", &c, &a, &b);
        int x = find(a);
        int y = find(b);
        if (c == 'M') {
            par[x] = y;
            front[x] = behind[y];
            behind[y] += behind[x];
        } else {
            if (find(a) != find(b)) printf("-1\n");
            else printf("%d\n", abs(front[a]-front[b])-1);
        }
    }
    return 0;
}
