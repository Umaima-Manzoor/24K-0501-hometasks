#include <iostream>
#include <string>
using namespace std;


class Call {
public:
    string name;
    string number;
    int duration;

    Call() : name(""), number(""), duration(0) {}
    Call(string n, string num, int dur) {
        name = n;
        number = num;
        duration = dur;
    }
};


class Stack {
    Call* arr; 
    int size;
    int top;

public:
    Stack(int n) { 
        size = n;
        arr = new Call[size];
        top = -1;
    }

    void PushStack(const Call& c) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl << endl;
            return;
        }
        arr[++top] = c;
        cout << c.name << " added to call history." << endl << endl;
       
    }

    void PopStack() {
        if (top == -1) {
            cout << "Stack Underflow" << endl << endl;
            return;
        }
        cout << arr[top].name << " removed from call history." << endl << endl;
        top--;
        
    }

    void PeekStack() {
        if (top == -1) {
            cout << "Stack is Empty" << endl << endl;
            return;
        }
        cout << "Most recent call:" << endl;
        cout << "Name: " << arr[top].name << ", Number: " << arr[top].number << ", Duration: " << arr[top].duration << "s" << endl << endl;

    }

    bool IsEmptyStack() {
        return top == -1;
    }


    void DisplayStack() {
        if (top == -1) {
            cout << "Call history is empty." << endl << endl;
            return;
        }
        cout << "Current call history (most recent first):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << i + 1 << ". Name: " << arr[i].name << ", Number: " << arr[i].number << ", Duration: " << arr[i].duration << "s" << endl;
        }
        cout << endl;
    }
};

int main() {
    Stack history(10); 

    history.PushStack(Call("Umaima", "501", 30));
    history.DisplayStack();
    
    history.PushStack(Call("Zubia", "789", 45));
    history.DisplayStack();
    
    history.PeekStack();
    history.DisplayStack();
    
    history.PopStack();
    history.DisplayStack();
    
    history.PushStack(Call("Mirha", "123", 39));
    history.DisplayStack();

    cout << "Is call history empty? " << (history.IsEmptyStack() ? "Yes" : "No")<< endl << endl;
    history.DisplayStack();

    history.PopStack();
    history.DisplayStack();

    history.PopStack();
    history.DisplayStack();

    history.PopStack();
    history.DisplayStack(); 
    cout << "Is call history empty? " << (history.IsEmptyStack() ? "Yes" : "No")<< endl << endl;

    return 0;
}
