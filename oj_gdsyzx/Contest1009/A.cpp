#include<stdio.h>
#include<string.h>
using namespace std;
 
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
 
int t, n, m, ma[15][15], sum;
 
void dfs(int step, int x, int y) {
    if (step == n*m) {
        sum++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if (!ma[xx][yy]) {
            ma[xx][yy] = 1;
            dfs(step+1, xx, yy);
            ma[xx][yy] = 0;
        }
    }
    return;
}
 
int main() {
    scanf("%d", &t);
    int x, y;
    while (t--) {
        scanf("%d%d%d%d", &n, &m, &x, &y);
        memset(ma, 1, sizeof(ma));
        sum = 0;
        for (int i = 2; i <= n+1; i++) {
            for (int j = 2; j <= m+1; j++) {
                ma[i][j] = 0;
            }
        }
        x += 2; y += 2;
        ma[x][y] = 1;
        dfs(1, x, y);
        printf("%d\n", sum);
    }
    return 0;
}
