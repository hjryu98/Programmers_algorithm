#include <string>
#include <vector>

using namespace std;
int answer;
int res[22];
void recur(vector <int> numbers, int target, int cur) {
    if (cur >= numbers.size()) {
        int sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            sum += res[i] * numbers[i];
        }
        if (target == sum) answer++;
        return;
    }

    res[cur] = 1;
    recur(numbers, target, cur + 1);
    res[cur] = -1;
    recur(numbers, target, cur + 1);
    res[cur] = 0;
}

int solution(vector<int> numbers, int target) {
    recur(numbers, target, 0);

    return answer;
}