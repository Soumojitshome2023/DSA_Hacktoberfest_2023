#include<iostream>
using namespace std;
struct Node{
    int coeff;
    int exp;
    Node* next;
};
class Poly{
    Node* head;
    public:
        Poly(){
            head=NULL;
        }
    void insert(int,int);
    Poly operator+(Poly &p);
    void display();
};
void Poly::insert(int c,int e){
    Node* curr=new Node;
    curr->coeff=c;
    curr->exp=e;
    if(head==NULL){
        head=curr;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=curr;
}
Poly Poly::operator+(Poly &p){
    Node* h1=head;
    Poly result;
    Node* h2=p.head;
    while(h1!=NULL&&h2!=NULL){
        if(h1->exp>h2->exp){
            result.insert(h1->coeff,h1->exp);
            h1=h1->next;
        }
        else if(h1->exp<h2->exp){
            result.insert(h2->coeff,h2->exp);
        }
        else{
            result.insert(h2->coeff+h2->exp,h1->exp);
            h1=h1->next;
            h2=h2->next;
        }
    }
    while(h1!=NULL){
        result.insert(h1->coeff,h1->exp);
        h2=h2->next;
        return result;
    }
}
void Poly::display(){
    Node* temp=head;
    if(head==NULL){
        cout<<"0"<<endl;
        return;
    }
    while(temp->next!=NULL){
        cout<<temp->coeff<<"x"<<temp->exp<<"+";
        temp=temp->next;
    }
    cout<<temp->coeff<<"x^"<<temp->exp<<endl;
}
int main(void){
    Poly p1,p2,p3;
    p1.insert(2,3);
    p1.insert(3,2);
    p1.insert(4,1);
    p1.display();
    cout<<endl;
    p2.insert(3,4);
    p2.insert(4,5);
    p2.insert(5,6);
    p2.display();
    cout<<endl;
    p3=p1+p2;
    p3.display();
    cout<<endl;
    return 0;
}