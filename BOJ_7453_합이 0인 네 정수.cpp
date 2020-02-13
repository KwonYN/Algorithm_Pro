#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX	4010

int N;
int A[MAX], B[MAX], C[MAX], D[MAX];
int AB[MAX*MAX], CD[MAX*MAX];
int idx;

void input()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}
}

void div()
{
	idx = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			AB[idx] = A[i] + B[j];
			CD[idx++] = C[i] + D[j];
			//if((i == N-1) && (j == N-1)) printf("%d\n", i*N+j);
		}
	}
	sort(AB, AB + idx);
	sort(CD, CD + idx);
}

long long int answer()
{
	long long int ans = 0;
	int s = 0, e = idx - 1;
	int sum;
	int ss, ee;
	int s_idx;

	while((s < idx) && (0 <= e))
	{
		sum = AB[s] + CD[e];
		if(sum == 0)
		{
			s_idx= s;
			ss = ee = 0;

			/*
			// s+1나 e-1이 배열 범위를 벗어날 수도 있음;;
			while(AB[s] == AB[s+1])
			{
				s++;
				ss++;
			}
			while(CD[e] == CD[e-1])
			{
				e--;
				ee++;
			}
			*/

			while(AB[s] + CD[e] == 0)
			{
				if(s >= idx) break;
				ss++;	s++;
			}
			while(AB[s_idx] + CD[e] == 0)
			{
				if(e < 0) break;
				ee++;	e--;
			}
			ans += (ss * ee);
			//s++; e--;
		}
		else if(sum < 0) s++;
		else e--;
	}

	return ans;	// 4000^4 만큼을 담아야 할 수도 있기 때문!
}

/*
void print_input()
{
	printf("  A   B   C   D\n");
	for(int i = 0; i < N; i++) printf("%3d %3d %3d %3d\n", A[i], B[i], C[i], D[i]);
	printf("  AB   CD\n");
	for(int i = 0; i < N * N; i++) printf("%4d %4d\n", AB[i], CD[i]);
}
*/

int main()
{
	input();
	div();
	//print_input();
	printf("%lld\n", answer());

	return 0;
}
