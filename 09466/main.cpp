#include <iostream>
#include <vector>
using namespace std;
#pragma disable(warning:4996)

void dfs(vector<int>& _num_vec, vector<int>& _group, int _n) {
    int group_num = 1;
    vector<int> is_visited(_n + 1, 0);
    vector<int> visited_node;

    for (int n_idx = 1; n_idx <= _n; n_idx++) {
        // 그룹 번호가 있으면 건너 뛴다.
        if (_group[n_idx] || is_visited[n_idx]) continue;

        visited_node.clear();
        is_visited[n_idx] = 1;
        visited_node.push_back(n_idx);
        int now_node = _num_vec[n_idx];

        // 방문하지 않은 노드이면서 그룹도 지정되어있지 않은 경우에만 갱신을 수행
        while (is_visited[now_node] == 0 && _group[now_node] == 0) {
            is_visited[now_node] = 1;
            visited_node.push_back(now_node);
            now_node = _num_vec[now_node];
        }

        // 순환 끝나고 시작과 끝이 같으면?
        int visited_size = visited_node.size();
        int vis_idx;
        // 순환이 시작되는 부분을 찾는다
        // 만약 순환이 시작되는 부분이 아니면 -1을 넣어주어
        // 그룹을 지을 수 없다는 것을 표시
        for (vis_idx = 0; vis_idx < visited_size; vis_idx++)
            if (visited_node[vis_idx] != now_node) _group[visited_node[vis_idx]] = -1;
            else break;

        for (; vis_idx < visited_size; vis_idx++)
            _group[visited_node[vis_idx]] = group_num;
        group_num++;

    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> num_vec(n+1,0);
        vector<int> group(n+1,0);
        for (int n_idx = 1; n_idx <= n; n_idx++)
            cin >> num_vec[n_idx];

        // dfs 수행
        dfs(num_vec, group, n);

        int answer = 0;
        for (int n_idx = 1; n_idx <= n; n_idx++)
            if (group[n_idx] < 0 ) answer++;

        cout << answer << "\n";
    }
    return 0;
}
