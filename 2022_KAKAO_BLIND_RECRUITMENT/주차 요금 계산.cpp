#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

set <string> s; // 주차장
map <string, int> m; // 차번호, 이용시간
map <string, string> info;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    for (int i = 0; i < records.size(); i++) {
        string cur = records[i];
        string time_data = cur.substr(0, 5);
        string car_number = cur.substr(6, 4);
        string sign = cur.substr(11, 1);

        if (sign[0] == 'I') {
            s.insert(car_number);
            info[car_number] = time_data;
        }
        else {
            s.erase(car_number);
            int starttime = stoi(info[car_number].substr(0, 2)) * 60 + stoi(info[car_number].substr(3, 2));
            int endtime = stoi(time_data.substr(0, 2)) * 60 + stoi(time_data.substr(3, 2));

            m[car_number] += endtime - starttime;
            info.erase(car_number);
        }
    }
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        string car = *iter;
        int starttime = stoi(info[car].substr(0, 2)) * 60 + stoi(info[car].substr(3, 2));
        int endtime = 23 * 60 + 59;
        m[car] += endtime - starttime;
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        string car = (*iter).first;
        int value = 0;

        if (fees[0] >= m[car]) value = fees[1];
        else {
            value = fees[1] + (int)ceil((m[car] - fees[0]) / (float)fees[2]) * fees[3];
        }
        answer.push_back(value);
    }


    return answer;
}