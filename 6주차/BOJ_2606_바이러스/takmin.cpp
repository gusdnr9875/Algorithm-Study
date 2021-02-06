//문제 :바이러스 (실버 3)
//알고리즘: DFS
//푼 날짜:2021-02-02

#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> graph[101];
bool visited[101];
int cnt;
void DFS(int idx) {
	visited[idx] = true;
	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];
		if (!visited[next]) {
			DFS(next);
			cnt++;
		}
		
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	DFS(1);
	cout << cnt;
}