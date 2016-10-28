#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
 
struct node {
    int data, pos;
} a[100001], b[100001];
 
int n, p[100001], t[100001], ans = 0;
 
int cmp(const node &x, const node &y) {
    return x.data < y.data;
}
 
void merge(int l, int r) {
    if (l >= r) return;
    int mid = (l+r)/2;
    merge(l, mid);
    merge(mid+1, r);
    int i = l, j = mid+1, k = l;
    while (i <= mid && j <= r) {
        if (p[i] <= p[j]) t[k++] = p[i++];
        else {
            t[k++] = p[j++];
            ans += mid-i+1;
            ans %= 99999997;
        }
    }
    while (i <= mid) t[k++] = p[i++];
    while (j <= r) {
        t[k++] = p[j++];
        ans += mid-i+1;
        ans %= 99999997;
    }
    memcpy(p+l, t+l, sizeof(int)*(r-l+1));
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].data);
        a[i].pos = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i].data);
        b[i].pos = i;
    }
    sort(a+1, a+n+1, cmp);
    sort(b+1, b+n+1, cmp);
    for (int i = 1; i <= n; i++) {
        p[a[i].pos] = b[i].pos;
    }
    merge(1, n);
    printf("%d", ans);
    return 0;
}
