#define inf 999999999
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[155][155]; //dp[i][j] : min time to make alg:i, code:j

void init() {
    for (int i = 0; i < 155; i++) {
        for (int j = 0; j < 155; j++) dp[i][j] = inf;
    }
}
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int alp_max = -1;
    int cop_max = -1;

    for (int i = 0; i < problems.size(); i++) {
        alp_max = max(alp_max, problems[i][0]);
        cop_max = max(cop_max, problems[i][1]);
    }

    init();
    alp = min(alp, alp_max);
    cop = min(cop, cop_max);
    dp[alp][cop] = 0;

    for (int i = alp; i <= alp_max; i++) {
        for (int j = cop; j <= cop_max; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

            for (int k = 0; k < problems.size(); k++) {
                int a = problems[k][0];
                int b = problems[k][1];
                int c = problems[k][2];
                int d = problems[k][3];
                int e = problems[k][4];

                if (i < a || j < b) continue;

                int alp_nxt = min(i + c, alp_max);
                int cop_nxt = min(j + d, cop_max);

                dp[alp_nxt][cop_nxt] = min(dp[alp_nxt][cop_nxt], dp[i][j] + e);
            }
        }
    }
    answer = dp[alp_max][cop_max];
    return answer;
}