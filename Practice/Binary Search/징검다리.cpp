#include <string>
#include <vector>
#include <algorithm>
/*
boj 2110 similar
*/
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int s = 0;
    int e = distance + 1;
    sort(rocks.begin(), rocks.end());

    while (s + 1 < e) {
        int mid = (s + e) / 2;
        int deleted = 0;
        int prv = 0;

        for (int i = 0; i < rocks.size(); i++) {
            int dist = rocks[i] - prv;
            if (dist < mid) deleted++;
            else prv = rocks[i];
        }
        if (distance - prv < mid) deleted++;
        else prv = distance;

        if (deleted > n) e = mid;
        else s = mid;
    }

    return s;
}