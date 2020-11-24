#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct node{
    int level;
    vector<int> child;
};

bool visit[100001];
int parent[100001][18];
vector<node> v(100001);

void dfs(int node, int lev){
    visit[node] = true;
    v[node].level = lev;

    for(int nextNode : v[node].child){
        if(visit[nextNode]){
            continue;
        }
        parent[nextNode][0] = node;
        dfs(nextNode, lev+1);
    }
}

int lca(int node1, int node2){
    if(v[node1].level != v[node2].level){
        if(v[node1].level < v[node2].level){
            int tmp = node1;
            node1 = node2;
            node2 = tmp;
        }

        for(int i=17;i>=0;--i){
            if(v[node1].level-v[node2].level >= (1 << i)){
                node1 = parent[node1][i];
            }
        }
    }

    if(node1 == node2){
        return node1;
    }

    for(int i=17;i>=0;--i){
        if(parent[node1][i] != parent[node2][i]){
            node1 = parent[node1][i];
            node2 = parent[node2][i];
        }
    }

    return parent[node1][0];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, q, p, c, node1, node2;

    cin>>n;
    for(int i=1;i<n;++i) {
        cin >> p >> c;
        v[p].child.push_back(c);
        v[c].child.push_back(p);
    }

    dfs(1, 0);

    for(int j=1;j<=17;++j){
        for(int i=1;i<=n;++i){
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    cin>>q;
    for(int i=0;i<q;++i){
        cin>>node1>>node2;
        cout<<lca(node1, node2)<<"\n";
    }

    return 0;
}
