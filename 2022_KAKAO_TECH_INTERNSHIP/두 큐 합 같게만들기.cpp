#include <string>
#include <vector>
using namespace std;
using ll = long long;
vector <int> v;
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int s = 0;
    int e = queue1.size() - 1;
    ll sum = 0;
    ll sum1 = 0;
    for (int i = 0; i < queue1.size(); i++) {
        sum += queue1[i];
        sum1 += queue1[i];
        v.push_back(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); i++) {
        sum += queue2[i];
        v.push_back(queue2[i]);
    }
    ll trgsum = sum / 2;

    while (s < e && e <= (v.size() - 1)) {
        if (sum1 == trgsum) return answer;

        if (sum1 < trgsum) {
            sum1 += v[++e];
            answer++;
        }
        else if (sum1 > trgsum) {
            sum1 -= v[s++];
            answer++;
        }
    }
    if (trgsum == sum1) return answer;

    return -1;
}