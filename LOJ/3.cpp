#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main() {
	freopen("copycat.in", "r", stdin);
	freopen("copycat.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		string a;
		cin >> a;
		cout << a << endl;
	}
	return 0;
}
