#include <iostream>
using namespace std;
int n, x, y;
int arr[26] = { 0, };
bool checked[25] = { 0, };
int result = 0;

void dfs(int cur) {
	if (cur == n*2) {
		result++;
		return;
	}
	if (arr[cur] == 0) {

		for (int i = 1; i <= n; i++) {
			if (checked[i] == 0) {
				if (cur + i + 1 <= 2 * n && !arr[cur+i+1]) {
					checked[i] = 1;
					arr[cur] = i;
					arr[cur + i + 1] = i;
					dfs(cur + 1);
					checked[i] = 0;
					arr[cur] = 0;
					arr[cur + i + 1] = 0;
				}
			}
		}
	}
	else
		dfs(cur + 1);
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> x >> y;
	
	arr[y] = y - x - 1;
	arr[x] = y - x - 1;
	checked[y - x - 1] = 1;
	dfs(1);
	cout << result << endl;
	return 0;
}