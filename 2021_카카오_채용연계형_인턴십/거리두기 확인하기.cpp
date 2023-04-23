#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
bool check[6][6];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue <pair<int, int>> q;
bool range(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}
void init() {
    memset(check, false, sizeof(check));
    while (!q.empty()) q.pop();
}

bool bfs(int x, int y, vector<string> v) {

    check[x][y] = true;
    q.push({ x, y });
    int dist = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int cx = q.front().first;
            int cy = q.front().second;

            q.pop();

            if (v[cx][cy] == 'P' && dist < 3 && dist > 0) return false;

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (!range(nx, ny)) continue;

                if (v[nx][ny] == 'X') continue;

                if (check[nx][ny]) continue;

                check[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
        dist++;
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {
        bool flag = true;

        for (int j = 0; j < places[i].size(); j++) {
            for (int k = 0; k < 5; k++) {
                init();
                if (places[i][j][k] == 'P') {
                    if (!bfs(j, k, places[i])) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) break;
        }

        if (!flag) answer.push_back(0);
        else answer.push_back(1);
    }

    return answer;
} 
