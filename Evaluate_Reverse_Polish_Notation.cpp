// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Some examples:
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty())
            return 0;
        stack<int> store;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int a = store.top();
                store.pop();
                int b = store.top();
                store.pop();
                store.push(a+b);
            }
            else if (tokens[i] == "-") {
                int a = store.top();
                store.pop();
                int b = store.top();
                store.pop();
                store.push(b-a);
            }
            else if (tokens[i] == "*") {
                int a = store.top();
                store.pop();
                int b = store.top();
                store.pop();
                store.push(b*a);
            }
            else if (tokens[i] == "/") {
                int a = store.top();
                store.pop();
                int b = store.top();
                store.pop();
                store.push(b/a);
            } 
            else {
                store.push(atoi(tokens[i].c_str()));
            }
        }
        if (!store.empty())
            return store.top();
    }
};
