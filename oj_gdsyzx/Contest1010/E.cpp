#include<stdio.h>
#include<queue>
using namespace std;
 
struct cup {
    int l[4], count;
};
 
int n, c[4], sum;
bool b[1001][1001] = {0};
 
int check(cup x) {
    for (int i = 1; i <= 3; i++) {
        if (x.l[i] == n) return 1;
    }
    return 0;
}
 
void init(cup &x, cup &y) {
    for (int i = 1; i <= 3; i++) {
        x.l[i] = y.l[i];
    }
}
 
void bfs(cup start) {
    queue<cup> q;
    while (!q.empty()) q.pop();
    q.push(start);
    while (!q.empty()) {
        cup pre = q.front();
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                if (i != j && (pre.l[i] || pre.l[j])) {
                    cup now;
                    now.count = pre.count+1;
                    init(now, pre);
                    if (pre.l[i] < c[i] && pre.l[j]) {
                        if (pre.l[j] < c[i]-pre.l[i]) {
                            now.l[i] = pre.l[i]+pre.l[j];
                            now.l[j] = 0;
                        } else {
                            now.l[i] = c[i];
                            now.l[j] = pre.l[j]-(c[i]-pre.l[i]); 
                        }
                        if (b[now.l[1]][now.l[2]]) continue;
                        b[now.l[1]][now.l[2]] = 1;
                        q.push(now);
                        if (check(now)) {
                            sum = now.count;
                            return;
                        }
                    }
                }
            }
        }
        q.pop();
    }
}
 
int main() {
    cup start;
    scanf("%d%d%d%d", &c[1], &c[2], &c[3], &n);
    if (n > c[1]) {
        printf("NO");
        return 0;
    }
    start.count = 0;
    start.l[1] = c[1];
    start.l[2] = start.l[3] = 0;
    if (n == c[1]) {
        printf("0");
        return 0;
    }
    bfs(start);
    b[c[1]][0] = 1;
    if (sum == 0) printf("NO");
    else printf("%d", sum);
    return 0;
}
