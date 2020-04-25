// BOJ_1644_소수의 연속합
#if 01
#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>
using namespace std;
#define NMAX    (4000000)

bool eratos[NMAX + 10];
int sosu[NMAX], sosu_cnt, N, cnt;

int main() {
    freopen("in.txt", "r", stdin);
    eratos[0] = eratos[1] = true;   sosu_cnt = 0;
    for (int i = 2; i <= NMAX; i++) {
        if (eratos[i]) continue;
        sosu[++sosu_cnt] = i;
        for (int j = i + i; j <= NMAX; j += i) eratos[j] = true;
    }
    int num;
    scanf("%d", &N);        cnt = 0;
    for (int i = 1; i <= sosu_cnt; i++) {
        num = 0;
        if (sosu[i] > N) break;
        for (int j = i; j <= sosu_cnt; j++) {
            //printf("(+될 소수 : %d) => %d\n", sosu[i], num);
            num += sosu[j];
            if (num >= N) {
                if (num == N) cnt++;
                break;
            }
        }
        //printf("=========================\n");
    }
    printf("%d\n", cnt);
    return 0;
}
#endif
