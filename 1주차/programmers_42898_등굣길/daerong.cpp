#include <string>
#include <vector>

#define MAP_MAX 101

using namespace std;

bool wet[MAP_MAX][MAP_MAX];
int map[MAP_MAX][MAP_MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    long long answer = 0;

    for (int y = 0; y <= n; y++) {
        for (int x = 0; x <= m; x++) {
            map[y][x] = 0;
            wet[y][x] = false;
        }
    }

    vector<int> temp;
    while (!puddles.empty()) {
        temp = puddles.back();
        puddles.pop_back();
        wet[temp[1]][temp[0]] = true;
    }

    map[1][1] = 1;
    for (int x = 2; x <= m; x++) {
        if (wet[1][x]) continue;
        map[1][x] = map[1][x - 1];
    }
    for (int y = 2; y <= n; y++) {
        if (wet[y][1]) continue;
        map[y][1] = map[y - 1][1];
    }

    for (int y = 2; y <= n; y++) {
        for (int x = 2; x <= m; x++) {
            if (wet[y][x]) continue;
            map[y][x] = (map[y - 1][x] + map[y][x - 1]) % 1000000007;
        }
    }

    return map[n][m];
}