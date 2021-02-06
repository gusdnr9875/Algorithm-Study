#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 0, m = 0, result = 0;
vector <int> vec[101];
bool visited[101] = { 0, };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		vec[t1].push_back(t2);
		vec[t2].push_back(t1);

	}

	queue <int> que;
	visited[1] = 1;
	que.push(1);

	while (!que.empty()) {
		int num = que.front();
		que.pop();

		for (int i = 0; i < vec[num].size(); i++) {
			int next = vec[num][i];
			if (visited[next] == 1) continue;
			que.push(next);
			visited[next] = 1;
			result++;
		}
	}

	cout << result << endl;
	return 0;
}