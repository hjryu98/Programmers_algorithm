#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map <char, int> m;
    int score[] = { 3,2,1,0,1,2,3 };
    int len = survey.size();

    for (int i = 0; i < len; i++) {
        string stype = survey[i];
        char f = survey[i][0];
        char s = survey[i][1];

        int choice = choices[i];

        if (choice >= 5) m[s] += score[choice - 1];
        else if (choice <= 3) m[f] += score[choice - 1];
    }
    if (m['R'] >= m['T']) answer += "R";
    else answer += "T";
    if (m['C'] >= m['F']) answer += "C";
    else answer += "F";
    if (m['J'] >= m['M']) answer += "J";
    else answer += "M";
    if (m['A'] >= m['N']) answer += "A";
    else answer += "N";

    return answer;
}