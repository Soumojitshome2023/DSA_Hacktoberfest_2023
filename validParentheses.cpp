
#include <bits/stdc++.h> 
using namespace std; 

bool valid(string s){

    stack<char> st; 
    for(auto i:s){
        if(i=='(' or i=='{' or i=='[') //if opening bracket push into stack
            st.push(i);  
        else{
            // if not opening bracket it should to be corresponding closing bracket of the bracket at top of stack
            if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']'))
                return false;

            st.pop();   
        }
    }
    return st.empty(); //stack has to be empty
}

int main() 
{ 
    bool res;

    res = valid("(({()})[])");
    cout << "Is it valid : " << res << endl;

    res = valid("(({()})[])(]");
    cout << "Is it valid : " << res << endl;

    return 0;
}