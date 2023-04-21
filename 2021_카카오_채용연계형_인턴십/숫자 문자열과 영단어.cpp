#include <string>
#include <vector>
#include <map>

using namespace std;
map <string, int> m;
int solution(string s) {
    int answer = 0;
    int len = s.size();

    m.insert({ "one", 1 });
    m.insert({ "two", 2 });
    m.insert({ "three", 3 });
    m.insert({ "four", 4 });
    m.insert({ "five", 5 });
    m.insert({ "six", 6 });
    m.insert({ "seven", 7 });
    m.insert({ "eight", 8 });
    m.insert({ "nine", 9 });
    m.insert({ "zero", 0 });

    string tmp = "";
    for (int i = 0; i < len; i++) {
        char cur = s[i];

        if (cur >= '0' && cur <= '9') answer = (cur - '0') + 10 * answer;

        else {
            tmp += cur;

            if (m.count(tmp)) {
                answer = m[tmp] + 10 * answer;
                tmp.clear();
            }

        }
    }

    return answer;
}