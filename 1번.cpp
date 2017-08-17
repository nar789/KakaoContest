#include<iostream>

using namespace std;

#include <vector>
#include <queue>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

	
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	queue<vector<int>> q;
	int d[][2] = { {-1,0},{1,0},{0,1},{0,-1} };


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			
			int color = 0;
			if (picture[i][j] != 0) {
				q.push({ i,j });
				number_of_area++;
				color = picture[i][j];
			}
			int size_of_one_area = 0;
			while (!q.empty()) {
				auto t = q.front();
				q.pop();
				picture[t[0]][t[1]] = 0;
				size_of_one_area++;
				
				for (int k = 0; k < 4; k++) {
					int dy = t[0]+d[k][0];
					int dx = t[1]+d[k][1];
					if (dy < 0 || dy >= m || dx < 0 || dx >= n || picture[dy][dx]!=color)continue;
					q.push({ dy,dx });
					picture[dy][dx] = 0;
				}
			}
			if (size_of_one_area > max_size_of_one_area)
				max_size_of_one_area = size_of_one_area;
		}
	}
	

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	vector<vector<int>> pic = { {1,1,1,0},{1,1,1,0},{0,0,0,1}, {0,0,0,1},{0,0,0,1},{0,0,0,1} };
	auto a = solution(6, 4, pic);
	cout << a[0] << " " << a[1] << endl;
	return 0;
}