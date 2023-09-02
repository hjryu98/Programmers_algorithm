#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue <pair<int, int>> q;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++) q.push({ i, priorities[i] });

    sort(priorities.begin(), priorities.end());

    while (!q.empty()) {
        int process = q.front().first;
        int pr = q.front().second;

        q.pop();

        if (priorities.back() <= pr) {
            priorities.pop_back();
            answer++;
            if (process == location) return answer;
        }
        else q.push({ process, pr });
    }
}