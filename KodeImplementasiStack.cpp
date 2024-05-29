#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool JenisOperasi(char A); //deglarasi program fung JenisOperasi yaitu ebuah fungsi yang memeriksa apakah karakter yang diberikan adalah salah satu dari operator aritmatika dasar 
int cekprecedence(char op); //deglarasi program fungsi cekPrecedence yaitu sebuah fungsi yang menentukan prioritas (precedence) dari operator aritmatika. 
vector<string> KonversiPostfix(vector<string>& infix);  //deglarasi program ekspresi matematika yang mengonversi ekspresi infix menjadi postfix (InfixToPostfix). 
vector<string> KonversiInfix(string str); //deglarasi program atau fungsi ekspresi matematika yang berguna untuk mengkonversi string aritmatika menjadi ekspresi infix (StringToInfix)
int evaluasi(const vector<string>& postfix); //deglarasi program kalkulator ekspresi  evaluasi aritmatika.


int main() {  //Membuat program awal bagian dari implementasi kalkulator ekspresi matematika
    string input;
    getline(cin, input);

    vector<string> infix = KonversiInfix(input);
    vector<string> postfix = KonversiPostfix(infix);

    int result = evaluasi(postfix);
    cout << result << endl;

return 0;
}
bool JenisOperasi(char A) { //program fung JenisOperasi yaitu ebuah fungsi yang memeriksa apakah karakter yang diberikan adalah salah satu dari operator aritmatika dasar 

    return (A == '*' or A == '/' or A == '+' or A == '-' or A == '%');
}
int cekprecedence(char op) { //program fungsi cekPrecedence yaitu sebuah fungsi yang menentukan prioritas (precedence) dari operator aritmatika. 
    if (op == '+' or op == '-') {
        return 1;
    } else if (op == '*' or op == '/' or op == '%') {
        return 2;
    } else {
        return 0;

vector<string> KonversiPostfix(vector<string>& infix) {  //program ekspresi matematika yang mengonversi ekspresi infix menjadi postfix (InfixToPostfix). 

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


vector<string> KonversiInfix(string str) {  //program atau fungsi ekspresi matematika yang berguna untuk mengkonversi string aritmatika menjadi ekspresi infix (StringToInfix)
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

int evaluasi(const vector<string>& postfix) { //program kalkulator ekspresi  evaluasi aritmatika.
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
