//Solution
//- 인접노드로 확장해가며 7개로 구성된 그룹을 만드는 문제, 해당 그룹이 조건을 만족하는 지도 확인해야 함.
//- 특정방향으로 연장되는 것이 아니라 지나온 모든 노드에서 연장하는 방식이라 풀이가 힘들었다.
//- 이론적 접근은 다음과 같다.
//- 1. 각각의 노드를 시작으로 인접노드로 확장을 수행한다.
//- 2. 2개 이상의 노드를 가진 패스에 대해 다음을 수행한다.
//- 2.1. 지나온 모든 노드에 대해 인접노드로 확장을 수행한다.
//- 2.2. 이전에 방문한 패스(같은 노드의 그룹으로 구성된 패스)는 무시한다.
//- 3. 7개의 노드가 모인 패스에 대해 다음을 확인한다.
//- 3.1. 'S'의 갯수가 4 이상이면 answer을 1 증가시킨다.
//- 3.2. 'S'의 갯수가 4 미만이면 answer을 증가시키지 않는다.
//- 4. 3.에서 구한 가질 수 있는 모든 그룹의 수 answer를 출력한다.
//- Failed 1 : DFS, BFS식 접근으론 해결할 수 없다.
//- 1. 지나온 모든 노드에 대해 확장해야 결과를 얻을 수 있다.
//- 2. 모든 노드에 대한 체크를 위해 크기 25짜리 배열을 방문체크에 사용했다.
//- 2.1. 2^25 = 33554432B = 32MB 이므로 사용에 문제가 없다. (이 문제의 메모리 제한은 256MB)
//- 2.2. 비트연산을 통해 접근함.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 세팅한다.
//- 1.1. map[][] : 주어진 반 배치
//- 1.2. visitied[y * 5 + x] : (x, y)위치의 방문여부를 체크한다.
//- 1.3. dx[], dy[] : 인접 노드 이동을 위한 배열
//- 1.4. answer : 결과를 저장할 변수
//- 2. 모든 노드에 대해 다음을 한번씩 수행한다.
//- 2.1. 해당 노드(x, y)를 시작으로 하는 expand()함수를 실행한다.
//- 2.1.1. map[y][x] == 'S'일 때, som은 1로 시작한다.
//- 2.1.2. map[y][x] == 'Y'일 때, som은 0으로 시작한다.
//- 2.2. 현재까지 방문한 노드(y * 5 + x)들의 합인 check를 확인하여 다음을 수행한다.
//- 2.2.1. 비트연산을 사용해 N번째(y * 5 + x) 위치의 노드가 연결되어 있는 지 확인한다. visit & 1 << N == true
//- 2.2.2. 2.2.1.에 해당하는 모든 노드에 대해 인접노드로 확장시킨다.
//- 2.2.2.1. 단, 노드의 집합이 이미 확인한 형태와 같으면 수행하지 않는다.
//- 2.2.2.2. 인접노드(nx, ny) 위치의 map[ny][nx] == 'S'인 경우 som을 1 증가시킨다.
//- 2.2.2.3. 인접노드(nx, ny) 위치의 map[ny][nx] == 'Y'인 경우 som을 증가시키지 않는다.
//- 2.3. sum이 7인 경우, 다음을 확인한다.
//- 2.3.1. som이 4 이상인 경우, answer을 1 증가시킨다.
//- 3. answer을 출력한다.

#include <iostream>

using namespace std;

#define N 5

char map[N][N];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
bool visited[1 << N * N];
int answer;

void init() {
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
}

void expand(int sum, int som, int visit) {
    if (sum == 7) {
        if (som > 3) answer += 1;
        return;
    }
    for (int i = 0; i < N * N; i++) {
        if ((visit & (1 << i)) == 0) continue;      // 방문한 패스(1) 찾아서 연장
        int x = i / N;
        int y = i % N;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int n_locate = nx * N + ny;
            int n_visit = visit | (1 << n_locate);

            if (visited[n_visit]) continue;         // 기방문(true) 체크
            visited[visit | (1 << n_locate)] = true;

            if (map[nx][ny] == 'S') expand(sum + 1, som + 1, n_visit);
            if (map[nx][ny] == 'Y') expand(sum + 1, som, n_visit);
        }
    }
}

void solution() {
    init();

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            visited[1 << (y * N + x)] = true;
            if (map[y][x] == 'S') expand(1, 1, 1 << (y * N + x));
            else expand(1, 0, 1 << (y * N + x));
        }
    }

    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}