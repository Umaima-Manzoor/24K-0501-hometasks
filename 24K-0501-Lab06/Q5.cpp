#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Stack {
    float* arr;
    int size;
    int top;

public:
    Stack(int n) {
        size = n;
        arr = new float[size];
        top = -1;
    }

    void push(float x) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    float pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        return arr[top--];
    }

    float Top() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

float evaluatePrefix(string prefix) {
    Stack s(prefix.length());
    int i = prefix.length() - 1;

    while (i >= 0) {
        if (prefix[i] == ' ') {
            i--;
            continue;
        }

        
        if (isdigit(prefix[i])) {
            string num = "";

            
            while (i >= 0 && isdigit(prefix[i])) {
                num = prefix[i] + num;
                i--;
            }

            float number = stof(num);
            s.push(number);
        }

        
        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^') {
            float op1 = s.pop();
            float op2 = s.pop();
            float result = 0;

            switch (prefix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }

            s.push(result);
            i--;
        } 
        else {
            i--;
        }
    }

    return s.Top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression (use spaces between numbers): ";
    getline(cin, prefix);

    float result = evaluatePrefix(prefix);
    cout << "Final evaluated result: " << result << endl;

    return 0;
}
