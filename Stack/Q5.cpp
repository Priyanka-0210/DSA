//Infix to Postfix with parenthesis
#include <iostream>
#include <cstring>
#include "samplestack.cpp"
using namespace std;

int icp(char x) {
    switch(x) {
        case '^' : return 3;
        case '*' : return 2;
        case '/' : return 2;
        case '+' : return 1;
        case '-' : return 1;
        case '(' : return 4; // Ensure '(' is always pushed
        case '#' : return -1;
        default  : return 0;
    }
}

int isp(char x) {
    switch(x) {
        case '^' : return 3;
        case '*' : return 2;
        case '/' : return 2;
        case '+' : return 1;
        case '-' : return 1;
        case '(' : return 0; // Ensures nothing pops on encountering '('
        case '#' : return -1;
        default  : return 0;
    }
}

int main() {
    Stack<char> s(100);
    char inf[100], z;
    s.Push('#');

    cout << "\nEnter an Infix Expression: ";
    cin >> inf;

    int len = strlen(inf);
    inf[len] = '#';
    inf[len + 1] = '\0';

    for (int i = 0; inf[i] != '#'; i++) {
        if (isalpha(inf[i]) || isdigit(inf[i])) {
            cout << inf[i];
        }
        else if (inf[i] == '(') {
            s.Push('(');
        }
        else if (inf[i] == ')') {
            while (s.TopElement() != '(') {
                s.Pop(z);
                cout << z;
            }
            s.Pop(z); // discard '('
        } 
        else {
            //  For Operator: + - * / ^
            while (!s.isEmpty() && isp(s.TopElement()) >= icp(inf[i])) {
                s.Pop(z);
                cout << z;
            }
            s.Push(inf[i]);
        }
    }

    while (!s.isEmpty()) {
        s.Pop(z);
        if (z != '#') cout << z;
    }

    cout << endl;
    return 0;
}
