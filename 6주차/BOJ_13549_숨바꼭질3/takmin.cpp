//문제: 숨바꼭질3 (골드 5)
//알고리즘:deque+BFS
//푼날짜 : 2021-02-02
//풀이1. BFS를이용한 최단거리탐색. BFS로풀었을때, 메모리 초과가났다-> BFS최단거리방식으로 구해야한다.
//풀이2. deque를이용한 BFS탐색. 순간이동했을때 시간이 0초이기때문에, deque로 0초일때를 우선순위로 먼저 처리한다.
//ex)0000000111111....
//한번방문한곳이면 다시 탐색할 필요가없기 때문에 visited 사용


//풀이1. Deque를 이용한 BFS
#include<iostream>
#include<deque>
#define MAX 100000
using namespace std;

int n, k;
bool visited[MAX+1];

int BFS() {
	deque<pair<int,int>> q;
	q.push_front({ n,0 });
	visited[n] = true;
	while (!q.empty()) {
		int num = q.front().first;
		int time = q.front().second;
		q.pop_front();
		cout << num << endl;
		if (num == k) return time;
		if (num * 2 <= MAX && !visited[num * 2]) {
			visited[num*2] = true;
			q.push_front({ num * 2,time });
		}


		if (num + 1 <= MAX && !visited[num + 1]) {
			visited[num + 1] = true;
			q.push_back({ num + 1,time + 1 });
		}
	
		


		if (num - 1 <= MAX && !visited[num - 1]) {
			visited[num - 1] = true;
			q.push_back({ num - 1,time + 1 });
		}
	}


	
}
int main() {
	cin >> n >> k;
	cout << BFS();

}


//풀이 2. BFS 최단거리
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;
const int MAX = 100000;
bool visited[MAX + 1];
int dist[MAX + 1];

int main(void)
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	dist[n] = 0;
	visited[n] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now * 2 <= MAX && visited[now * 2] == false) // x * 2로 순간이동 하는 경우
		{
			q.push(now * 2);
			dist[now * 2] = dist[now];
			visited[now * 2] = true;
		}

		if (now - 1 >= 0 && visited[now - 1] == false) // x - 1로 이동하는 경우
		{
			q.push(now - 1);
			dist[now - 1] = dist[now] + 1;
			visited[now - 1] = true;
		}
		if (now + 1 <= MAX && visited[now + 1] == false) // x + 1로 이동하는 경우
		{
			q.push(now + 1);
			dist[now + 1] = dist[now] + 1;
			visited[now + 1] = true;
		}


	}
	cout << dist[k] << '\n';

}