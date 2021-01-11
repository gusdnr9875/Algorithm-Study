//Solution
//- 주어진 조건으로 만들 수 있는 모든 문자열을 출력하는 문제.
//- 시뮬레이션, DFS, 백트래킹
//- 이론적 접근은 다음과 같다.
//- 1. 주어진 문자배열을 오름차순으로 정렬한다.
//- 2. DFS로 순회하면서 다음의 조건을 찾는다.
//- 2.1. 길이가 4이면서, 
//- 2.2. 모음이 1개 이상
//- 2.3. 자음이 2개 이상
//- 3. 위와 같이 모든 문자열을 찾을 수 있다.
//- 풀이 방법은 다음과 같다.
//- 1. 풀이에 필요한 변수를 세팅한다.
//- 1.1. L : 만들 문자열의 길이
//- 1.2. C : 주어진 문자의 갯수
//- 1.3. arr : 주어진 문자 배열
//- 1.4. result : 결과 문자열 배열
//- 1.5. s : 모음이 저장될 set
//- 2. dfs()함수를 사용해 조건에 맞는 문자열을 찾는다.
//- 2.1. cnt == L인 문자열에 대해 다음을 확인한다. (cnt는 str의 길이)
//- 2.1.1. 모음이 1개 이상이고 자음이 2개 이상인 문자이면 다음을 수행한다.
//- 2.1.2. result 배열에 str을 넣는다.
//- 2.2. dfs()의 index를 이동시키며 다음처럼 확장한다.
//- 2.2.1. 현재 문자를 선택하는 경우, 
//- 2.2.1.1. 현재문자가 모음이면 cnt값과 s_cnt 값을 1증가시킨 후 이동한다.
//- 2.2.1.2. 현재문자가 자음이면 cnt값만 1증가시킨 후 이동한다.
//- 2.2.2. 현재 문자를 선택하지 않는 경우,
//- 2.2.2.1. index만 이동하여 수행한다.
//- 2.3. 영역을 벗어난 경우, 종료한다.
//- 3. 2.과정을 통해 저장한 모든 문자열을 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

vector<char> arr;
int L;
int C;
unordered_set<char> s;
set<string> result;

void init() {
	cin >> L >> C;
	char temp;
	for (int c = 0; c < C; c++) {
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');
}

void dfs(int target, int cnt, string str, int s_cnt) {
	if (cnt == L) {
		if (s_cnt >= 1 && cnt - s_cnt >= 2) {
			result.insert(str);
		}
		return;
	}
	if (target >= C) return;

	if (s.count(arr[target]) == 1) dfs(target + 1, cnt + 1, str + arr[target], s_cnt + 1);
	else dfs(target + 1, cnt + 1, str + arr[target], s_cnt);
	dfs(target + 1, cnt, str, s_cnt);
}

void solution() {
	init();
	dfs(0, 0, "", 0);
	for (set<string>::iterator it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie();

	solution();

	return 0;
}