#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtFront(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    if(head!=NULL)
    {
        head=n;
        n -> next = temp;
        return;
    }
}


void insertAttail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head = n;
        return;}
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp-> next;
    }
    temp->next = n;
}

void insertAfterSpecifiedPosition(node* &head, int val,int target){
    if(head == NULL){
        cout<<"Empty List";
        return;
    }
    node* n = new node(val);
    node* temp=head;
    while(temp->next !=NULL){
        if(temp->data == target)
        {
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp=temp->next;
    }
    cout << "Target node not found" << endl;
}

void insertBeforeSpecifiedPosition(node* &head, int val,int target){

if(head == NULL){
        cout<<"Empty List";
        return;
    }
    node* n = new node(val);
    node* temp=head;
    while(temp->next !=NULL){
        if(temp->next->data == target)
        {
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp=temp->next;
    }
    cout << "Target node not found" << endl;
}

void deleteAtFront(node* &head){
    if(head == NULL)
    {
        cout<<"Empty List";
        return;
    }
    node* temp=head;
    if(head != NULL)
    {
        head = head->next;
        delete temp;
    }
}

void deleteAtEnd(node* head){
if(head == NULL)
    {
        cout<<"Empty List";
        return;
    }
if(head->next==NULL)
    {
        delete head;
        head = NULL;
        return;
    }
node* temp=head;
while (temp->next->next !=NULL)
{
    temp=temp->next;
}
delete temp->next;
temp->next = NULL;
}


void deleteNode(node* &head,int target){
if(head == NULL)
    {
        cout<<"Empty List";
        return;
    }
if(head->data==target)
    {
        node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    node* temp=head;
while (temp->next != NULL)
{
    if(temp->next->data==target)
    {
        node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        return;
    }
    temp = temp->next;
}
cout<<"Node not found"<<endl;
}

void displaylist(node* head){
    node* temp=head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
node* head=NULL;
int key,value,target;
while(true){
cout << "Enter operation key (0 to display, 1 to insert at front, 2 to insert at tail, 3 to insert after target, 4 to delete at front, 5 to delete at end,6 to insert before target, -1 to exit): ";
cin>>key;
if(key == -1)       break;
if(key==0)      displaylist(head);
if(key==1){
    cin>>value;
    insertAtFront(head,value);
}   
if(key==2){
    cin>>value;
    insertAttail(head,value);
}
if(key==3){
    cout<<"value: "<<endl;
    cin>>value;
    cout<<"target: "<<endl;
    cin>>target;
    insertAfterSpecifiedPosition(head,value,target);
}
if(key==4){
    deleteAtFront(head);
}
if(key==5){
    deleteAtEnd(head);
}
if(key==6){
    cout<<"value: "<<endl;
    cin>>value;
    cout<<"target: "<<endl;
    cin>>target;
    insertBeforeSpecifiedPosition(head,value,target);
}
if(key==7){
    cout<<"target: "<<endl;
    cin>>target;
    deleteNode(head,target);
}
}
}
