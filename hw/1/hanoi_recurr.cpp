#include <bits/stdc++.h>
using namespace std;

int hanoi(int n, char S, char A, char D){
    if( n <= 0 ) return 0;
    if( n == 1){
        cout << "move disc "<< n <<" from " << S << " to " << D << "\n";
    }
    else{
        hanoi(n-1, S, D, A);
        cout << "move disc " << n << " from " << S << " to " << D << "\n";
        hanoi(n-1, A, S, D);
    }
    return pow(2, n) - 1;
}

int main(){
    int n=3;
    int moves;
    //move all discs from tower1 to tower3
    moves = hanoi(n, 's', 'a' , 'd');
    cout << "total moves: " << moves ;
}