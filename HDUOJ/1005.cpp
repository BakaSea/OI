#include<stdio.h>
#include<string.h>
using namespace std;

struct MAT {
	int d[10][10], m, n;
	
	MAT(int mm = 0, int nn = 0) {
		m = mm; n = nn;
		memset(d, 0, sizeof(d));
	}
	
	MAT operator * (const MAT &B) {
		MAT C = MAT(m, B.n);
		for (int i = 1; i <= C.m; ++i) {
			for (int j = 1; j <= C.n; ++j) {
				for (int k = 1; k <= n; ++k) {
					C.d[i][j] = (C.d[i][j]+d[i][k]*B.d[k][j])%7;
				}
			}
		}
		return C;
	}
	
} E = MAT(2, 2);

int n, a, b;

MAT pow(MAT X, int k) {
	if (!k) return E;
	MAT Y = pow(X, k/2);
	if (k%2) return Y*Y*X;
	else return Y*Y;
}

int main() {
	E.d[1][1] = 1; E.d[1][2] = 0; E.d[2][1] = 0; E.d[2][2] = 1;
	while (scanf("%d%d%d", &a, &b, &n) != EOF && !(n == 0 && a == 0 && b == 0)) {
		MAT X = MAT(2, 2), F = MAT(2, 1);
		X.d[1][1] = a; X.d[1][2] = b; X.d[2][1] = 1; X.d[2][2] = 0;
		F.d[1][1] = F.d[2][1] = 1;
		if (n <= 2) printf("1\n");
		else {
			MAT Y = pow(X, n-2)*F;
			printf("%d\n", Y.d[1][1]);
		}
	}
	return 0;
}
