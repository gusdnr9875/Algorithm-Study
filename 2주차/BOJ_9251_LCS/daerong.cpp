//Solution
//- 동적계획법의 꽃 LCS!!
//- 이론은 다음과 같다.
//- 1. 두 문자열의 인덱스가 x, y일 때,
//- 2. str[x] != str[y]인 경우,
//- 2.1. dp[y][x]는 dp[y][x-1], dp[y-1][x] 중 큰 수를 취한다. 
//- 2.2. 한글자를 더한다고 해서 그 전에 문자열이 사라지지 않는다.
//- 3. str[x] == str[y]인 경우, 
//- 3.1. dp[y][x] = dp[y-1][x-1] + 1이다.
//- 3.2. 그렇지 않으면 누적이 발생한다. ex> AAAA, ABCD
//- 3.3. dp[Y-1][X-1]의 값은 최장길이 LCS를 갖는다.
//Inefficient 1 : 8ms로 4ms의 두배가량의 시간이 소요됐다. 
//- 코드는 하단에 주석처리 함.
//- 장점
//- 1. 모든 x, y가 아닌, 일부만 접근한다.
//- 1.1. str1 == str2인 경우, 길이+1만 수행한다.
//- 단점
//- 1. dp[][]를 -1로 초기화 해야한다.
//- 2. if문 필요.
//- 2.1. if(x < 0 || y < 0)로 영역 밖 체크.
//- 2.2. if(dp[][] != -1)로 방문여부 체크
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 세팅한다.
//- 1.1. str1, str2 : 주어진 문자열
//- 1.2. dp[y][x] : str1[x], str2[y]에서의 LCS 길이
//- 2. expand() 함수에서 dp[][]를 완성한다.
//- 2.1. x, y를 각각 증가시키며 다음을 수행한다.
//- 2.1.1. str1[x] == str2[y]인 경우, 
//- 2.1.1.1. dp[y][x]에 대각성분 dp[y-1][x-1]에 1을 더한 값을 저장한다.
//- 2.1.2. str1[x] != str2[y]인 경우, 
//- 2.1.2.1. dp[y][x]에 인접성분 dp[y-1][x], dp[y][x-1] 중 큰 값을 저장한다.
//- 3. dp[Y][X]의 값을 출력한다.

#include <iostream>
#include <algorithm>

using namespace std;

#define STR_MAX 1001

int X;
int Y;
string str1;
string str2;
int dp[STR_MAX][STR_MAX];

void init() {
	cin >> str1 >> str2;
	X = str1.length();
	Y = str2.length();
	str1 = " " + str1;
	str2 = " " + str2;
}

void expand() {
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			if (str1[x] == str2[y]) dp[y][x] = dp[y - 1][x - 1] + 1;
			else dp[y][x] = max(dp[y - 1][x], dp[y][x - 1]);
		}
	}
}

void solution() {
	init();
	expand();
	cout << dp[Y][X] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}

////Inefficient 1
////- 풀이는 다음과 같다.
////- 1. 풀이에 필요한 변수를 세팅한다.
////- 1.1. str1, str2 : 주어진 문자열
////- 1.2. X : str1의 길이
////- 1.3. Y : str2의 길이
////- 1.4. dp[y][x] : str1[x], str2[y]에서의 LCS 길이
////- 2. X-1, Y-1을 시작으로 expand()를 수행하여 dp[][]를 채운다.
////- 2.1. 영역 밖에선 0을 return
////- 2.2. dp[][] == -1인 경우, dp[][] return
////- 2.3. 다음의 조건에 따라 dp[y][x]를 업데이트 하고 return
////- 2.3.1. str1[x] == str2[y]인 경우, 대각선 dp[y-1][x-1]에 1을 더한다.
////- 2.3.2. str1[x] != str2[y]인 경우, dp[y-1][x], dp[y][x-1] 중 큰 값을 취한다.
////- 3. dp[Y-1][X-1]의 값을 출력한다.
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//#define STR_MAX 1001
//
//int X;
//int Y;
//string str1;
//string str2;
//int dp[STR_MAX][STR_MAX];
//
//void init() {
//	cin >> str1 >> str2;
//	X = str1.length();
//	Y = str2.length();
//	for (int y = 0; y < Y; y++) {
//		for (int x = 0; x < X; x++) {
//			dp[y][x] = -1;
//		}
//	}
//}
//
//int expand(int x, int y) {
//	if (x < 0 || y < 0) return 0;
//	if (dp[y][x] != -1) return dp[y][x];
//
//	if (str1[x] == str2[y]) {
//		return dp[y][x] = expand(x - 1, y - 1) + 1;
//	}
//	else {
//		return dp[y][x] = max(expand(x - 1, y), expand(x, y - 1));
//	}
//}
//
//void solution() {
//	init();
//	cout << expand(X - 1, Y - 1) << endl;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	solution();
//
//	return 0;
//}