#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int one[] = { 1,2,3,4,5 };
int two[] = { 2,1,2,3,2,4,2,5 };
int thr[] = { 3,3,1,1,2,2,4,4,5,5 };
vector <int> value(3);
vector<int> solution(vector<int> answers) {
    vector<int> answer;

    for (int i = 0; i < answers.size(); i++) {
        int cur = answers[i];
        if (cur == one[i % 5]) value[0]++;
        if (cur == two[i % 8]) value[1]++;
        if (cur == thr[i % 10]) value[2]++;
    }
    /*
    <algorithm>
    max_element(시작점, 끝점(개구간))
    가장 큰 값의 포인터를 반환, 값 출력을 위해 *사용
    */
    int max_val = *max_element(value.begin(), value.end());

    for (int i = 0; i < 3; i++) {
        if (max_val == value[i]) answer.push_back(i + 1);
    }

    return answer;
}