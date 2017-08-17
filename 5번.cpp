#include <vector>
#include<cmath>
#include<iostream>
#include<algorithm>
#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a
using namespace std;

void sort(vector<vector<int>>& data, int k,int n,int** &s) {
	if (!k)sort(data.begin(), data.end(), [](vector<int>&a, vector<int>&b)->bool {return (a[0]<b[0]); });
	else sort(data.begin(), data.end(), [](vector<int>&a, vector<int>&b)->bool {return (a[1]<b[1]); });
	int idx = 0;
	int origin = data[0][k];
	data[0][k] = idx;
	if (k == 1)s[data[0][0]+1][data[0][1]+1] = 1;
	for (int i = 1; i < data.size(); i++) {
		if (origin== data[i][k])data[i][k] = idx;
		else {
			origin = data[i][k];
			data[i][k] = ++idx;
		}
		if (k == 1) {
			int x = data[i][0] + 1; int y = data[i][1] + 1;
			if (y < n && x < n)s[x][y] = 1;
		}
	}
}

int solution(int n, vector<vector<int>> data) {
	int answer = 0;
	int **s = new int*[n];
	for (int i = 0; i < n; i++) {
		s[i] = new int[n]; 
	}
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) { s[i][j] = 0; }
	for (int k = 0; k < 2; k++) sort(data,k,n,s);
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

	for (int i = 0; i < data.size()-1; i++)
	{
		for (int j = i + 1; j < data.size(); j++)
		{
			if (data[i][0] == data[j][0] || data[i][1] == data[j][1])continue;
			int maxx = max(data[i][0], data[j][0]);int minx = min(data[i][0], data[j][0]);
			int maxy = max(data[i][1], data[j][1]);int miny = min(data[i][1], data[j][1]);
			int a = s[maxx][maxy];int b = s[minx+1][maxy];int c = s[maxx][miny+1];int d = s[minx+1][miny+1];
			int m = a - (b + c) + d;
			if (m == 0) answer++;
		}
	}

	for (int i = 0; i < n; i++)delete s[i];
	delete s;
	return answer;
}

int main()
{
	vector<vector<int>> k;
	const int N = 10;
	for (int i = 0; i <N; i++)
		k.push_back({ i,i });
	cout << solution(N, k);
	return 0;
}