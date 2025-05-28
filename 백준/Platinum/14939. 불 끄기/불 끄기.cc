#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int N = 10;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, -1, 1, 0, 0};

// 격자 범위 체크
bool inRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

// 불을 토글(반전)하는 함수
void toggle(vector<vector<bool>>& board, int x, int y) {
    for (int dir = 0; dir < 5; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (inRange(nx, ny)) {
            board[nx][ny] = !board[nx][ny];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<bool>> original(N, vector<bool>(N));
    
    // 입력
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < N; ++j) {
            original[i][j] = (row[j] == 'O'); // O: true, #: false
        }
    }

    int min_clicks = 1e9;

    // 첫 줄에서 누를 스위치 조합 (0 ~ 2^10-1)
    for (int bit = 0; bit < (1 << N); ++bit) {
        vector<vector<bool>> board = original;
        int clicks = 0;

        // 첫 번째 줄 스위치 누르기
        for (int j = 0; j < N; ++j) {
            if (bit & (1 << j)) {
                toggle(board, 0, j);
                ++clicks;
            }
        }

        // 아래 줄들 처리
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i - 1][j]) {
                    toggle(board, i, j);
                    ++clicks;
                }
            }
        }

        // 마지막 줄 모두 꺼졌는지 확인
        bool all_off = true;
        for (int j = 0; j < N; ++j) {
            if (board[N - 1][j]) {
                all_off = false;
                break;
            }
        }

        if (all_off) {
            min_clicks = min(min_clicks, clicks);
        }
    }

    // 출력
    cout << (min_clicks == 1e9 ? -1 : min_clicks) << '\n';
    return 0;
}
