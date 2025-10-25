#include <iostream>
#include <string>
using namespace std;

class Stack {
    char* arr;
    int size;
    int top;
    
    public:
    
    Stack(int n) {
        size = n;
        arr = new char[size];
        top = -1; 
    }
    void push(char x) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }
    char pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }
    char Top() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return '\0';
        }
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};


int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return -1;
}

string infixToPostfix(string infix) {
    string postfix = "";
    Stack s(infix.length());

    for (int i=0; i<infix.length(); i++) {
        char c = infix[i];
        if ((c >= 'a' && c<= 'z') || (c>='A' && c<='Z')) {
            postfix += c;
        }

        else if (c == '(') {
            s.push(c);
        }

        else if (c == ')') {
            while (!s.isEmpty() && s.Top() != '(') {
                char op = s.pop();
                postfix += op;
            }

            if (s.Top() == '(') {
                s.pop(); 
            }

        }

        else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.Top())) {
                char op = s.pop();
                postfix += op;
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        char op = s.pop();
        postfix += op;
    }
    return postfix;
}


int main(){

    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
