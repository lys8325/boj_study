#include <iostream>
#include <string>
using namespace std;

char video[64][64];

string divide(int y, int x, int n){
    string str;
    bool isComplete = true;

    char target = video[y][x];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(video[y+i][x+j] != target){
                isComplete = false;
                break;
            }
        }
    }

    if(isComplete){
        str.push_back(target);
        return str;
    }

    str.append("(");
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            str.append(divide((y+i*n/2), (x+j*n/2), n/2));
        }
    }
    str.append(")");
    return str;
}

int main() {
    int n;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>video[i];
    }

    string ans = divide(0,0,n);
    cout<<ans;
    return 0;
}
