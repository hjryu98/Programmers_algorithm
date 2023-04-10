#include <string>
#include <vector>
#include <map>

using namespace std;
map<char, int> mm; //약관 저장

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int y, m, d; //오늘의 날짜
    y = stoi(today.substr(0, 4));
    m = stoi(today.substr(5, 2));
    d = stoi(today.substr(8, 2));
    int todayv = d + 100 * m + 10000 * y;

    int termsize = terms.size();

    for (int i = 0; i < termsize; i++) {
        int len = terms[i].size();
        char tp = terms[i][0];
        string tmp = "";

        for (int j = 2; j < len; j++) tmp += terms[i][j];

        mm[tp] = stoi(tmp);
    }

    int prisize = privacies.size();

    for (int i = 0; i < prisize; i++) {
        int py = stoi(privacies[i].substr(0, 4));
        int pm = stoi(privacies[i].substr(5, 2));
        int pd = stoi(privacies[i].substr(8, 2));
        char tp = privacies[i][11];

        int curm = pm + mm[tp];
        int curd = pd - 1;
        int cury = py;

        while (curm > 12) {
            curm -= 12;
            cury++;
        }
        int curv = curd + 100 * curm + 10000 * cury;

        if (curv < todayv) answer.push_back(i + 1);

    }

    return answer;
}