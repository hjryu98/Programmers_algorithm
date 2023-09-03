#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    //1
    for (int i = 0; i < new_id.size(); i++) new_id[i] = tolower(new_id[i]);

    //2
    for (int i = 0; i < new_id.size(); i++) {
        char cur = new_id[i];

        if ((cur >= 'a' && cur <= 'z') || (cur >= '0' && cur <= '9') || cur == '-' || cur == '_' || cur == '.') answer += cur;
    }

    //3
    string tmp = "";
    int dot_cnt = 0;
    for (int i = 0; i < answer.size(); i++) {
        char cur = answer[i];
        if (cur != '.') {
            if (dot_cnt >= 2) {
                tmp += '.';
                dot_cnt = 0;
            }
            else if (dot_cnt == 1) {
                tmp += '.';
                dot_cnt = 0;
            }
            tmp += cur;
        }
        else {
            dot_cnt++;
        }
    }
    answer.clear();
    answer = tmp;
    tmp.clear();
    //4
    int size = answer.size();
    for (int i = 0; i < size; i++) {
        if (i == 0 || i == size - 1) {
            if (answer[i] == '.') continue;
        }
        tmp += answer[i];
    }
    //5
    if (tmp.empty()) tmp += 'a';

    //6
    answer.clear();
    if (tmp.size() >= 16) {
        for (int i = 0; i < 15; i++) {
            if (i == 14) {
                if (tmp[i] == '.') break;
            }
            answer += tmp[i];
        }
    }
    else answer = tmp;

    //7
    char cur = answer[answer.size() - 1];
    while (answer.size() <= 2) {
        answer += cur;
    }

    return answer;
}