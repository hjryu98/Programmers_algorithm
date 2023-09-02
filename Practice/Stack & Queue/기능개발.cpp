#include <string>
#include <vector>
#include <queue>
using namespace std;
queue <pair<pair<int, int>, int>> q;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for (int i = 0; i < progresses.size(); i++) q.push({ {progresses[i], 0}, i });

    while (!q.empty()) {
        int cnt = 0;
        int val = q.front().first.first;
        int day = q.front().first.second;
        int idx = q.front().second;
        if (val >= 100) {
            while (!q.empty() && q.front().first.first >= 100) {
                q.pop();
                cnt++;
            }
            answer.push_back(cnt);
        }
        else {
            for (int i = 0; i < speeds.size(); i++) {
                if (q.front().second == i) {
                    q.push({ {q.front().first.first + speeds[i], q.front().first.second + 1}, i });
                    q.pop();
                }
            }
        }
    }

    return answer;
}