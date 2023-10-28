#include<iostream>
using namespace std;
class Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class Queue{
    Node* front,*rear;
    Queue(){
        front=rear=NULL;
    }
    void enQueue(int x){
        Node* temp=new Node(x);
        if(rear==NULL){
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    void deQueue()
    {
        if(front==NULL)
            return;
        Node* temp=front;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        delete(temp);
    }
};
int main(){
    Queue q;
    int ch;
    cout<<"1.Insert"<<endl;
    cout<<"2.Delete"<<endl;
    do{
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch){
            case 1:cout<<"Enter the value to be inserted"<<endl;
                   int item;
                   cin>>item;
                   q.enQueue(item);
                   break;
            case 2:q.deQueue();
                   break;
            default:cout<<"Invalid Choice"<<endl;
        }
    }while(ch!=2);
    return 0;
}