#include <iostream>
#include <queue>
using namespace std;
int n = 0, k = 0;
int visited[100001] = { 0, };


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	queue <int> que;


	cin >> n >> k;
	que.push(n);
	visited[n] = 1;

	while (!que.empty()) {
		
		int v = que.front();
		que.pop();
		//cout << v << endl;
		for (int j = v; j <= 100000; j *= 2) { // 0초 후에 2*X의 위치로 이동
			if (j == 0) break;
			if (visited[j] == 0) {
				visited[j] = visited[v];
				que.push(j);
			}
		}
		if (visited[v + 1] == 0 && (v+1) <= 100000) {
			visited[v + 1] = visited[v] + 1;
			que.push(v + 1);
		}
		if (visited[v - 1] == 0 && (v-1) >= 0) {
			visited[v - 1] = visited[v] + 1;
			que.push(v - 1);
		}



	}

	cout << visited[k] - 1 << endl;
	return 0;
}