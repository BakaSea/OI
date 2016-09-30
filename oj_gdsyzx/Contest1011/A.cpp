#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
 
int main() {
    int l, r, n, m, a[100001];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    while (m--) {
    	int t;
    	scanf("%d", &t);
    	l = 1; r = n;
    	while (l+1 < r) {
    		int mid = (l+r)/2;
    		if (a[mid] < t) l = mid;
    		else if (a[mid] > t) r = mid;
    		else {
    			l = mid;
    			break;
			}
		}
		if (abs(t-a[l]) > abs(t-a[r])) printf("%d\n", a[r]);
		else printf("%d\n", a[l]);
	}
    return 0;
}
