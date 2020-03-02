// BOJ_12904_A와 B
/*
	두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임.
	문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능.
	1) 문자열의 뒤에 A를 추가
	2) 문자열을 뒤집고 뒤에 B를 추가
	=> S를 T로 만들 수 있는지 없는지 알아내는 프로그램을 작성
*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX	(1000)

char S[MAX+10], T[MAX+10]; // S의 길이 < T의 길이
int s_len, t_len;
bool flag;

char *str_reverse(char *str, int len) {
	char tmp[MAX+10] = { '\0' };
	for(int i = 0; i < len; i++) tmp[i] = str[i];
	for(int i = len - 1; i >= 0; i--) {
		str[len - i - 1] = tmp[i];
	}
	str[len] = '\0';
	return str;
}

int main() {
	s_len = t_len = 0;
	scanf("%s", S);		while(S[s_len]) s_len++;
	scanf("%s", T);		while(T[t_len]) t_len++;
	//printf("%s\n", str_reverse(T, t_len));
	
	printf("%d\n", flag); // 만들 수 있으면 true, 아니면 false
	return 0;
}
