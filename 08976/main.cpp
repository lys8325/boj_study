#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int main()
{
    vector<string> board;
    vector<pair<int, int>> candidate;

    for(int i=0;i<8;++i){
        string str;
        cin>>str;
        board.push_back(str);
    }

    int tmpY, tmpX, answer = -1;
    for(int row=0;row<8;++row){
        for(int col=0;col<8;++col){
            if(board[row][col] == 'W'){
                for(int idx=0;idx<8;++idx){
                    tmpY = row + dy[idx];
                    tmpX = col + dx[idx];

                    if(0 <= tmpY && tmpY < 8 && 0 <= tmpX && tmpX < 8 && board[tmpY][tmpX] == '.'){
                        candidate.push_back({tmpY, tmpX});
                    }
                }
            }
        }
    }

    int candiSize = candidate.size();
    for(int idx=0;idx<candiSize;++idx){
        int targetY = candidate[idx].first;
        int targetX = candidate[idx].second;
        int tmpSum = 0;

        for(int d=0;d<8;++d){
            int nextY = targetY + dy[d];
            int nextX = targetX + dx[d];

            if(0 > nextY || nextY >= 8 || 0 > nextX || nextX >= 8){
                continue;
            }

            int cnt = 0;
            while(board[nextY][nextX] == 'W'){
                ++cnt;
                nextY = nextY + dy[d];
                nextX = nextX + dx[d];

                if(0 > nextY || nextY >= 8 || 0 > nextX || nextX >= 8 || (board[nextY][nextX] == '.')){
                    break;
                }

                if(board[nextY][nextX] == 'B'){
                    tmpSum += cnt;
                    break;
                }
            }
        }

        answer = max(answer, tmpSum);
    }

    cout<<answer;
    return 0;
}
