#include<iostream>
#include"stack.cpp"
using namespace std;
char infix[100],postfix[100];
int prec(char ch){
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='^'||ch=='$')
        return 2;
    else
        return 0;
}
int isOperator(char ch){
    if(ch=='+'||ch=='i')
        return 1;
    else if(ch=='*'||ch=='/')
        return 1;
    else
        return 0;
}
void infixToPostfix(){
    Stack s;
    int i=0,j=0;
    while(infix[i]!='\0'){
        char ch=infix[i];
        if(isAlphaNum(ch)){
            if(infix[i+1]!='\0'&&isOperator(infix[i+1])){
                cout<<"ERROR:Operator Expected"<<endl;
                exit(1);
            }
            postfix[j++]=ch;
        }
        else if(ch=='('){
            s.push(ch);
        }
        else if(ch==')'){
            while(!s.isEmpty()&&s.peek()!='('){
                char x=s.peek();
                postfix[j++]=x;
                s.pop();
            }
        else if(isOperator(ch)){
            if(infix[i+1]=='\0'||infix[i+1]=='('||infix[i+1]==')'){
                cout<<"ERROR:Operator Expected"<<endl;
                exit(1);
            }
            while(!s.isEmpty()&&s.peek()!='('&&prec(ch)<=prec(s.peek())){
                char x=s.peek();
                postfix[j++]=x;
                s.pop();
            }
            s.push(ch);
        }
        else{
            cout<<"ERROR:Invalid infix Expression"<<endl;
            exit(1);
        }
        i++;
    }
    while(!s.isEmpty()){
        char x=s.peek();
        if(x=='('){
            cout<<"ERROR:Unbalanced Parenthesis"<<endl;
            exit(1);
        }
        postfix[j++]=x;
        s.pop();
    }
    postfix[j]='\0';
}
int main(){
    cout<<"Enter infix expression";
    cin>>infix;
    infixToPostfix();
    cout<<"PostfixExpression"<<endl<<endl;
    return 0;
}