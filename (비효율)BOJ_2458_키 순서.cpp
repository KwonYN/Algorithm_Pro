// BOJ_2458_키 순서
#include <cstdio>
#include <queue>
using namespace std;
#define MMAX	(500)

int N, M;
int howTall[MMAX+2][MMAX+2];
int cnt;
int tall, shrt;

int bfs1(int s) {
	queue<int> que;
	int chk[MMAX+2] = { 0 };
	int out, lv_cnt = 0;

	que.push(s);	chk[s] = 1;
	while(!que.empty()) {
		out = que.front();	que.pop();
		for(int i = 1; i <= N; i++) {
			if(howTall[out][i] && !chk[i]) {	// 더 작음
				que.push(i);
				chk[i] = 1;
				lv_cnt++;
			}
		}
	}
	return lv_cnt;
}

int bfs2(int s) {
	queue<int> que;
	int chk[MMAX+2] = { 0 };
	int out, lv_cnt = 0;

	que.push(s);	chk[s] = 1;
	while(!que.empty()) {
		out = que.front();	que.pop();
		for(int i = 1; i <= N; i++) {
			if(howTall[i][out] && !chk[i]) {	// 더 큼
				que.push(i);
				chk[i] = 1;
				lv_cnt++;
			}
		}
	}
	return lv_cnt;
}

int main() {
	int a, b;
	cnt = 0;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		howTall[b][a] = 1; // b > a
	}
	for(int i = 1; i <= N; i++) {
		shrt = bfs1(i);		tall = bfs2(i);
		if(tall + shrt == N-1) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
