#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtTail(node*&head, int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node* tail = head;
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

void print(node*head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* evenOdd(node*&head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    
    node* prev = head;
    node * temp1= new node(0);
    temp1->next=head;
    
    node* c = temp1;
    node* p = head;
    //node* firsteve = head;
    //int k=0;
    while(c->next!=NULL)
    {

        prev = c;
        c = c->next;
        if(c->data%2==1)
        {
            node* temp = p->next;
            prev->next = c->next;
            p->next = c;
            c->next = temp;
            p = p->next;
        }
    }
    if(c->data%2==1)
    {
        node* temp = p->next;
        prev->next = NULL;
        p->next = c;
        c->next = temp;
    }
    return head;
}

int main() 
{
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    node* head = NULL;
    int n, d;
    cin >> n;
    while(n--)
    {
        cin >> d;
        insertAtTail(head, d);
    }
    node* fin = evenOdd(head);
    print(fin);
    return 0;
}