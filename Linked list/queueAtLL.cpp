#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *front,*back;

public:
    LinkedList()
    {
        front = NULL;
        back = NULL;
    }
    int isempty()
    {
        if (front == NULL && back==NULL)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    void pushqueue(int value){
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        if (front==NULL)
        {
            back=newnode;
            front=newnode;
        }
        else{
            back->next=newnode; //front apni jagah hi rahega back next list ke address ko point karega
            back=newnode;
        }
        
    }
    void popqueue(){
        if (isempty()==0)
        {
            cout<<"Queue is Empty";
        }
        else{
            if (front==back)
            {
                delete(front);
                front=NULL;
                back=NULL;
            }
            else{
                Node* deletenode=front;
                front=front->next;
                delete(deletenode);
            }
            
        }
        
    }
    void DisplayList(){
        if (isempty()==0)
        {
            cout<<"List is Empty";
        }
        else{
            Node* ptr=front;
            cout<<"Elements of Linked List are: "<<endl;
            while (ptr!=NULL)
            {
                cout<<ptr->data<<endl;
                ptr=ptr->next;
            }
            
        }
        
    }
    ~LinkedList(){
        delete front;
        delete back;
    }
};


int main(){
    LinkedList obj;
    obj.pushqueue(12);
    obj.pushqueue(16);
    obj.pushqueue(13);
    obj.pushqueue(17);
    obj.popqueue();
    obj.DisplayList();
}