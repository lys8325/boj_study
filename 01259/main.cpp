#include <iostream>
using namespace std;

int main() {
    string num;
    int left, right;
    bool isPal;

    while(1){
        cin>>num;
        if(num == "0"){
            return 0;
        }

        left = 0;
        right = num.length()-1;
        isPal = true;

        while(left <= right){
            if(num[left] != num[right]){
                isPal = false;
                break;
            }
            ++left, --right;
        }

        if(isPal){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
}
