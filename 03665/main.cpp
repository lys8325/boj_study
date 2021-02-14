#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N_MAX = 500;

int t, n, m;
int indegree[N_MAX + 1];
bool edges[N_MAX + 1][N_MAX + 1];

int main(){
    scanf("%d", &t);
    while(t--){
        memset(indegree, 0, sizeof(indegree));
        memset(edges, false, sizeof(edges));
        scanf("%d", &n);
        vector<int> v;
        for (int i = 0; i < n; i++){
            int x; scanf("%d", &x);
            for (auto y: v){
                edges[x][y] = true;
                indegree[y] += 1;
            }
            v.push_back(x);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            if (edges[a][b]){
                edges[a][b] = false;
                indegree[b] -= 1;
                edges[b][a] = true;
                indegree[a] += 1;
            }
            else if (edges[b][a]){
                edges[b][a] = false;
                indegree[a] -= 1;
                edges[a][b] = true;
                indegree[b] += 1;
            }
        }

        // Topological Sort
        queue<int> q;

        bool isVague = false;

        for (int i = 1; i <= n; i++){
            if(!indegree[i]) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            if (q.size() > 1){
                isVague = true;
                break;
            }
            int cur = q.front();
            ans.push_back(cur);
            q.pop();

            for (int next = 1; next <= n; next++){
                if (!edges[cur][next]) continue;
                indegree[next] -= 1;
                if (!indegree[next]){
                    q.push(next);
                }
            }
        }

        if (isVague){
            printf("?\n");
            continue;
        }

        if (ans.size() != n){
            printf("IMPOSSIBLE\n");
            continue;
        }

        reverse(ans.begin(), ans.end());

        for (auto x: ans){
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}
