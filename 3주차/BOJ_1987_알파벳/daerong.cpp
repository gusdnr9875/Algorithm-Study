//Solution
//- 알파벳 중복 없이 가장 길게 연장할 수 있는 path를 찾는 문제
//- 이론적 접근은 다음과 같다.
//- 1. dfs로 연장하면서 최장경로를 찾을 수 있다.
//- 2. 알파벳은 26자로 26개의 비트로 방문여부를 체크할 수 있다.
//- 3. 이동하면서 방문여부를 체크하고 확장한다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 선언한다.
//- 1.1. dx[], dy[] : 인접한 셀에 이동하기 위한 변수
//- 1.2. char[][] map : 주어진 알파벳 배열
//- 1.3. answer : 연장할 수 있는 최대길이
//- 2. dfs() 함수를 통해 최장길이를 확인한다.
//- 2.1. 영역을 벗어난 위치에 대해 다음을 수행한다.
//- 2.1.1. answer < cnt인 경우, answer를 cnt로 수정한다.
//- 2.2. 기 방문을 체크한다.
//- 2.2.1. checked & 1 << 알파벳 넘버(A = 0, B = 1 ...)로 확인할 수 있다.
//- 2.2.2. 기 방문 시, 
//- 2.2.2.1. answer < cnt인 경우, answer를 cnt로 수정한다.
//- 2.3. 인접한 방향에 대해 dfs()를 실행한다.
//- 3. answer을 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 20

int Y;
int X;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
vector<string> map;
int answer;

void init() {
	cin >> Y >> X;
	string temp;
	for (int y = 0; y < Y; y++) {
		cin >> temp;
		map.push_back(temp);
	}
}

int get_index(char target) {
	return target - 'A';
}

void dfs(int x, int y, int checked, int cnt) {
	if (x < 0 || x >= X || y < 0 || y >= Y) {
		answer = max(answer, cnt);
		return;
	}
	if (checked & (1 << get_index(map[y][x]))) {
		answer = max(answer, cnt);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		dfs(nx, ny, checked | (1 << get_index(map[y][x])), cnt + 1);
	}
}

void solution() {
	init();
	dfs(0, 0, 0, 0);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}