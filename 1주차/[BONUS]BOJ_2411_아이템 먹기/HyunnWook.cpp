#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct MyStruct
{
	int y;
	int x;
}game;

vector <game> item;
int arr[102][102] = { 0, };
int dp[102][102] = { 0, };
int n = 0, m = 0, a, b;

bool cmp(game a, game b) {
	if (a.x < b.x) return 1;
	else if (a.x == b.x) {
		if (a.y < b.y) return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> a >> b;
	int temp_y,temp_x;
	for (int i = 1; i <= a; i++) {
		cin >> temp_y >> temp_x;
		item.push_back({ temp_y,temp_x });
		arr[temp_y][temp_x] = 1;
	}
	item.push_back({ n,m });
	for (int i = 1; i <= b; i++) {
		cin >> temp_y >> temp_x;
		arr[temp_y][temp_x] = -1;
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	*/
	dp[1][0] = 1;
	sort(item.begin(), item.end(), cmp);

	int current_y = 1, current_x = 1;

	for (int cnt = 0; cnt < item.size(); cnt++) {
		int des_y = item[cnt].y;
		int des_x = item[cnt].x;

		for (int i = current_y; i <= des_y; i++) {
			for (int j = current_x; j <= des_x; j++) {
				if (arr[i][j] == -1)
					dp[i][j] = 0;
				else if (arr[i - 1][j] != -1 && arr[i][j - 1] != -1) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else if (arr[i - 1][j] != -1) {
					dp[i][j] = dp[i - 1][j];
				}
				else if (arr[i][j - 1] != -1)
					dp[i][j] = dp[i][j - 1];
			}
		}

		current_y = des_y;
		current_x = des_x;
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	cout << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}*/

	cout << dp[n][m] << endl;
	return 0;
}