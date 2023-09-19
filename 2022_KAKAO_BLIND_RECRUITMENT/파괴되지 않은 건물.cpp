#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    int arr[1003][1003] = { 0, };

    for (int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];

        if (type == 1) {
            arr[r1][c1] += -1 * degree;
            arr[r1][c2 + 1] += degree;
            arr[r2 + 1][c1] += degree;
            arr[r2 + 1][c2 + 1] += -1 * degree;
        }
        else {
            arr[r1][c1] += degree;
            arr[r1][c2 + 1] += -1 * degree;
            arr[r2 + 1][c1] += -1 * degree;
            arr[r2 + 1][c2 + 1] += degree;
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            arr[i][j + 1] += arr[i][j];
        }
    }

    for (int i = 0; i < board[0].size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            arr[i + 1][j] += arr[i][j];
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            board[i][j] += arr[i][j];

            if (board[i][j] > 0) answer++;
        }
    }

    return answer;
}