#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    vector<string> infix = KonversiInfix(input);
    vector<string> postfix = KonversiPostfix(infix);

    int result = evaluasi(postfix);
    cout << result << endl;

return 0;
}
