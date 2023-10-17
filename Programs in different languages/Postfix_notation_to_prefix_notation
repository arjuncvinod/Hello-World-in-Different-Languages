#include <iostream>
#include <stack>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

std::string postfixToPrefix(const std::string& postfix) {
    std::stack<std::string> stack;

    for (char c : postfix) {
        if (isOperator(c)) {
            std::string op1 = stack.top();
            stack.pop();
            std::string op2 = stack.top();
            stack.pop();

            std::string temp = c + op2 + op1;
            stack.push(temp);
        } else {
            std::string temp(1, c);
            stack.push(temp);
        }
    }

    return stack.top();
}

int main() {
    std::string postfixExpression;
    std::cout << "Enter a postfix expression: ";
    std::cin >> postfixExpression;

    std::string prefixExpression = postfixToPrefix(postfixExpression);
    std::cout << "Prefix expression: " << prefixExpression << "\n";

    return 0;
}
