#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int> &v, int target){
    int left = 0;
    int right = v.size();
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(v[mid] == target){
            return 1;
        }

        if(v[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v;
    int n, m, tmp;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>tmp;
        cout<<search(v, tmp)<<"\n";
    }

    return 0;
}
