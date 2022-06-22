#include <bits/stdc++.h>
using namespace std;

class Stacks{
    int top1, top2;
    int total_size;
    int *arr;
    
    public:
        //constructor
        Stacks(int size){
            top1=-1;
            top2=size;
            total_size=size;
            arr=new int[size];
        }
        
        int isEmpty1(){
            return top1==-1;
        }
        int isEmpty2(){
            return top2==total_size;
        }
        int isFull(){
            return top1==top2-1;
        }
        
        void push1(int val){
            if(isFull()){
                cout << "Stackoverflow" << "\n";
                return;
            }
            arr[++top1]=val;
        }
        void push2(int val){
            if(isFull()){
                cout << "Stackoverflow" << "\n";
                return;
            }
            arr[--top2]=val;
        }
        
        int pop1(){
            if(isEmpty1()){
                cout << "Stack empty" << "\n";
                return INT_MIN;
            }
            return arr[top1--];
        }
        int pop2(){
            if(isEmpty2()){
                cout << "Stack empty" << "\n";
                return INT_MIN;
            }
            return arr[top2++];
        }
        
        int peek1(){
            if(isEmpty1()){
                cout << "Stack empty" << "\n";
                return INT_MIN;
            }
            return arr[top1];
        }
        int peek2(){
            if(isEmpty2()){
                cout << "Stack empty" << "\n";
                return INT_MIN;
            }
            return arr[top2];
        }
};

int main(){
    int total_size;
    cout << "Enter total size of two stacks: " ;
    cin>>total_size;
    
    Stacks ts(total_size);
    
    cout << "operations:\n\
    1 -> push\n\
    2 -> pop\n\
    3 -> peek\n" ;
    cout << "Enter choices as two numbers\n";
    cout << "the first number represents the stack(1 or 2)\n";
    cout << "and the second number represents the operation(1,2 or 3)\n" ;
    cout << "\nEnter -1 to exit\n";
    
    while(1){
        int a, b;
        cout << "Enter choice: " ;
        cin>>a;
        if(a==-1) break;
        cin>>b;
        
        if(a==1){
            if(b==1){
                int val;
                cout << "Enter value: " ;
                cin>>val;
                ts.push1(val);
            }
            else if(b==2){
                cout << ts.pop1() << "\n";
            }
            else if(b==3){
                cout << ts.peek1() << "\n";
            }
            else{
                cout << "Invalid input!" << "\n";
            }
        }
        else if(a==2){
            if(b==1){
                int val;
                cout << "Enter value: " ;
                cin>>val;
                ts.push2(val);
            }
            else if(b==2){
                cout << ts.pop2() << "\n";
            }
            else if(b==3){
                cout << ts.peek2() << "\n";
            }
            else{
                cout << "Invalid input!" << "\n";
            }
        }
        else{
            cout << "Invalid input!" << "\n";
        }
    }
    return 0;
}