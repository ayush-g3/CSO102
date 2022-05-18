#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=3;
    int moves = pow(2, n) - 1;
    for(int i=1; i <= moves; i++){
        switch(i%3){
            case 1:
                cout << "move disc from source to destination\n";
                break;
            case 2:
                cout << "move disc from source to auxiliary\n";
                break;
            case 0:
                cout << "move disc from auxiliary to destination\n";
                break;
        }
    }
}