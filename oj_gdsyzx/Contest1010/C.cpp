#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
 
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
 
struct node {
    int x, y;
};
 
int n, m, fi[60][60][5], sum, tmx;
 
void bfs() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (fi[i][j][0]) continue;
            sum++;
    node start;
    start.x = i;
    start.y = j;
    fi[i][j][0] = 1;
    queue<node> q;
    while (!q.empty()) q.pop();
    q.push(start);
    int num = 1;
    while (!q.empty()) {
        node pre = q.front();
        for (int k = 0; k < 4; k++) {
            int xx = pre.x+dx[k];
            int yy = pre.y+dy[k];
            if (!fi[xx][yy][0] && !fi[pre.x][pre.y][k+1]) {
                fi[xx][yy][0] = 1;
                node now;
                now.x = xx;
                now.y = yy;
                q.push(now);
                num++;
            }
        }
        q.pop();
    }
    if (num > tmx) tmx = num;
        }
    }
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m+1; j++) {
            fi[i][j][0] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &fi[i][j][0]);
            int k = 1;
            while (k <= 4) {
                fi[i][j][k] = fi[i][j][0]%2;
                fi[i][j][0] /= 2;
                k++;
            }
        }
    }
    sum = tmx = 0;
    bfs();
    printf("%d\n%d", sum, tmx);
    return 0;
}
