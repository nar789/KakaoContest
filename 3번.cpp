#include <string>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
	int use[100] = { 0, };

	for (auto i : sentence) {
		if(i>='a')
			use[i - 'a']++;
	}
	char exception = 0;
	int incnt = -1;
	char in = 0;
	int idx = 0;
	int outpos = -1;
	char back = 0;
	bool doubleoption = false;
	for (auto i : sentence)
	{
		if (i == ' ')return "invalid";
		if (i < 'a') {
			if (exception != 0 && exception != i && outpos >= 0 && doubleoption)
			{
				if ((idx - outpos) % 2 != 1)return "invalid";
			}
			answer += i;
			if (incnt > 0) {
				if (back != in)return "invalid";
				incnt--;
			}
			if (incnt == 0) {
				if (answer.back() != ' ' && idx!=sentence.size()-1 && !exception)answer += ' ';
				incnt--; in = 0;
			}
		}
		else {
			if (exception != 0 && exception != i && outpos>=0)
			{
				doubleoption = true;
				if ((idx - outpos) % 2 != 0)return "invalid";
			}
			if (use[i - 'a'] == 2)
			{
				if (exception==0) {
					if (incnt >= 0)return "invalid";
					if(answer.size()!=0 && answer.back() != ' ')answer += ' ';
					outpos = idx;
					exception = i;
				}
				else if (exception == i) {
					if (doubleoption)
						doubleoption = false;
					exception = 0;
					outpos = -1;
					if (incnt >= 0)return "invalid";
					if (back >= 'a' || back == ' ')return "invalid";
					if (answer.back() != ' ' && idx != sentence.size() - 1)answer += ' ';

				}
			}
			else {
				if (back == 0 || back >= 'a')return "invalid";
				if (incnt < 0) {
					incnt = use[i - 'a'];
					in = i;
					if (answer.size()>1 && !exception && answer[answer.size() - 2] !=' '){
						char b = answer.back();
						if (b == ' ' || b >= 'a')return "invalid";
						answer = answer.substr(0, answer.size() - 1);
						answer += ' ';
						answer += b;
					}
				}
				else if (incnt >= 0 && in != i)return "invalid";
			}
		}
		idx++;
		back = i;
	}

	if (incnt >= 0 || outpos >= 0) return "invalid";
    return answer;
}