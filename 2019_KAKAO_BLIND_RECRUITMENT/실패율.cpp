#include <string>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;
ll arr[510][2];

bool comp(int a, int b) {
    ll A = arr[a][1] * arr[b][0];
    ll B = arr[b][1] * arr[a][0];

    if (A == B) return a < b;
    else return A > B;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int size = stages.size();

    for (int i = 0; i < size; i++) {
        int cur = stages[i];
        arr[cur][1]++;
    }

    for (int i = 1; i <= N; i++) {
        arr[i][0] = size - arr[i - 1][1];
        size -= arr[i - 1][1];
    }

    for (int i = 1; i <= N; i++) answer.push_back(i);
    sort(answer.begin(), answer.end(), comp);


    return answer;
}