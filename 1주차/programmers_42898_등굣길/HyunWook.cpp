#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[101][101];
int arr[101][101] = { 0, };
int y_ar[2] = { 0,-1 };
int x_ar[2] = { -1,0 };

int solved(int y, int x) {
	if (y == 1 && x == 1)
		return 1;
	int &ret = dp[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i<2; i++) {
		int ny = y + y_ar[i];
		int nx = x + x_ar[i];
		if (ny >= 1 && nx >= 1 && arr[ny][nx] != 1) {
			ret += solved(ny, nx);
			ret %= 1000000007;
		}
	}
	return ret;
}
int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;

	for (int i = 0; i<puddles.size(); i++) {
		arr[puddles[i][1]][puddles[i][0]] = 1;
	}

	memset(dp, -1, sizeof(dp));
	answer = solved(n, m);
	return answer;
}