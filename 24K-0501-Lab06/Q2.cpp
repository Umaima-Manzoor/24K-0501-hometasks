#include <iostream>
#include <string>
using namespace std;

class Stack {
    int* arr;
    int size;
    int top;

public:
    Stack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};


int evaluatePostfix(string expr) {
    Stack s(expr.length()); 

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        
        if (ch >= '0' && ch <= '9') {
            int num = ch - '0';
            s.push(num);
        } else {
            
            if (s.isEmpty()) {
                cout << "Invalid expression" << endl;
                return -1;
            }
            int b = s.pop(); 
            
            if (s.isEmpty()) {
                cout << "Invalid expression" << endl;
                return -1;
            }
            int a = s.pop(); 

            int result = 0;
            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        cout << "Division by zero!" << endl;
                        return -1;
                    }
                    result = a / b; break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
            s.push(result);
        }
    }

    if (s.isEmpty()) {
        cout << "Invalid expression" << endl;
        return -1;
    }
    int finalResult = s.pop();

    if (!s.isEmpty()) {
        cout << "Invalid expression" << endl;
        return -1;
    }

    return finalResult;
}

int main() {
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;

    int result = evaluatePostfix(expr);
    cout << "Evaluated result: " << result << endl;

    return 0;
}
