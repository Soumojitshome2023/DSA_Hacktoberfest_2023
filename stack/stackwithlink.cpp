#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class Stack{
    Node* top;
    void push(int data){
        Node* temp=new Node();
        if(!temp){
            cout<<"\nStack Overflow";
            exit(1);
        }
        temp->data=data;
        temp->next=top;
        top=temp;
    }
    int isEmpty(){
        return top==NULL;
    }
    int peek(){
        if(!isEmpty())
            return top->data;
        else
            exit(1);
    }
    void pop(){
        Node* temp;
        if(top==NULL){
            cout<<"\nStack Underflow"<<endl;
            exit(1);
        }else{
            temp=top;
            top=top->next;
            free(temp);
        }
    }
}
int main(){
    Stack s;
    int ch;
    cout<<"1.Push"<<endl;
    cout<<"2.Peek"<<endl;
    cout<<"3.Pop"<<endl;
    cout<<"4.Exit"<<endl;
    do{
        cout<<"Enter your choice"<<endl;
        int ch;
        switch(ch){
            case 1:int item;
                   cout<<"Enter the item to be pushed"<<endl;
                   cin>>item;
                   s.push(item);
                   break;
            case 2:cout<<"Top Element:"<<stack.peek()<<endl;
                   break;
            case 3:cout<<"Popped"<<stack.pop()<<"from the stack"<<endl;
                   break;
            case 4:exit(1);
                   break;
            default:cout<<"Invalid Choice"<<endl;
        }
    }while(ch!=4);
    return 0;
}