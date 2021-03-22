#include <iostream>
#include <algorithm>
using namespace std;

int hasNum[500000];
int n, m;

int findNum(int targetNum){
    int cnt = 0;
    int left = 0, right = n-1, mid = 0;

    while(left <= right){
        mid = (left + right) / 2;

        if(targetNum > hasNum[mid]){
            left = mid + 1;
        }else if(targetNum < hasNum[mid]){
            right = mid - 1;
        }else{
            break;
        }
    }

    if(targetNum == hasNum[mid]){
        ++cnt;
        for(int i=mid+1;i<n;++i){
            if(targetNum == hasNum[i]){
                ++cnt;
            }else{
                break;
            }
        }

        for(int i=mid-1;i>=0;--i){
            if(targetNum == hasNum[i]){
                ++cnt;
            }else{
                break;
            }
        }
    }

    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>hasNum[i];
    }
    sort(hasNum, hasNum + n);

    cin>>m;
    int targetNum;
    for(int i=0;i<m;++i){
        cin>>targetNum;
        cout<<findNum(targetNum)<<" ";
    }

    return 0;
}
