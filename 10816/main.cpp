#include <iostream>
#include <algorithm>
using namespace std;

int hasNum[500000];
int n, m;

int findLeft(int targetNum, int left, int right){
    int index, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(targetNum > hasNum[mid]){
            left = mid + 1;
        }else if(targetNum < hasNum[mid]){
            right = mid - 1;
        }else{
            index = findLeft(targetNum, 0, mid-1);
            if(index == -1){
                return mid;
            }
            return index;
        }
    }

    return -1;
}

int findRight(int targetNum, int left, int right){
    int index, mid ;

    while(left <= right){
        mid = (left + right) / 2;

        if(targetNum > hasNum[mid]){
            left = mid + 1;
        }else if(targetNum < hasNum[mid]){
            right = mid - 1;
        }else {
            index = findRight(targetNum, mid + 1, n - 1);
            if (index == -1) {
                return mid;
            }
            return index;
        }
    }

    return -1;
}

int findNum(int targetNum){
    int left = 0, right = n-1, mid = 0;
    int leftIndex = 1, rightIndex = 0;

    while(left <= right){
        mid = (left + right) / 2;

        if(targetNum > hasNum[mid]){
            left = mid + 1;
        }else if(targetNum < hasNum[mid]){
            right = mid - 1;
        }else{
            leftIndex = findLeft(targetNum, 0, mid);
            rightIndex = findRight(targetNum, mid, n-1);
            break;
        }
    }

    return rightIndex - leftIndex + 1;
}

int main() {
    cin.tie(NULL);
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
