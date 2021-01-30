//문제: 다리만들기2 (골드3)
//알고리즘: 크루스칼 MST
//푼날짜: 2021-01-27


#define x first
#define y second
#define all(v) v.begin(), v.end()
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

using namespace std;

typedef pair<int, int> p;

struct Edge {
	int s, e, x;
	Edge() {}
	Edge(int s, int e, int x) : s(s), e(e), x(x) {}
	bool operator < (const Edge& t) const {
		return x < t.x;
	}
};

const int di[] = { 1, -1, 0, 0 };
const int dj[] = { 0, 0, 1, -1 };

int n, m;
int inp[11][11];
int arr[11][11];
vector<Edge> edge;
vector<p> v[11];

bool bound(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void bfs(int i, int j, int k) {
	queue<p> q; q.push({ i, j });
	arr[i][j] = k;
	v[k].push_back({ i, j });
	while (q.size()) {
		i = q.front().x;
		j = q.front().y;
		q.pop();
		for (int x = 0; x < 4; x++) {
			int ii = i + di[x];
			int jj = j + dj[x];
			if (!bound(ii, jj)) continue;
			if (!inp[ii][jj] || arr[ii][jj]) continue;
			arr[ii][jj] = k;
			v[k].push_back({ ii, jj });
			q.push({ ii, jj });
		}
	}
}

void f(int i, int j, int dir) {
	int s = arr[i][j];
	int cnt = 0;
	while (1) {
		i += di[dir];
		j += dj[dir];
		cnt++;
		if (!bound(i, j) || arr[i][j] == s) break;
		if (!arr[i][j]) continue;
		if (cnt - 1 != 1) edge.push_back({ s, arr[i][j], cnt - 1 });
		break;
	}
}

int par[11];



//부모를 얻는다.
int findParent(int x) {
	if (par[x] == x) return x;
	return par[x] = findParent(par[x]);
}

//부모를 합친다
void unionParent(int a, int b) {
	a = findParent(a); b = findParent(b);
	if (a < b) par[b] = a;
	else par[a] = b;
}

//같은 부모를 가지는지 확인
int isSameParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return 1; //부모가 같음
	else return 0; //부모가 다름
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int pv = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> inp[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!arr[i][j] && inp[i][j]) bfs(i, j, ++pv);

	for (int i = 0; i < pv; i++) {
		for (auto t : v[i]) {
			for (int d = 0; d < 4; d++) f(t.x, t.y, d);
		}
	}

	sort(all(edge));
	int ans = 0, cnt = 0;
	for (int i = 0; i < 7; i++) par[i] = i;
	for (auto i : edge) {
		int s = i.s, e = i.e, x = i.x;
		if (!isSameParent(s, e)) {
			ans += x, cnt++;
			unionParent(s, e);
		}
	}
	if (cnt != pv - 1) cout << -1;
	else cout << ans;
}