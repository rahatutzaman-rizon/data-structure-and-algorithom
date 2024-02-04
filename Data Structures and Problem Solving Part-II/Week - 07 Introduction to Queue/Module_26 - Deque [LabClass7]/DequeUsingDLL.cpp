#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node* prev;
    int data;
    node* next;
};

class Deque{
public:
    node *head;
    node *tail;
    int sz;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node *CreateNode(int value)
    {
        node *newnode = new node;
        newnode->prev = NULL;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }

    void push_back(int value)
    {
        node *a = CreateNode(value);
        if(sz == 0)
        {
            head = a;
            tail = a;
        }
        else
        {
            tail->next = a;
            a->prev = tail;
            a->next = NULL;
            tail = a;
        }
        sz++;
        cout<<"OK"<<endl;
    }

    void push_front(int value)
    {
        node *a = CreateNode(value);
        if(sz == 0)
        {
            cout<<"OK"<<endl;
            head = a;
            tail = a;
        }
        else
        {
            cout<<"OK"<<endl;
            head->prev = a;
            a->next = head;
            head = a;
        }
        sz++;
    }

    void pop_back()
    {
        if(sz == 1)
        {
            cout<<"OK"<<endl;
            delete tail;
            head = NULL;
            tail = NULL;
        }
        else if(sz == 0)
        {
            cout<<"Already Empty\n";
            return;
        }
        else
        {
            cout<<"OK"<<endl;
            node *a = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete a;

        }
        sz--;
    }

    void pop_front()
    {
        if(sz == 0)
        {
            cout<<"Already Empty\n";
            return;
        }
        else if(sz == 1)
        {
            cout<<"OK"<<endl;
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            cout<<"OK"<<endl;
            node *a = head;
            delete head;
            a = a->next;
            a->prev = NULL;
            head = a;
        }
        sz--;
    }

    void front()
    {
        if(sz==0){cout<<"Deque is Empty"<<endl;return;}
        else{cout<<head->data<<endl;}
    }

    void back(){
        if(sz==0){cout<<"Deque is Empty"<<endl;return;}
        else{cout<<tail->data<<endl;}
    }

    void Traverse()
    {
        node *a = head;
        while(a != NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<endl;
    }

    void size()
    {
        cout<<sz<<endl;
    }

};

int main()
{
    Deque d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    cout<<endl;

    cout<<"Deque : ";d.Traverse();
    cout<<"FRONT : ";d.front(); cout<<"BACK : ";d.back();


    d.push_front(60);
    d.push_front(70);
    d.push_back(80);
    cout<<"Deque : ";d.Traverse();
    cout<<"FRONT : ";d.front(); cout<<"BACK : ";d.back();
    cout<<"SIZE : ";d.size();


    d.pop_front();
    d.pop_front();
    cout<<"Deque : ";d.Traverse();

    d.pop_back();
    d.pop_back();
    cout<<"Deque : ";d.Traverse();
    cout<<"SIZE : ";d.size();



    d.pop_front();
    d.pop_front();
    cout<<"Deque : ";d.Traverse();
    cout<<"SIZE : ";d.size();

    d.pop_back();
    d.pop_front();
    cout<<"SIZE : ";d.size();
    d.front();
    d.back();



    return 0;
}
