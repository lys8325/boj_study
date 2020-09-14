#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define maxN 1000
#define maxM 1000
using namespace std;

int main() {
    int n, m, vSize, groupNum, groupLen, targetGroup;
    int initMap[maxN][maxM];
    int groupMap[maxN][maxM]={0};
    int dy[4]={-1,1,0,0};
    int dx[4]={0,0,1,-1};
    vector<pair<int,int>> v;
    vector<pair<int,int>> v2;
    queue<pair<int,int>> q;
    map<int,int> zeroNum;
    set<int> checkList;
    vector<int> answerList;

    cin>>n>>m;

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%1d", &initMap[i][j]);
            if(initMap[i][j] == 0){
                v.push_back(make_pair(i,j));
            }else{
                v2.push_back(make_pair(i,j));
                groupMap[i][j] = 1;
            }
        }
    }

    vSize = v.size();
    groupNum = 2;
    int y,x,answer,tmpY,tmpX,targetY,targetX;
    for(int i=0;i<vSize;++i){
        targetY = v[i].first;
        targetX = v[i].second;
        if(groupMap[targetY][targetX] == 0){
            q.push(make_pair(targetY,targetX));
            groupMap[targetY][targetX] = groupNum;
            groupLen = 1;
        }else{
            continue;
        }
        while(!q.empty()){
            y = q.front().first;
            x = q.front().second;
            for(int j=0;j<4;++j){
                tmpY = y + dy[j];
                tmpX = x + dx[j];
                if(tmpY >= n || tmpY < 0|| tmpX >= m || tmpX < 0){
                    continue;
                }else{
                    if(groupMap[tmpY][tmpX] == 0){
                        ++groupLen;
                        groupMap[tmpY][tmpX] = groupNum;
                        q.push(make_pair(tmpY,tmpX));
                    }
                }
            }
            q.pop();
        }
        zeroNum[groupNum] = groupLen;
        ++groupNum;
    }

    vSize = v2.size();
    for(int i=0;i<vSize;++i){
        y = v2[i].first;
        x = v2[i].second;
        answer = 1;
        for(int j=0;j<4;++j){
            tmpY = y + dy[j];
            tmpX = x + dx[j];
            if(tmpY >= n || tmpY < 0|| tmpX >= m|| tmpX < 0){
                continue;
            }else{
                if(groupMap[tmpY][tmpX] == 1){
                    continue;
                }
                targetGroup = groupMap[tmpY][tmpX];
                checkList.insert(targetGroup);
            }
        }
        for(auto j : checkList){
            answer += zeroNum[j];
        }
        initMap[y][x] = answer % 10;
        checkList.clear();
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<initMap[i][j];
        }
        cout<<endl;
    }

    return 0;
}
