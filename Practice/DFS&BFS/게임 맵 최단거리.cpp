#include<vector>
#include <queue>
#include <algorithm>
using namespace std;
queue <pair<int, int>> q;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool check[105][105];

bool range(int x, int y, int n, int m) {
    return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    check[0][0] = true;
    q.push({ 0,0 });

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int cx = q.front().first;
            int cy = q.front().second;

            q.pop();

            if (cx == maps.size() - 1 && cy == maps[0].size() - 1) return answer;

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (!range(nx, ny, maps.size(), maps[0].size())) continue;

                if (check[nx][ny]) continue;

                if (maps[nx][ny] == 0) continue;

                check[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
        answer++;
    }

    return -1;
}