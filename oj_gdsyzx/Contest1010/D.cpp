#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
 
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
 
struct node {
    int x, y, pre;
} q[100];
 
int n, m, fi[10][10], head, tail, point;
 
void print(int p) {
    if (q[p].pre == -1) {
        printf("(%d, %d)\n", q[p].x-1, q[p].y-1);
        return;
    }
    print(q[p].pre);
    printf("(%d, %d)\n", q[p].x-1, q[p].y-1);
}
 
void bfs() {
    head = tail = 1;
    node start;
    start.x = 1;
    start.y = 1;
    start.pre = -1;
    q[head] = start;
    while (head <= tail) {
        node pre = q[head];
        for (int k = 0; k < 4; k++) {
            int xx = pre.x+dx[k];
            int yy = pre.y+dy[k];
            if (!fi[xx][yy]) {
                fi[xx][yy] = 1;
                node now;
                now.x = xx;
                now.y = yy;
                now.pre = head;
                tail++;
                q[tail] = now;
                if (xx == 5 && yy == 5) {
                    point = tail;
                    return;
                }
            }
        }
        head++;
    }
}
 
int main() {
    memset(fi, 1, sizeof(fi));
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &fi[i][j]);
        }
    }
    bfs();
    print(point);
    return 0;
}
