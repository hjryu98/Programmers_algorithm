#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
vector <set<int>> v(1005); //i��° ������ ������ �Ű��ߴ��� ����
map <string, int> m;
map <int, int> reported; //i��° ������ ��� �Ű� ���߳�
vector<int> answer;
void init(int val) {
    for (int i = 0; i < val; i++) answer.push_back(0);
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    for (int i = 0; i < id_list.size(); i++) m[id_list[i]] = i;

    init(id_list.size());

    sort(report.begin(), report.end()); //sort
    report.erase(unique(report.begin(), report.end()), report.end()); //erase repeated string

    for (int i = 0; i < report.size(); i++) {
        int len = report[i].size();
        string tmp = "";
        string who = "";
        for (int j = 0; j < len; j++) {
            if (report[i][j] != ' ') tmp += report[i][j];
            else {
                who = tmp;
                tmp.clear();
            }
        }
        if (!v[m[who]].count(m[tmp])) {
            v[m[who]].insert(m[tmp]);
            reported[m[tmp]]++;
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        for (auto iter = v[i].begin(); iter != v[i].end(); iter++) {
            if (reported[*iter] >= k) answer[i]++;
        }
    }

    return answer;
}