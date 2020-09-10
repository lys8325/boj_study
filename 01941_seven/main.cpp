#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
char girls[5][5];
bool visit[5][5] = {false};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int countY = 0;
int countS = 0;
int answer = 0;
set<vector<pair<int,int>>> group;
vector<pair<int,int>> seven;

void dfs(int y,int x,int level){
    int tmpY = y;
    int tmpX = x;
    bool isY = false;

    if(level == 7){ // 완성이면 종료
        return;
    }
    if((y<0)||(y>4)||(x<0)||(x>4)){ // 바운더리 체크
        return;
    }

    if(!visit[y][x]){ // 방문안했음 진행
        seven.push_back(make_pair(y,x));
        visit[y][x] = true;
        if(girls[y][x] == 'Y'){
            ++countY;
            if(countY>=4){
                --countY;
                seven.pop_back();
                visit[y][x] = false;
                return;
            }
            isY = true;
        }else{
            ++countS;
        }
        if((countS + countY) == 7){
            vector<pair<int,int>> temp;
            temp = seven;
            sort(temp.begin(),temp.end());
            if(group.find(temp) == group.end()){
                ++answer;
                group.insert(temp);
            }
            if(isY){
                --countY;
            }else{
                --countS;
            }
            seven.pop_back();
            visit[y][x] = false;
            return;
        }
    }else{ // 방문 했음 종료
        return;
    }
    for(int j=0;j<seven.size();++j){
        for(int i=0;i<4;++i){
            tmpY = seven[j].first + dy[i];
            tmpX = seven[j].second + dx[i];
            dfs(tmpY,tmpX,level+1);
        }
    }

    if(isY){
        --countY;
    }else{
        --countS;
    }
    visit[y][x] = false;
    seven.pop_back();
}

int main() {
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            cin>>girls[i][j];
        }
    }
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            dfs(i,j,0);
        }
    }
    cout<<answer<<endl;
    return 0;
}
