#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool JenisOperasi(char A);
int cekprecedence(char op);

vector<string> KonversiPostfix(vector<string>& infix);
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

vector<string> KonversiPostfix(vector<string>& infix) {
    vector<string> postfix;
    stack<string> opStack;

    for (const string& token : infix) {
        if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1]))) {
            postfix.push_back(token);
        } else if (token == "(") {
            opStack.push(token);
        } else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.pop();
        } else {
            while (!opStack.empty() && cekprecedence(opStack.top()[0]) >= cekprecedence(token[0])) {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    while (!opStack.empty()) {
        postfix.push_back(opStack.top());
        opStack.pop();
    }
    return postfix;
}
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

int evaluasi(const vector<string>& postfix) {
    stack<int> eval;

    for (const string& token : postfix) {
        if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1]))) {
            eval.push(stoi(token));
        } else {
            int b = eval.top();
            eval.pop();
            int a = eval.top();
            eval.pop();

            if (token == "+") {
    eval.push(a + b);
} else if (token == "-") {
    eval.push(a - b);
} else if (token == "*") {
    eval.push(a * b);
} else if (token == "/") {
    eval.push(a / b);
} else if (token == "%") {
    eval.push(a % b);
} 
        }
    }
 return eval.top();
}
