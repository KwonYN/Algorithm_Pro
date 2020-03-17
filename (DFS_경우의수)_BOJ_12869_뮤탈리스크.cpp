// BOJ_12869_뮤탈리스크
#if 01
#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int hp[4];
int min_attack;

void mutalisk(int s1, int s2, int s3, int cnt) {
	if(cnt >= min_attack) return;
	if(s1 <= 0 && s2 <= 0 && s3 <= 0) {
		if(min_attack > cnt) min_attack = cnt;
		return;
	}
	if(s1 >= s2 && s1 >= s3) {
		mutalisk(s1-9, s2-3, s3-1, cnt+1);
		mutalisk(s1-9, s2-1, s3-3, cnt+1);
	}
	if(s2 >= s1 && s2 >= s3) {
		mutalisk(s1-3, s2-9, s3-1, cnt+1);
		mutalisk(s1-1, s2-9, s3-3, cnt+1);
	}
	if(s3 >= s1 && s3 >= s2) {	
		mutalisk(s1-1, s2-3, s3-9, cnt+1);
		mutalisk(s1-3, s2-1, s3-9, cnt+1);
	}
}

int main()
{
	min_attack = 0x7fffffff;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &hp[i]);
	mutalisk(hp[1], hp[2], hp[3], 0);
	printf("%d\n", min_attack);
	return 0;
}
#endif
