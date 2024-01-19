#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> temp_stack;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            temp_stack.push('(');
        }
        else if (s[i] == ')') {
            if (temp_stack.empty()) {
                answer = false;
                break;
            }
            else {
                temp_stack.pop();
            }
        }
    }
    
    if (!temp_stack.empty()) {
        answer = false;
    }

    return answer;
}