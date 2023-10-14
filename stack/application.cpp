// implementation of stack i.e. infix to posfix expression conversion.
// e.g. infix expression=a+b-c/e
// e.g. postfix expression=ab+c/de*+
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define N 20
char stack[N];
class corestack
{
private:
    int t = -1;

public:
    void push(char item)
    {
        if (t == N - 1)
        {
            cout << "Overflow";
        }
        else
        {
            t++;
            stack[t] = item;
        }
    }

    void pop()
    {

        if (t == -1)
        {
            cout << "underflow";
        }
        else
        {
            t--;
        }
    }

    int top()
    {
        char v;
        if (t >= 0)
        {
            v = stack[t];
            return v;
        }
        else
        {
            return 0;
        }
    }
};

int priority(char a)
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '^')
    {
        return 3;
    }
    else
        return -1;
}
void in_post(string str)
{
    corestack st;
    string postfix;
    int l = str.length();
    for (int i = 0; i < l; i++)
    {
        char c = str[i];

        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            postfix += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and add to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (st.top() != 0 && priority(str[i]) <= priority(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (st.top() != 0)
    {
        postfix += st.top();
        st.pop();
    }
    cout<<"postfix expression"<<"=";
    cout << postfix << endl;
}

int main()
{
    string str;
    cout << "enter the infix expression"
         << ":";
    cin >> str;
    in_post(str);

    return 0;
}