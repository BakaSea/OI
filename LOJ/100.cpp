#include<stdio.h>
#include<string.h>
#define MOD 1000000007
using namespace std;

struct MAT {
	
	long long d[510][510];
	int m, n;
	
	MAT (int mm = 0, int nn = 0) {
		m = mm; n = nn;
		memset(d, 0, sizeof(d));
	}
	
	MAT operator * (const MAT &B){
		MAT C = MAT(m, B.n);
		for (int i = 1; i <= C.m; ++i)
			for (int j = 1; j <= C.n; ++j)
				for (int k = 1; k <= n; ++k) {
					C.d[i][j] = (C.d[i][j]+d[i][k]*B.d[k][j])%MOD;
					while (C.d[i][j] < 0) C.d[i][j] = (C.d[i][j]+MOD)%MOD;
				}
		return C;
	}
	
};

int n, p, m;

int main() {
	scanf("%d%d%d", &n, &p, &m);
	MAT A = MAT(n, p), B = MAT(p, m), C = MAT(n, m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= p; ++j)
			scanf("%lld", &A.d[i][j]);
	for (int i = 1; i <= p; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%lld", &B.d[i][j]);
	C = A*B;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			printf("%lld ", C.d[i][j]);
		printf("\n");
	}
	return 0;
}
