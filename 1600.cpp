#include<iostream>
#include<queue>
#include<climits>

using namespace std;

int walkX[4] = {1, 0, -1, 0}, walkY[4] = {0, -1, 0, 1};
int jumpX[8] = {2, 1, -1,  -2, -2, -1, 1, 2}, jumpY[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int board[202][202] = {0};
int visited[202][202][32] = {0};

bool inside(int x, int y, int W, int H) {
    return (x>=0) && (x<H) && (y>=0) && (y<W);
}

struct kan {
    int x, y, jumpN;

    kan(int xx, int yy, int jumpNN) {
        x = xx;
        y = yy;
        jumpN = jumpNN;
    }
};

int main() {
    int K, W, H;
    bool flag = false;
    int i, j;
    int rcost = INT_MAX;
    queue<kan> q;
    // 우하좌상 순으로 탐색

    cin >> K >> W >> H;
    for(i=0; i<H; i++) {
        for(j=0; j<W; j++) {
            cin >> board[i][j];
        }
    }

    q.push(kan(0, 0, 0));

    visited[0][0][0] = 0;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        if(cur.x == H-1 && cur.y == W-1) {
            flag = true;
            if(W == 1 && H == 1) {
                rcost = 0;
                break;
            }
            for(i=0; i<31; i++) {
                if(visited[cur.x][cur.y][i])
                    rcost = min(rcost, visited[cur.x][cur.y][i]);
            }
            break;
        }

        if(cur.jumpN < K) {
            for(i=0; i<8; i++) {
                int nextX = cur.x + jumpX[i];
                int nextY = cur.y + jumpY[i];
                
                if(!inside(nextX, nextY, W, H)) continue;
                if(board[nextX][nextY] == 1 || visited[nextX][nextY][cur.jumpN + 1]) continue;
                q.push(kan(nextX, nextY, cur.jumpN + 1));
                visited[nextX][nextY][cur.jumpN + 1] = visited[cur.x][cur.y][cur.jumpN] +1;
            }
        }

        for(i=0; i<4; i++) {
            int nextX = cur.x + walkX[i];
            int nextY = cur.y + walkY[i];
            
            if(!inside(nextX, nextY, W, H)) continue;
            if(board[nextX][nextY] == 1 || visited[nextX][nextY][cur.jumpN]) continue;

            q.push(kan(nextX, nextY, cur.jumpN));
            visited[nextX][nextY][cur.jumpN] = visited[cur.x][cur.y][cur.jumpN] +1;

        }
    }

    if(!flag) rcost = -1;
    cout << rcost;

    return 0;
}