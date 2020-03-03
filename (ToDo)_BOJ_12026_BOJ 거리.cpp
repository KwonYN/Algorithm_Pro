// BOJ_12026_BOJ 거리
/*
	BOJ 거리는 보도블록 N개가 일렬로 놓여진 형태의 도로(1번부터 N번까지 번호가 매겨져)
	1 -> N
	BOJ거리의 각 보도블록에는 B, O, J 중에 하나가 쓰여 있다. 1번은 반드시 B
	항상 번호가 증가하는 방향으로 점프를 해야 한다.
	한 번 k칸 만큼 점프를 하는데 필요한 에너지의 양은 k*k
	스타트는 B, O, J, B, O, J, B, O, J, ... 순서로 보도블록을 밟으면서 점프를 할 것.
	스타트가 링크를 만나는데 필요한 에너지 양의 최솟값?
*/
#if 01
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define NMAX	(1010)
#define INF		(987654321)

typedef pair<int, int> pii;

int N, min_energy;
string block;
vector<pii> edges[NMAX];
int van_dijk[NMAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);		cout.tie(NULL);
	freopen("in.txt", "r", stdin);
	cin >> N;
	cin >> block;
	for (int i = 0; i < N; i++) van_dijk[i] = INF;
	for (int i = 0; i < N-1; i++) {
		if (block[i] == 'B') {
			for (int j = i + 1; j < N; j++) {
				if (block[j] == 'O') edges[i].push_back({ (j - i) * (j - i), j });
			}
		}
		else if (block[i] == 'O') {
			for (int j = i + 1; j < N; j++) {
				if (block[j] == 'J') edges[i].push_back({ (j - i) * (j - i), j });
			}
		}
		else if(block[i] == 'J') {
			for (int j = i + 1; j < N; j++) {
				if (block[j] == 'B') edges[i].push_back({ (j - i) * (j - i), j });
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) cout << block[i];
	cout << "\n";
	*/
	priority_queue < pii, vector<pii>, greater<pii> > pq;
	pq.push({ 0, 0 }); van_dijk[0] = 0;
	while (!pq.empty()) {
		pii cur = pq.top();		 pq.pop();
		if (van_dijk[cur.second] < cur.first) continue;
		van_dijk[cur.second] = cur.first;
		if (cur.second == N-1) break;
		for (pii child : edges[cur.second]) {
			if (van_dijk[cur.second] + child.first < van_dijk[child.second])
				pq.push({ van_dijk[cur.second] + child.first , child.second});
		}
	}
	if (van_dijk[N-1] == INF) min_energy = -1;
	else min_energy = van_dijk[N-1];

	cout << min_energy << "\n";
	return 0;
}
#endif
