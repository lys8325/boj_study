#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define SIDE 4

int side_arr[SIDE][2] = { {-1,0},{0,1},{1,0},{0,-1} }; // 상우하좌
// BFS_Q 에는 한 번이라도 파괴를 했는지에 대한 여부, 인덱스, 깊이를 저장
typedef struct BFS_Q {
    int is_crashed_;
    int row_;
    int col_;
}BFS_Q;

int main(){
    int N, M;  scanf("%d %d", &N, &M);
    vector<vector<int>> map(N + 1, vector<int>(M + 1));
    vector<vector<int>> is_visited_crash(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> is_visited_non_crash(N + 1, vector<int>(M + 1, 0));

    for(int n_idx = 1; n_idx <= N; n_idx++)
        for (int m_idx = 1; m_idx <= M; m_idx++)
            scanf("%1d", &map[n_idx][m_idx]);

    BFS_Q start_Q = { 0, 1, 1 };
    int bfs_size = 1;
    int bfs_depth = 0;
    queue<BFS_Q> bfs_queue; bfs_queue.push(start_Q);
    while (true) {
        // go next depth
        if (bfs_size == 0) {
            if (bfs_queue.size() == 0) break;
            bfs_size = bfs_queue.size();
            bfs_depth++;
        }

        BFS_Q front_Q = bfs_queue.front();
        bfs_queue.pop();
        bfs_size--;
        /* printf("%d %d %d\n", front_Q.is_crashed_, front_Q.row_ , front_Q.col_);*/

        // 정답 인덱스이면 그냥 종료
        if (front_Q.row_ == N && front_Q.col_ == M) {
            printf("%d", bfs_depth + 1);
            return 0;
        }

        // 만약에, 이 경로가 crash 를 한 번 했던 녀석이라면 crash 를 했던 map의 값을 살펴본다.
        // 방문 했던 노드에서 부쉈던 경험이 있을때, 값이 더 작거나 같은 요소가 있으면 그냥 넘긴다.
        // crash 를 하지 않은 녀석도 위와 같은 동일한 논리로 진행한다.
        if (front_Q.is_crashed_ == 0) {
            if (is_visited_non_crash.at(front_Q.row_).at(front_Q.col_)) continue;
            else is_visited_non_crash.at(front_Q.row_).at(front_Q.col_) = 1;
        }
        else {
            if (is_visited_crash.at(front_Q.row_).at(front_Q.col_)) continue;
            else is_visited_crash.at(front_Q.row_).at(front_Q.col_) = 1;
        }

        // 현재노드의 4 방향 옆을 살핀다.
        for (int side_idx = 0; side_idx < SIDE; side_idx++) {
            int now_row = front_Q.row_ + side_arr[side_idx][0];
            int now_col = front_Q.col_ + side_arr[side_idx][1];

            // 범위 체크
            if (!(1 <= now_row && now_row <= N)) continue;
            if (!(1 <= now_col && now_col <= M)) continue;

            // 만약, 다음 노드의 부분이 벽이 아니라면 그냥 추가
            if (map.at(now_row).at(now_col) == 0) {
                if (is_visited_non_crash.at(now_row).at(now_col)) continue;
                BFS_Q plus_Q = { front_Q.is_crashed_ , now_row , now_col};
                bfs_queue.push(plus_Q);
            }
                // 만약, 해당 위치가 벽이고 현재의 crash 가 1이 아니면 1로 변경하고 넘긴다.
            else if (front_Q.is_crashed_ == 0) {
                if (is_visited_crash.at(now_row).at(now_col)) continue;
                BFS_Q plus_Q = { 1, now_row , now_col};
                bfs_queue.push(plus_Q);
            }
                // 만약, 해당 위치가 벽이고 현재의 crash 가 1이면 그냥 continue;
            else {
                continue;
            }
        }
    }
    printf("-1");
    return 0;
}


//vector<string> map(1001, "x");
//int n, m;
//int minVal = 1000001;
//int dy[4] = {1, -1, 0, 0};
//int dx[4] = {0, 0, 1, -1};
//bool visit[1001][1001];
//
//void dfs(int y, int x, int curVal, bool used){
//    if(curVal >= minVal){
//        return;
//    }
//
//    if(y == n && x == m){
//        minVal = curVal;
//        return;
//    }
//
//    int nextY, nextX;
//    for(int i=0;i<4;++i){
//        nextY = y + dy[i];
//        nextX = x + dx[i];
//
//        if(
//                1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m
//                && map[nextY][nextX] == '0' && !visit[nextY][nextX]
//        ){
//            visit[nextY][nextX] = true;
//            dfs(nextY, nextX, curVal+1, used);
//            visit[nextY][nextX] = false;
//        }
//
//        if(!used){
//            if(
//                    1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m
//                    && map[nextY][nextX] == '1' && !visit[nextY][nextX]
//                    ){
//                visit[nextY][nextX] = true;
//                dfs(nextY, nextX, curVal+1, true);
//                visit[nextY][nextX] = false;
//            }
//        }
//    }
//}
//
//int main() {
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    string str;
//    cin>>n>>m;
//
//    for(int i=1;i<=n;++i){
//        cin>>str;
//        map[i].append(str);
//    }
//
//    dfs(1, 1, 1, false);
//
//    if(minVal == 1000001){
//        cout<<-1;
//    }else{
//        cout<<minVal;
//    }
//
//    return 0;
//}
