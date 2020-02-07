#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>


#define STACK_MAX 300
using namespace std;
struct Stack {
    int s[STACK_MAX] = {};
    int top = 0;
    void init() {
        top = 0;
    }
    bool isEmpty() {
        return (top == 0);
    }
    bool isFull() {
        return (top >= STACK_MAX-1);
    }
    void push(int x) {
        if(isFull()) {
            cerr << "stack over flow" << endl;
            exit(-1);
        }
        top++;
        s[top] = x;
    }
    int pop() {
        if(isEmpty()) {
            cerr << "stack under flow" << endl;
            exit(-1);
        }
        top--;
        return s[top+1];
    }
    
};
int add(int a, int b) {
    return a+b;
}
int sub(int a, int b) {
    return a-b;
}
int mul(int a,int b) {
    return a*b;
}
int main() {
    char str[100];
    Stack s;
    s.init();
    while(scanf("%s", str) != EOF) {
        if(strcmp("+", str) == 0) {
            int a = s.pop();
            int b = s.pop();
            s.push(add(a, b));
        }else if(strcmp("-", str) == 0) {
            int b = s.pop();
            int a = s.pop();
            s.push(sub(a, b));
        }else if(strcmp("*", str) == 0) {
            int a = s.pop();
            int b = s.pop();
            s.push(mul(a, b));
        }else {
            int x = atoi(str);
            s.push(x);
        }
    }
    printf("%d\n", s.pop());
}