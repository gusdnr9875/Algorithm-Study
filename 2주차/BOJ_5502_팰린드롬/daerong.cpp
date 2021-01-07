//Solution
//- 펠린트롬이라는 대칭 문자열을 구하기 위해 추가할 문자의 갯수를 구하는 문제.
//- 이론적 접근은 다음과 같다.
//- 1. 양 끝에서 출발하는 문자열을 두개 만든다.
//- 1.1.정상 문자열을 str
//- 1.2.역순 문자열을 rts로 기술한다.
//- 2. 다음 과정을 통해 최장길이 문자열 max_len을 구한다.
//- 2.1.x와 y는 각각 str, rts에 대한 index이며 0에서 부터 시작한다.
//- 2.2.str[x] == rts[y]인 경우,
//- 2.2.1.문자열의 길이가 1 증가하고
//- 2.2.2.양쪽의 인덱스를 모두 1 증가시킨다. = > (x + 1, y + 1)
//- 2.3.str[x] != rts[y]인 경우,
//- 2.3.1.양쪽의 인덱스를 각각 1 증가시킨다. = > (x + 1, y) && (x, y + 1)
//- 3. 주어진 문자열의 길이 N에서 max_len을 뺀 값이 바로 추가할 문자의 갯수이다.
//- Failed 1 : dp[][]를 string으로 선언해 메모리 초과가 발생했다.
//- 1. 결과를 확인하기 위해 string으로 선언했으나 메모리 초과 발생.
//- 2. 풀이에 string은 필요 없으므로 int형으로 변환해 해결
//- 풀이과정은 다음과 같다.
//- 1. 풀이에 필요한 값을 세팅한다.
//- 1.1.str : 주어진 문자열
//- 1.2.rts : str을 역순으로 배열한 문자열
//- 1.3.dp[y][x] : str[x], rts[y] 위치에서의 최장 펠린드롬 길이
//- 2. y = N - 1, y = N - 1를 시작으로 expand()를 수행하여 dp[][]를 세팅한다.
//- 2.1.영역을 벗어난 경우 최장길이 0을 return
//- 2.2.이미 최장길이를 구한 경우, dp[y][x]를 리턴
//- 2.3.str[x] == rts[y]인 경우,
//- 2.3.1.dp[y][x]에 expand(x - 1, y - 1) + 1을 저장하고
//- 2.3.2.dp[y][x]의 값을 리턴
//- 2.4.str[x] != rts[y]인 경우,
//- 2.4.1.expand(x - 1, y)와 expand(x, y - 1)의 최대값을 구하고
//- 2.4.2.dp[y][x]에 2.4.1.에서 구한 최대값을 저장하고
//- 2.4.3.dp[y][x]의 값을 리턴
//- 3. 위 과정을 반복한 후, dp[N - 1][N - 1]의 값을 결과로 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAP_MAX 5000

int N;
string str;
string rts;
vector<vector<int>> dp;

void init() {
	cin >> N;
	cin >> str;
	rts = str;
	reverse(rts.begin(), rts.end());
	for (int y = 0; y < N; y++) {
		vector<int> line;
		for (int x = 0; x < N; x++) {
			line.push_back(-1);
		}
		dp.push_back(line);
	}
}

int expand(int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (dp[y][x] != -1) return dp[y][x];

	if (str[x] == rts[y]) {
		return dp[y][x] = expand(x - 1, y - 1) + 1;
	}
	else {
		return dp[y][x] = max(expand(x - 1, y), expand(x, y - 1));
	}
}

void print_map() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << dp[y][x] << " ";
		}
		cout << endl;
	}
}

void solution() {
	init();
	cout << N - expand(N - 1, N - 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}