#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num[3];

    while(1){
        cin>>num[0]>>num[1]>>num[2];
        if(num[0] == 0 && num[1] ==0 && num[2]== 0){
            return 0;
        }

        sort(num, num + 3);
        if(num[0]*num[0] + num[1]*num[1] == num[2]*num[2]){
            cout<<"right\n";
        }else{
            cout<<"wrong\n";
        }
    }
    return 0;
}
