//
// Created by Ashwath on 08.12.18.
//

#include <iostream>
#include <stack>

bool balanced(std::string input){
    std::stack<char> vals;
    char x;
    for(int i=0; i<input.length(); i++){
        if(input[i] == '{' || input[i] == '[' || input[i] == '('){
            vals.push(input[i]);
        }

        else {
            if (vals.empty()) {
                return false;
            }

            switch (input[i]){
                case ')':
                    x = vals.top();
                    vals.pop();
                    if(x == '{' || x == '['){
                        return false;
                    }
                    break;
                case ']':
                    x = vals.top();
                    vals.pop();
                    if(x=='(' || x == '{'){
                        return false;
                    }
                    break;
                case '}':
                x = vals.top();
                vals.pop();
                if(x=='[' || x=='('){
                    return false;
                }
                break;
            }
        }

    }
    return vals.empty();
}

// Driver program to test above function
int main()
{
    std::string expr = "([)]";

    if (balanced(expr))
        std::cout << "Balanced";
    else
        std::cout << "Not Balanced";
    return 0;
}