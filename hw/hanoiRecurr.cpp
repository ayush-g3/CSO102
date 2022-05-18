#include <bits/stdc++.h>

using namespace std;

int hanoi(int n, char S, char A, char D, int moves = 0){
    moves = 0;
    if( n <= 0 );
    if( n == 1){
        cout << "move disc from " << S << " to " << D << "\n";
        ++moves;
    }
    else{
        moves += hanoi(n-1, S, D, A, 0);
        cout << "move disc from " << S << " to " << D << "\n";
        ++moves;
        moves += hanoi(n-1, A, S, D, 0);
    }
    return moves;
}

int main(){
    int n=3;
    int moves;
    //move all discs from tower1 to tower3
    moves = hanoi(n, 's', 'a' , 'd');
    cout << moves ;
}