#include <iostream>
#include <string>

using namespace std;
int main() {
    string seat;
    int num,cup,ans,index;
    cin>>num>>seat;

    cup = num + 1;
    index = seat.find("LL");
    while(index != -1){
        --cup;
        index = seat.find("LL",index+2);
    }
    if(num >= cup){
        ans = cup;
    } else{
        ans = num;
    }
    cout<<ans;
    return 0;
}