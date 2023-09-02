#include <string>
#include <vector>

using namespace std;
int discount[] = { 10, 20, 30, 40 };
int res[10];

void recur(int x, int m, vector<vector<int>>& users, vector<int>& emoticons, vector<int>& answer) {
    if (x >= m) {
        int emoticon_plus = 0;
        int money = 0;
        vector <int> prices;

        for (int i = 0; i < emoticons.size(); i++) {
            prices.push_back(emoticons[i] * (100 - res[i]) / 100);
        }

        for (int i = 0; i < users.size(); i++) {
            int disc = users[i][0]; //이것 이상의 임티 모두 구매
            int value = users[i][1]; //구매 비용이 이것 이상이면 임티 플러스 구매
            int sum = 0;

            for (int j = 0; j < emoticons.size(); j++) {
                if (disc <= res[j]) {
                    sum += prices[j];
                }
            }

            if (sum >= value) emoticon_plus++;
            else money += sum;
        }
        if (answer[0] < emoticon_plus) {
            answer.pop_back();
            answer.pop_back();
            answer.push_back(emoticon_plus);
            answer.push_back(money);
        }
        else if (answer[0] == emoticon_plus) {
            if (answer[1] < money) {
                answer.pop_back();
                answer.push_back(money);
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        res[x] = discount[i];
        recur(x + 1, m, users, emoticons, answer);
        res[x] = 0;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    recur(0, emoticons.size(), users, emoticons, answer);

    return answer;
}