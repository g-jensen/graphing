#include "PostFix.h"


std::unordered_map<std::string, INodeFactory*> PostFix::tokens(
    { 
        {"*",new MultNodeFactory()},
        {"+",new AddNodeFactory()},
        {"-",new SubtractNodeFactory()},
        {"/",new DivideNodeFactory()}
    }
);

std::vector<std::string> PostFix::TokenizeString(std::string s, char token)
{
    // Vector of string to save tokens
    std::vector <std::string> tokens;

    // stringstream class check1
    std::stringstream check1(s);

    std::string intermediate;

    // Tokenizing w.r.t. space ' '
    while (getline(check1, intermediate, token))
    {
        tokens.push_back(intermediate);
    }

    return tokens;
}

std::string PostFix::RemoveSpace(std::string s)
{
    std::string output = "";
    for (char c : s) {
        if (c != ' ') {
            output += c;
        }
    }
    return output;
}

int PostFix::Prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

std::string PostFix::InfixToPostfix(std::string s)
{

    s = RemoveSpace(s);

    

    std::stack<char> st; //For stack operations, we are using C++ built in stack
    std::string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += " ";
            result += c;
        }

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (st.top() != '(')
            {
                result += " ";
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        //If an operator is scanned
        else {
            while (!st.empty() && Prec(s[i]) <= Prec(st.top())) {
                result += " ";
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += " ";
        result += st.top();
        st.pop();
    }

    /*if (result.size() > 1) {
        result = result.substr(1, result.size());
    }*/

    return result;
}

exprNode* PostFix::PostfixToTree(std::string s)
{
    auto token = tokens.find("*");
    INodeFactory* rootNodeFactory = nullptr;
    if (token != tokens.end()) {
        rootNodeFactory = token->second;
    }
    exprNode* root = rootNodeFactory->execute();
}
