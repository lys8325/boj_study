#include <iostream>
#include <string>
using namespace std;

int main() {
    string dial;
    string target;
    int t;
    t=0;
    cin>>dial;
    for(int i=dial.length()-1;i>=0;--i){
        target = dial.substr(i,1);
        switch(target[0]){
            case 'A' :
            case 'B' :
            case 'C' :
                t += 3;
                break;
            case 'D' :
            case 'E' :
            case 'F' :
                t += 4;
                break;
            case 'G' :
            case 'H' :
            case 'I' :
                t += 5;
                break;
            case 'J' :
            case 'K' :
            case 'L' :
                t += 6;
                break;
            case 'M' :
            case 'N' :
            case 'O' :
                t += 7;
                break;
            case 'P' :
            case 'Q' :
            case 'R' :
            case 'S' :
                t += 8;
                break;
            case 'T' :
            case 'U' :
            case 'V' :
                t += 9;
                break;
            case 'W' :
            case 'X' :
            case 'Y' :
            case 'Z' :
                t += 10;
                break;

            default:
                t += 0;
                break;
        }
    }
    cout<<t<<endl;
}