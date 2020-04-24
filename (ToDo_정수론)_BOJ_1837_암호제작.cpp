// BOJ_1837_암호제작
#if 01
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX		(1000000)

string P;
int K;
int eratos[MAX + 10], sosu[MAX], sosu_cnt;
int len, r;
bool quality;

bool get_quotient(int n) {
	int num = 0;
	for (int i = 0; i < len; i++) {
		num = num * 10 + (P[i]-'0');
		num %= n;
	}
	if (!num) return true;
	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	quality = false;
	eratos[0] = eratos[1] = 1;		sosu_cnt = 0;
	for (int i = 2; i <= MAX; i++)
	{
		if (eratos[i]) continue;
		sosu[++sosu_cnt] = i;
		for (int j = 2 * i; j <= MAX; j += i) eratos[j]++;
	}
	cin >> P; cin >> K;				len = P.length();
	for (int i = 1; i <= sosu_cnt; i++) {
		if (sosu[i] < K) {
			if (get_quotient(sosu[i])) {
				r = sosu[i];
				break;
			}
		}
		else { quality = true; break;  }
	}
	if (quality) cout << "GOOD" << "\n";
	else cout << "BAD " << r << "\n";
	return 0;
}
#endif
