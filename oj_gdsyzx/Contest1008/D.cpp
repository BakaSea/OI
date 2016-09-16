#include<stdio.h>
   
void filecache() {
    freopen("sudoku.in", "r", stdin);
    freopen("sudoku.out", "w", stdout);
}
   
int ans, map[10][10], bx[10][10] = {0}, by[10][10] = {0}, bs[10][10][10] = {0};
   
void dfs(int x, int y) {
    if (x == 8 && y == 9) {
        ans++;
        return;
    }
    if (y == 9) {
        x++;
        y = 0;
    }
    if (map[x][y]) {
        dfs(x, y+1);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (!bx[x][i] && !by[y][i] && !bs[x/3*3][y/3*3][i]) {
            bx[x][i] = 1;
            by[y][i] = 1;
            bs[x/3*3][y/3*3][i] = 1;
            map[x][y] = i;
            dfs(x, y+1);
            bx[x][i] = 0;
            by[y][i] = 0;
            bs[x/3*3][y/3*3][i] = 0;
            map[x][y] = 0;
        }
    }
    return;
}
   
int main() {
    //filecache();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]) {
                if (!bx[i][map[i][j]] && !by[j][map[i][j]] && !bs[i/3*3][j/3*3][map[i][j]]) {
                    bx[i][map[i][j]] = 1;
                    by[j][map[i][j]] = 1;
                    bs[i/3*3][j/3*3][map[i][j]] = 1;
                } else {
                    printf("0");
                    return 0;
                }
            }
        }
    }
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}
