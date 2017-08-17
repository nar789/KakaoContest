#include <string>
#include <iostream>
#include<conio.h>
#include<cmath>
using namespace std;

int dfs(int si,int sc,int n,int num,int jump,int start)
{
	if (si < 0) {
		if (num == n)return 1;
		return 0;
	}

	bool pos = false;
	int sum = 0;
	for (int j = si; j >= 0; j--)
	{
		sum += pow(3,j) * 2 * (start + jump + (si-j)*2);
		if (sum >= n - num)
			pos = true;
	}
	if (!pos)return 0;

	int r = 0;
	for (int i =start; i <=start+jump; i++)
	{
		int k = pow(3, si) * 2 * i;
		if (k > n - num)break;
		r += dfs(si - 1,sc,n,num+k,jump-(i-start)+2,i);
	}
	return r;
}
int solution(int n) {
	
	int answer = 0;
	int sc = 0;
	do {
		if (sc >=19)break;
		if (pow(3,sc+1) > n)
			break;
		else sc++;
	} while (true);
	int num = pow(3,sc) + sc*2;
	if (num == n)return 1;
	answer=dfs(sc-2, sc, n, num, 2,0);
	return answer;
}

int main()
{
	//int n = (((41 * 3 + 2) * 3 + 2) * 3 + 2)*3+2;
	//cout << solution(n) << endl;
	cout << solution(0x7fffffff) << endl;
	return 0;
}