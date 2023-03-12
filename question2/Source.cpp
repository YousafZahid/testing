#include <iostream>
#include <stack>
#include <string>

using namespace std;

#include <iostream>
using namespace std;
#define MAX_SIZE 50

class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (isFull()) {
            return;
        }
        else
            arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {

            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        if (top < 0) {
            cout << "Error: stack is empty\n";
            return true;
        }
        else
            return false;

    }

    bool isFull() {
        if (top >= MAX_SIZE - 1) {
            cout << "Error: stack overflow\n";
            return true;
        }
        return false;
    }

    bool isBalanced(string str) {
        stack<char> s;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                s.push(str[i]);
            }
            else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
                if (s.empty()) {
                    return false;
                }
                else if ((str[i] == ')' && s.top() == '(') ||
                    (str[i] == ']' && s.top() == '[') ||
                    (str[i] == '}' && s.top() == '{')) {
                    s.pop();
                }
                else {
                    return false;
                }
            }
        }
        return s.empty();
    }

    ~Stack() {

    }

};



int main() {
    Stack s;
    string st1 = "{()}[]"; // balanced
    string st2 = "{(})"; // not balanced
    if (s.isBalanced(st1)) {
        cout << "It is Balanced";
    }
    else {
        cout << "it is not balanced";
    }
    cout << endl;
    if (s.isBalanced(st2)) {
        cout << "It is Balanced";
    }
    else {
        cout << "it is not balanced";
    }

    return 0;
}

