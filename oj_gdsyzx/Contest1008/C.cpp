#include<stdio.h>
#include<queue>
#define MAX 1001
using namespace std;
  
void filecache() {
    freopen("labyrinth.in", "r", stdin);
    freopen("labyrinth.out", "w", stdout);
}
  
struct Map {
    int x;
    int y;
} pre[MAX][MAX];
bool book[MAX][MAX], flag;
int a[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
int map[MAX][MAX], n, m, ans;
  
int in(int x, int y) {
    if (x > 0 && x <= n && y > 0 && y <= m) return 1;
    return 0;
}
  
void bfs() {
    queue<Map> q;
    while (!q.empty()) q.pop();
    book[1][1] = true;
    Map cur;
    cur.x = cur.y = 1;
    q.push(cur);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = cur.x + a[i][0];
            int y = cur.y + a[i][1];
            if (in(x, y) && !book[x][y] && !map[x][y]) {
                Map temp;
                temp.x = x;
                temp.y = y;
                q.push(temp);
                book[x][y] = true;
                pre[x][y].x = cur.x;
                pre[x][y].y = cur.y;
                if (x == n && y == m) return;
            }
        }
    }
    return;
}
  
int count(int x, int y) {
    if (x == 0 && y == 0) {
        flag = true;
        return 0;
    }
    if (x == 1 && y == 1) return 1;
    return count(pre[x][y].x, pre[x][y].y)+1;
}
  
int main() {
    //filecache();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    bfs();
    flag = false;
    ans = count(n, m);
    if (flag) {
        printf("0");
    } else {
        printf("%d", count(n, m));
    }
    return 0;
}
