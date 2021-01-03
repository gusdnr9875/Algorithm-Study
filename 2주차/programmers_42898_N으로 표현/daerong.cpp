#include <string>
#include <vector>

#define CNT_MAX 8

using namespace std;

vector<int> uds[CNT_MAX + 1];

int expand(int number) {
    for (int i = 1; i <= CNT_MAX; i++) {
        int J = uds[i].size();
        for (int j = 0; j < J; j++) {
            if (uds[i][j] == number) return i;
            for (int ii = i + 1; ii + i <= CNT_MAX; ii++) {
                int JJ = uds[ii].size();
                for (int jj = 0; jj < JJ; jj++) {
                    uds[ii + i].push_back(uds[i][j] + uds[ii][jj]);
                    if (abs(uds[i][j] - uds[ii][jj])) uds[ii + i].push_back(abs(uds[i][j] - uds[ii][jj]));
                    uds[ii + i].push_back(uds[i][j] * uds[ii][jj]);
                    if (uds[i][j] / uds[ii][jj]) uds[ii + i].push_back(uds[i][j] / uds[ii][jj]);
                    else uds[ii + i].push_back(uds[ii][jj] / uds[i][j]);
                }
            }
        }
    }

    return -1;
}

int solution(int N, int number) {
    uds[2].push_back(1);
    int temp = N;
    int temp2 = N;
    uds[1].push_back(temp);
    for (int i = 2; i <= CNT_MAX; i++) {
        temp = temp * 10 + N;
        temp2 = temp2 * N;
        uds[i].push_back(temp);
        uds[i].push_back(temp2);
    }

    int answer = expand(number);
    return answer;
}