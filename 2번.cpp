#include <vector>
#include<iostream>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;

	struct node {
		int left, up;
	};
	
	node** d;
	d = new node*[m];
	for (int i = 0; i < m; i++)
		d[i]= new node[n];
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			if (i == 0 && j == 0) {
				d[0][0] = {0,0};
				continue;
			}
			
			int left = 0, up = 0;
			if (j - 1 >= 0) {
				if (city_map[i][j - 1] == 2)left = d[i][j - 1].left;
				if (i == 0 && j - 1 == 0)left = 1;
				else if (city_map[i][j - 1] == 0)left = (d[i][j - 1].left + d[i][j - 1].up) % MOD;
			}
			if (i - 1 >= 0) {
				if (city_map[i - 1][j] == 2)up = d[i - 1][j].up;
				if (i-1 == 0 && j== 0)up = 1;
				else if (city_map[i-1][j] == 0)up = (d[i-1][j].left + d[i-1][j].up) % MOD;
			}
			d[i][j] = { left,up };
		}
	}
	answer = (d[m - 1][n - 1].left + d[m - 1][n - 1].up) % MOD;
	for (int i = 0; i < m; i++)
		delete d[i];
	delete d;
	return answer;
}

int main()
{
	int a = solution(3, 3, { {0,0,0},{ 0,0,0 },{ 0,0,0 } });
	cout << a << endl;
	return 0;
}