#include <iostream>

using namespace std;

bool check[2000001]={false};
int cc=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,period,time;
    cin>>n>>time;
    for(int i=0;i<n;++i){
        cin>>period;

        for(int j=1;j*period<=time;++j){
            if(check[j*period]==false){
                check[j*period]=true;
                ++cc;
            }
        }
    }
    cout<<cc;
    return 0;
}