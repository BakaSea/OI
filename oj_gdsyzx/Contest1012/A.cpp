#include<stdio.h>
#include<algorithm>
  
struct T {
    int s, e;
} ti[105];
  
int cmp(const T &a, const T &b) {
    return a.e < b.e;
}
  
int main() {
    int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &ti[i].s, &ti[i].e);
            if (ti[i].s > ti[i].e) {
                int temp = ti[i].s;
                ti[i].s = ti[i].e;
                ti[i].e = temp;
            }
        }
        std::sort(ti+1, ti+n+1, cmp);
        int ans = 1, cur = ti[1].e;
        for (int i = 1; i <= n; i++) {
            if (ti[i].s >= cur) {
                cur = ti[i].e;
                ans++;
            }
        }
        printf("%d\n", ans);
    return 0;
}
