// (중상) [교육P-0034] 당황한 암호학자 
#if 01

#include <cstdio>
#include <string>
using namespace std;
#define MAX	1000000

int T, L, p;
string K;
int flag;
char *result[2] = { "GOOD", "BAD" };
int sosu[MAX];
int sosu_cnt;
int isPrime[MAX];

bool isDivided(string num, int n)
{
	int new_num = 0;
	int len = num.length();
	for(int i = 0; i < len; i++)
	{
		new_num *= 10;
		new_num += (num[i] - 97);
		new_num %= n;
	}
	if(!new_num) return true;
	return false;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	for (int i = 1; i <= MAX; i++) isPrime[i] = 1;
	sosu_cnt = isPrime[0] = isPrime[1] = 1;
	for (int i = 2; i <= MAX; i++)	 // eratos 배열에 0인 값이 바로 소수!
	{
		sosu[++sosu_cnt] = i;
		if (isPrime[i] == 1)
		{
			for (int j = 2 * i; j <= MAX; j += i) isPrime[j] = 0;
		}
	}
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%s", K);
		scanf("%d", &L);
		printf("K = %s, L = %d\n", K, L);
		flag = 0;	p = L + 1;

		for(int i = 1; sosu[i] <= L; i++)
		{
			if(isDivided(K, sosu[i]))
			{
				flag = 1;
				p = sosu[i];
				break;
			}
		}
		// K에 대해서 어떻게 나눠주나??
		// 가장 큰 자리수부터 한 자리씩 꺼내가면서 L로 모듈려서 해줌!! 그러면서 끝까지!
		// 그럼 나눠 떨어지는지 결국에는 볼 수 있음.
		// (L보다 이하의 소수에 대해서 다!)

		printf("#%d %s", tc, result[flag]);
		if (flag) printf(" %d", p);
		printf("\n");
	}

	return 0;
}

#endif
