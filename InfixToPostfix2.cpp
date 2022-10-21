#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int isOperator(char c)
{
    if (c == '(')
    {
        return 1;
    }
    if (c == ')')
    {
        return 1;
    }
    if (c == '^')
    {
        return 4;
    }
    if (c == '%')
    {
        return 4;
    }
    if (c == '/')
    {
        return 3;
    }
    if (c == '*')
    {
        return 3;
    }
    if (c == '+')
    {
        return 2;
    }
    if (c == '-')
    {
        return 2;
    }
    return 0;
}
string InfixtoPostfix(string expression)
{
    const int explen = expression.length();
    char *infix;
    infix = new char[explen];
    strcpy(infix, expression.c_str());
    char *postfix = new char[explen];
    strcpy(postfix, "");
    stack<char> s;
    int j = 0;
    for (int i = 0; i < explen; i++)
    {
        if (isOperator(infix[i]) == 0)
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix[j] = s.top();
                j++;
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && isOperator(infix[i]) <= isOperator(s.top()))
            {
                postfix[j] = s.top();
                j++;
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty())
    {
        postfix[j] = s.top();
        s.pop();
    }
    return postfix;
}
int main()
{
    string expression = "(a+b)*(c-2)";
    cout << InfixtoPostfix(expression);
    // cout<<sizeof(int);
}
