#include<stdio.h>
#include<math.h>
#define eps 1e-6
using namespace std;

double ax, ay, bx, by, cx, cy, dx, dy, p, q, r;

double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double cal(double x, double y) {
	double lx = cx, ly = cy, rx = dx, ry = dy, lt, rt;
	while (fabs(rx-lx) > eps || fabs(ry-ly) > eps) {
		double lmidx = lx+(rx-lx)/3, lmidy = ly+(ry-ly)/3, rmidx = rx-(rx-lx)/3, rmidy = ry-(ry-ly)/3;
		lt = dis(ax, ay, x, y)/p+dis(x, y, lmidx, lmidy)/r+dis(lmidx, lmidy, dx, dy)/q;
		rt = dis(ax, ay, x, y)/p+dis(x, y, rmidx, rmidy)/r+dis(rmidx, rmidy, dx, dy)/q;
		if (lt < rt) {
			rx = rmidx;
			ry = rmidy;
		} else {
			lx = lmidx;
			ly = lmidy;
		}
	}
	return lt;
}

int main() {
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy, &p, &q, &r);
	double lx = ax, ly = ay, rx = bx, ry = by;
	while (fabs(rx-lx) > eps || fabs(ry-ly) > eps) {
		double lmidx = lx+(rx-lx)/3, lmidy = ly+(ry-ly)/3, rmidx = rx-(rx-lx)/3, rmidy = ry-(ry-ly)/3;
		if (cal(lmidx, lmidy) < cal(rmidx, rmidy)) {
			rx = rmidx;
			ry = rmidy;
		} else {
			lx = lmidx;
			ly = lmidy;
		}
	}
	printf("%.2lf", cal(lx, ly));
	return 0;
}
