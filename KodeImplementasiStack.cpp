#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool JenisOperasi(char A);
int cekprecedence(char op);

vector<string> KonversiInfix(string str);
int evaluasi(const vector<string>& postfix);


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
bool JenisOperasi(char A) {
    return (A == '*' or A == '/' or A == '+' or A == '-' or A == '%');
}



vector<string> KonversiInfix(string str) {
    vector<string> infix;
string digit; 

for (size_t i = 0; i < str.size(); i++) {
    char currentChar = str[i]; 

    if (isspace(currentChar)) {
        continue;
    }
    else if (isdigit(currentChar)) {
        digit += currentChar;
    } 
    else if (currentChar == '-' && (i == 0 || JenisOperasi(str[i - 1]) || str[i - 1] == '(')) {
        if (str[i + 1] == '(') {
            infix.push_back("-1");
            infix.push_back("*");
        } else if (isdigit(str[i + 1])) {
            digit += currentChar;
        } else {
            infix.push_back("-1");
            infix.push_back("*");
        }
    } 
    else {
        if (!digit.empty()) {
            infix.push_back(digit);
            digit.clear();
        }
        infix.push_back(string(1, currentChar));
    }
}

if (!digit.empty()) {
    infix.push_back(digit);
}
return infix;
}

