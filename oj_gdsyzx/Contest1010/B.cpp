#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
 
const int
    dx[6] = {0, 0, 0, 1, 0, -1}, 
    dy[6] = {0, 0, 1, 0, -1, 0},
    dz[6] = {1, -1, 0, 0, 0, 0};
 
struct node {
    int x, y, z;
};
 
int n, m, r, fi[40][40][40], t, x1, y1, z1, x2, y2, z2;
 
void bfs() {
    node start;
    start.x = x1;
    start.y = y1;
    start.z = z1;
    fi[x1][y1][z1] = 1;
    queue<node> q;
    while (!q.empty()) q.pop();
    q.push(start);
    while (!q.empty()) {
        node pre = q.front();
        for (int k = 0; k < 6; k++) {
            int xx = pre.x+dx[k];
            int yy = pre.y+dy[k];
            int zz = pre.z+dz[k];
            if (!fi[xx][yy][zz]) {
                fi[xx][yy][zz] = fi[pre.x][pre.y][pre.z]+1;
                node now;
                now.x = xx;
                now.y = yy;
                now.z = zz;
                q.push(now);
            }
        }
        q.pop();
    }
}
 
int main() {
    while (scanf("%d%d%d%*c", &r, &n, &m)) {
        if (n == 0 && m == 0 && r == 0) break;
        memset(fi, 1, sizeof(fi));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    char c;
                    scanf("%c", &c);
                    if (c == 'S') {
                        x1 = j;
                        y1 = k;
                        z1 = i;
                        fi[x1][y1][z1] = 0;
                    }
                    if (c == 'E') {
                        x2 = j;
                        y2 = k;
                        z2 = i;
                        fi[x2][y2][z2] = 0;
                    }
                    if (c == '.') {
                        fi[j][k][i] = 0;
                    }
                    if (c == '#') {
                        fi[j][k][i] = 1;
                    }
                }
                scanf("%*c");
            }
            scanf("%*c");
        }
        bfs();
        if (!fi[x2][y2][z2]) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", fi[x2][y2][z2]-1);
    }
    return 0;
}
