#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    int remainder =1;
    int index=0;
    int numLen = 0;
    while(remainder > 0){
        remainder = n - (9*pow(10,index));
        if(remainder > 0) {
            numLen += 9*pow(10,index)*(index+1);
            n -= (9 * pow(10, index));
            ++index;
        }
    }
    numLen += n*(index+1);
    if(numLen < k){
        cout<<-1<<endl;
        return 0;
    }

    remainder =1;
    index=0;
    while(remainder > 0){
        remainder = k - (9*pow(10,index))*(index+1);
        if(remainder > 0) {
            k -= (9 * pow(10, index))*(index+1);
        }
        ++index;
    }
    int tmp = k/(index);
    remainder = k%(index);

    int target = pow(10,index-1) + tmp - 1;
    string answer = to_string(target) + to_string(target+1);
    cout<<answer[answer.length()/2+remainder-1]<<endl;

    return 0;
}
