#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int cekprecedence(char op);

int main() {
    string input;
    getline(cin, input);

    vector<string> infix = KonversiInfix(input);
    vector<string> postfix = KonversiPostfix(infix);

    int result = evaluasi(postfix);
    cout << result << endl;

return 0;
}



int cekprecedence(char op) {
    if (op == '+' or op == '-') {
        return 1;
    } else if (op == '*' or op == '/' or op == '%') {
        return 2;
    } else {
        return 0;
    }
}
