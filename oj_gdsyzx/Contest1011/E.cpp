#include<stdio.h>
#include<math.h>
using namespace std;

int main() {
	int l, r;
	double n;
	scanf("%lf", &n);
	l = 0; r = n+1;
	while (l < r) {
		int mid = (l+r)/2;
		double k = 1.0*mid*log10(mid);
		if (k > n-1) r = mid;
		else if (k < n-1)l = mid+1;
		else if (k == n-1) {
			l = mid;
			break;
		}
	}
	printf("%d", l);
	return 0;
}
