#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long s = 0;
    long long e = (long long)times[times.size() - 1] * n;

    while (s + 1 < e) {
        long long mid = (s + e) / 2;
        long long sum = 0;
        for (int i = 0; i < times.size(); i++) {
            sum += (mid / times[i]);

            if (sum >= n) break;
        }

        if (sum >= n) e = mid;
        else s = mid;
    }

    return e;
}