#include <iostream>
#include <stack>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    int isempty()
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    void push(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        newnode->next = head;
        head = newnode;
    }
    void pop()
    {
        if (isempty() == 0)
        {
            cout << "Stack is empty";
        }
        else
        {
            Node *deletenode = head;
            head = head->next;
            delete (deletenode);
        }
    }
    void DisplayList()
    {
        if (isempty() == 0)
        {
            cout << "Empty Linked List";
        }
        else
        {
            Node* ptr=head;
            cout << "Elements of Linked List are: " << endl;
            while (ptr != NULL)
            {
                cout << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }
    void topofList(){
        if (isempty()==0)
        {
            cout<<"List is Empty";
        }
        else{
            cout<<head->data;
        }
        
    }
};

int main()
{
    LinkedList obj;
    obj.push(12);
    obj.push(14);
    obj.push(17);
    obj.push(13);
    obj.pop();
    obj.DisplayList();
}