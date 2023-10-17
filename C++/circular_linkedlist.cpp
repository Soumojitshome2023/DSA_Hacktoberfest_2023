//menu driven program for circularlinkedlist.
#include <iostream>
#include <cstdlib>
#include<stdlib.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val) : data(val), next(nullptr) {}
};
class Clinkedlist
{
    node *head, *temp;

public:
    Clinkedlist()
    {
        head = NULL;
        temp = NULL;
    }
    ~Clinkedlist()
    {
        node *x;
        x = head;
        while (x->next != head)
        {
            delete (x);
            x = x->next;
        }
        delete (x);
    }
    void insertBeg(int item);
    void insertEnd(int x);
    void deleteBeg();
    void deleteEnd();
    void insertAny(int index, int pro);
    void deleteAny(int pos);
    int lengthl();
    void display();
     void reverse();
    void scarch(int sc);
};
void Clinkedlist::insertBeg(int item)
{
    node *Newnode = new node(item);

    if (head == NULL)
    {
        head = temp = Newnode;
        Newnode->data = item;
        Newnode->next = head;
    }

    else
    {
        Newnode->data = item;
        Newnode->next = head;
        head = Newnode;
        temp->next = Newnode;
    }
}
void Clinkedlist::insertEnd(int x)
{
    node *Newnode = new node(x);
    if (head == NULL)
    {
        head = temp = Newnode;
        Newnode->data = x;
        Newnode->next = head;
    }

    else
    {
        Newnode->data = x;
        Newnode->next = temp->next;
        temp->next = Newnode;
        temp = Newnode;
    }
}
void Clinkedlist::deleteBeg()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    else if (head == temp)
    {
        node *w = head;
        head = temp = NULL;
        delete (w);
    }
    else
    {
        node *beg = head;
        temp->next = head->next;
        head = head->next;
        delete (beg);
    }
}
void Clinkedlist::deleteEnd()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    else if (head == temp)
    {
        node *w = head;
        head = temp = NULL;
        delete (w);
    }
    else
    {
        node *end = head;
        while (end->next != temp)
        {
            end = end->next;
        }
        node *d;
        d = end->next;
        end->next = temp->next;
        temp = end;
        delete (d);
    }
}
void Clinkedlist::insertAny(int index, int pro)
{
    node *Newnode = new node(pro);
    node *itex = temp;
    int a = lengthl();
    if (index == 1)
    {
        insertBeg(pro);
    }
    else if (index == a)
    {
        insertEnd(pro);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            itex = itex->next;
        }
        Newnode->data = pro;
        Newnode->next = itex->next;
        itex->next = Newnode;
    }
}
void Clinkedlist::deleteAny(int pos)
{
    int a, i;
    a = lengthl();
    i = 1;
    node *anyd = head;
    if (pos < 1 || pos > a)
    {
        cout << "invalid position" << endl;
    }
    else if (pos == 1)
    {
        deleteBeg();
    }
    else if (pos == a)
    {
        deleteEnd();
    }
    else
    {
        while (i < pos - 1)
        {
            anyd = anyd->next;
            i++;
        }
        node *del = anyd->next;
        anyd->next = anyd->next->next;
        delete (del);
    }
}
int Clinkedlist::lengthl()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *len;
    len = head;
    int count = 0;
    while (len != temp)
    {
        count++;
        len = len->next;
    }
    count++;
    return count;
}
void Clinkedlist::reverse()
{
    node *pre, *curr, *nex;
    pre = temp;
    curr = nex = head;
    while (nex != temp)
    {
        nex = nex->next;
        curr->next = pre;
        pre = curr;
        curr = nex;
    }
    curr->next = pre;
    pre = head;
    head = temp;
    temp = pre;
}
void Clinkedlist::scarch(int sc)
{
    node *s;
    s = head;
    int flag = 0;
    while (s->data != sc && s->next!= head)
    {
        s = s->next;
        flag += 1;
    }
    if (s->data==sc)
    {
        ++flag;
        cout << "the position of scarched item"
             << "=";
        cout << flag << endl;
    }
    else
    {
        cout << "the scarched item is not found!" << endl;
    }
}
void Clinkedlist::display()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *s = head;
    while (s->next != head)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << s->data << endl;
}
int main()
{
    
    Clinkedlist l;
    int n, item, i;
    int index, pro, pos, sc;
    cout << "operations on circular linkedlist:" << endl;
    cout << "----------------------------" << endl;
    cout << "0 for EXIT"
         << endl
         << "1.insert at beginning"
         << endl
         << "2.insert at end"
         << endl
         << "3.delete from beinning"
         << endl
         << "4.delete from end"
         << endl
         << "5.insert at any position"
         << endl
         << "6.delete from any position"
         << endl
         << "7.length of the linkedlist"
         << endl
         << "8.reverse"
         << endl
         << "9.scarch an item"
         << endl
         << "10.display" << endl;
    cout << "-------------------------------" << endl;
    while (1)
    {
        cout << "enter your choice"
             << "=";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "enter the item to be inserted"
                 << "=";
            cin >> item;
            l.insertBeg(item);
            break;
        case 2:
            cout << "enter the item to be inserted"
                 << "=";
            cin >> i;
            l.insertEnd(i);
            break;
        case 3:
            l.deleteBeg();
            break;
        case 4:
            l.deleteEnd();
            break;
        case 5:
            cout << "enter the position where the value should be inserted"
                 << "=";
            cin >> index;
            cout << "enter the item to be inserted"
                 << "=";
            cin >> pro;
            l.insertAny(index, pro);
            break;
        case 6:
            cout << "enter the position from where the value should be deleted"
                 << "=";
            cin >> pos;
            l.deleteAny(pos);
            break;
        case 7:
            cout << "the length of the linkedlist"
                 << "=";
            int le;
            le = l.lengthl();
            cout << le << endl;
            break;
             case 8:
                 l.reverse();
                 break;
             case 9:
                 cout << "enter the item to be scarched"
                      << "=";
                 cin >> sc;
                 l.scarch(sc);
                 break;
        case 10:
            l.display();
            break;
        default:
            exit(99);
        }
    }
    return 0;
}
