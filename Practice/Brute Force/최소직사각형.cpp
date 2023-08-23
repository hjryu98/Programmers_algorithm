#include <string>
#include <vector>

using namespace std;

int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int min(int a, int b) {
    if (a >= b) return b;
    else return a;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int mxw = 0, mxh = 0; //최대 가로, 세로
    int mxlong = 0; // 모든 길이 중 제일 긴 것
    int mxhlong = 0; // 나머지 길이가 될 것

    mxw = sizes[0][0], mxh = sizes[0][1];

    if (sizes.size() == 1) return mxw * mxh;

    for (int i = 1; i < sizes.size(); i++) {
        mxw = max(mxw, sizes[i][0]);
        mxh = max(mxh, sizes[i][1]);
    }
    mxlong = max(mxw, mxh);

    for (int i = 0; i < sizes.size(); i++) {
        int ret = min(sizes[i][0], sizes[i][1]);
        mxhlong = max(mxhlong, ret);
    }

    answer = mxlong * mxhlong;

    return answer;
}