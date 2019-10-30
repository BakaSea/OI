#include<stdio.h>
#include<math.h>
using namespace std;

int T;
double H, h, D, x, ans;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf%lf", &H, &h, &D);
		x = D-sqrt((H-h)*D);
		if (x < 0) printf("%.3lf\n", h);
		else if (x > h*D/H) printf("%.3lf\n", h*D/H);
		else printf("%.3lf\n", H+D-2*sqrt((H-h)*D));
	}
	return 0;
}
