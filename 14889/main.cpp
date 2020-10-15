#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int n, minAns = 99999;
int power[20][20];
bool used[20];
vector<int> v1;
vector<int> v2;

int calc(){
   int ans, v1Ans = 0, v2Ans = 0;
   int p1, q1, p2, q2;
   for(int i=0;i<n;++i){
       p1 = v1[i];
       p2 = v2[i];
       for(int j=0;j<n;++j){
           if(i == j){
               continue;
           }
           q1 = v1[j];
           q2 = v2[j];
           v1Ans += power[p1][q1];
           v2Ans += power[p2][q2];
       }
   }

    ans  = abs(v1Ans - v2Ans);
    return ans;
}

void dfs(int cnt, int start){
    if(cnt == n){
        v2.clear();
        for(int i=0;i<2*n;++i){
            if(!used[i]){
                v2.push_back(i);
            }
        }
        minAns = min(minAns, calc());
        return;
    }

    for(int i=start;i<2*n;++i){
        if(!used[i]){
            v1.push_back(i);
            used[i] = true;
            dfs(cnt+1, i+1);
            v1.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>power[i][j];
        }
    }

    n /= 2;
    dfs(0, 0);
    cout<<minAns;
    return 0;
}
