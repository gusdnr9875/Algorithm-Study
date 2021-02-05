//Solution
//- 3가지 이동에 대해 BFS를 확장시키며 도착을 체크하는 문제
//- 이론적 접근은 다음과 같다.
//- 1. 이동은 3가지로 시간이 0, 1로 다르게 추가된다.
//- 2. 시간의 오름차순으로 확장을 수행해야 한다.
//- 3. priority_queue를 사용하여 BFS를 한다.
//- 4. time의 오름차순으로 수행되므로 B가 일치하는 순간 값을 출력한다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 선언한다.
//- 1.1. visited : 방문을 체크할 배열
//- 1.2. pq : 시간의 오름차순, index의 오름차순으로 정렬된 우선순위 큐
//- 2. BFS()를 수행하며 도착지를 찾는다.
//- 2.1. 처음에는 (A, 0)으로 시작한다.
//- 2.2. B와 일치하면 time을 출력하고 반복을 종료한다.
//- 2.3. 방문하지 않은 경우, 방문에 체크하고 3가지 이동에 대해 pq에 추가한다.
//- 2.4. 다음 성분으로 2.2.단계를 반복한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N_MAX 100001

typedef struct NDOE {
    int step;
    int time;
} NODE;
bool operator <(NODE a, NODE b) {
    if (a.time == b.time) return a.step > b.step;
    return a.time > b.time;
}

int A, B;
bool visited[N_MAX];

void init() {
    cin >> A >> B;
}

int bfs() {
    priority_queue<NODE> pq;

    pq.push({ A, 0 });
    visited[A] = true;

    NODE temp;
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();

        if (temp.step == B) return temp.time;

        if (temp.step * 2 < N_MAX && !visited[temp.step * 2]) {
            pq.push({ temp.step * 2, temp.time });
            visited[temp.step * 2] = true;
        }

        if (temp.step + 1 < N_MAX && !visited[temp.step + 1]) {
            pq.push({ temp.step + 1,temp.time + 1 });
            visited[temp.step + 1] = true;
        }

        if (temp.step - 1 >= 0 && !visited[temp.step - 1]) {
            pq.push({ temp.step - 1,temp.time + 1 });
            visited[temp.step - 1] = true;
        }
    }
}

void solution() {
    init();
    cout << bfs() << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}