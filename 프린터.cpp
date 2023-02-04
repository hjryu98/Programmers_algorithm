#include <queue>
#include <vector>
using namespace std;
queue <int> q;
priority_queue <int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(i);
        pq.push(priorities[i]);
    }
    while (!q.empty()) {
        int curl = q.front();

        q.pop();

        if (priorities[curl] != pq.top()) {
            q.push(curl);
        }
        else {
            answer++;
            pq.pop();
            if (curl == location) break;
        }
    }

    return answer;
}