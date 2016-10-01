#include<string.h>
#include<iostream>
#include<stdio.h>
#define MAXN 200
using namespace std;

struct BIGNUM {
	int len, s[MAXN];
	
	BIGNUM() {
		memset(s, 0, sizeof(s));
		len = 1;
	}
	
	BIGNUM operator = (const char* num) {
		len = strlen(num);
		for (int i = 0; i < len; i++) s[i] = num[len-i-1]-'0';
		return *this;
	}
	
	BIGNUM operator = (const int num) {
		char a[MAXN];
		sprintf(a, "%d", num);
		*this = a;
		return *this;
	}
	
	BIGNUM(const int num) {
		*this = num;
	}
	
	BIGNUM(const char *num) {
		*this = num;
	}
	
	BIGNUM operator + (const BIGNUM &a) {
		BIGNUM c;
		 c.len = max(len, a.len)+1;
		 for (int i = 0, x = 0; i < c.len; i++) {
		 	c.s[i] = s[i]+a.s[i]+x;
		 	x = c.s[i]/10;
		 	c.s[i] %= 10;
		 }
		 while (c.s[c.len-1] == 0 && c.len > 1) c.len--;
		 return c;
	}
	
	BIGNUM operator * (const BIGNUM &x) {
		BIGNUM c;
		c.len = len+x.len;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < x.len; j++) {
				c.s[i+j] += s[i]*x.s[j];
				c.s[i+j+1] += c.s[i+j]/10;
				c.s[i+j] %= 10;
			}
		}
		while (c.s[c.len-1] == 0 && c.len > 1) c.len--;
		return c;
	}
	
	BIGNUM operator / (const int b) {
		BIGNUM c;
		c.len = len;
		for(int i = len-1; i >= 0; i--) {
        	if (s[i]%b != 0) 
				c.s[i-1] += 10*(s[i]%b);
        	c.s[i] = (c.s[i]+s[i])/b;
    	}
    	while(c.s[c.len-1] == 0 && c.len > 1) 
			c.len--;
    	return c;
	}
	
	bool operator < (const BIGNUM &x) const {
		if (len != x.len) return len < x.len;
		for (int i = len-1; i >= 0; i--) {
			if (s[i] != x.s[i]) return s[i] < x.s[i];
		}
		return false;
	}
	
	bool operator <= (const BIGNUM &x) const {
		return !(x < *this);
	}
	
	bool operator == (const BIGNUM &x) const {
		return !(x < *this || *this < x);
	}
};

istream &operator >> (istream &in, BIGNUM &x) {
	char num[MAXN];
	in >> num;
	x = num;
	return in;
}

ostream &operator << (ostream &out, const BIGNUM &x) {
	for (int i = x.len-1; i >= 0; i--) {
		cout << x.s[i];
	}
	return out;
}

int main() {
	BIGNUM n, l, r, mid;
	cin >> n;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	l = 0; r = n;
	while (l < r) {
		mid = (l+r)/2;
		if (mid == l) {
			cout << l << endl;
			return 0;
		}
		if (mid*mid*mid+mid*mid+mid+mid+mid <= n) l = mid;
		else r = mid;
	}
	return 0;
}
