#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
       
    }
};
class LinkedList
{
    public:
        int count=0;
       Node *head=NULL;
    void insertbegin(int x)
    {
        Node *curr=new Node(x);
        count++;
        if(head==NULL)
            head=curr;
        else
            {
                curr->next=head;
                head->next=curr;
                head=curr;
            }
        cout <<"\nNo of nodes="<<count<<"\n";
    }
    void insertend(int n)
    {
        Node *curr=new Node(n);
        if(head==NULL)
            head=curr;
        else
            {
                int i=1;
                Node *temp=head;
                while(i<count)
                    temp=temp->next;
                curr->next=head;
                temp->next=curr;
                count++;
            }
    }
    void delbeg()
    {
        if(head==NULL)
            cout<<"Empty list";
        else
        {
            Node *temp1=head;
            int i=1;
            while(i<count)
            {
                temp1=temp1->next;
            }
            Node *temp=head;
            head=head->next;
            temp1->next=head;
            delete(temp);
            count--;
        }
    }
    void delend()
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    
    else
    {
        Node *temp = head;
       int i=1;
       while(i<count-1)
       {
           temp=temp->next;
       }
       Node *temp1=temp->next;
       temp->next=head;
       delete(temp1);
    }
}
    void delpos(int pos)
    {
        int count;
        if(head==NULL)
            cout<<"Empty List";
        else
        {
            Node *temp=head;
            count=1;
            while(count<pos-1)
            {
                temp=temp->next;
                count++;
            }
            Node *temp1=temp->next;
            temp->next=temp->next->next;
            delete(temp1);
        }
    }

    
    void display()
    {
        Node *temp=head;
        if(head==NULL)
            cout<<"Empty List";
        else
        {
            int i=1;
            while(i<count)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }
};
int main()
{
    LinkedList mylist;
    int choice,n,pos;
    do{
        cout<<"1.Enter value at the beginning:"<<endl;
        cout<<"2.Enter value at the end:"<<endl;
        cout<<"3.Delete from beginning:"<<endl;
        cout<<"4.Display the list:"<<endl;
        cout<<"5.Delete from end:"<<endl;
        cout<<"6.Delete from position:"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                    cout<<"Input Element to insert";
                    cin>>n;
                    mylist.insertbegin(n);
                    break;
            case 2:
                    cout<<"Input element to insert";
                    cin>>n;
                    mylist.insertend(n);
                    break;
            case 3:
                    mylist.delbeg();
                    break;
            case 5:
                    mylist.delend();
                    break;
            case 4:
                    mylist.display();
                    break;
            case 6:
                    cout<<"Enter position to be delete:"<<endl;
                    cin>>pos;
                    mylist.delpos(pos);
                    break;

        }
    }while(choice<=7);
}
