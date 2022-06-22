#include <bits/stdc++.h>

using namespace std;

void output(char from, char to, int disk);
void movedisc(stack<int> &src, stack<int> &dest, char s, char d);
void hanoi(int n, stack<int> &src, stack<int> &aux, stack<int> &dest);

void output(char from, char to, int disk){
    cout <<"Move the disk " << disk <<" from " << from << " to "<< to << endl;
}

void movedisc(stack<int> &src, stack<int> &dest, char s, char d){
    int tower1TopDisk = src.top(); src.pop();
    int tower2TopDisk = dest.top(); dest.pop();
 
    // When tower 1 is empty
    if (tower1TopDisk == -1){
        src.push(tower2TopDisk);
        output(d, s, tower2TopDisk);
    }
 
    // When tower2 tower is empty
    else if (tower2TopDisk == -1){
        dest.push(tower1TopDisk);
        output(s, d, tower1TopDisk);
    }
 
    // When top disk of tower1 > top disk of tower2
    else if (tower1TopDisk > tower2TopDisk){
        src.push(tower1TopDisk);
        src.push(tower2TopDisk);
        output(d, s, tower2TopDisk);
    }
 
    // When top disk of tower1 < top disk of tower2
    else{
        dest.push(tower2TopDisk);
        dest.push(tower1TopDisk);
        output(s, d, tower1TopDisk);
    }
}

void hanoi(int n, stack<int> &src, stack<int> &aux, stack<int> &dest){
    int moves = pow(2, n)-1;
    char s='s', a='a', d='d';
    if(n%2==0){
        swap(a, d);
    }
    
    cout << "total moves required: " << moves << "\n";
    
    for(int i=1; i <= moves; i++){
        if(i%3==1){
            movedisc(src, dest, s, d);
        }
        else if(i%3==2){
            movedisc(src, aux, s, a);
        }
        else{
            movedisc(aux, dest, a, d);
        }
    }
}

int main(){
    //number of discs
    int n = 4;
    
    stack<int> src;
    stack<int> aux;
    stack<int> dest;
    for(int i=n; i >= 1; i--){
        src.push(i);
        aux.push(-1);
        dest.push(-1);
    }
    hanoi(n, src, aux, dest);
}