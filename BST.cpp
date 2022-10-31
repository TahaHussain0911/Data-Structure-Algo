#include <iostream>
using namespace std;

class BinaryTree
{
private:
    struct Node
    {
        int data;
        Node *LC, *RC;
        int index;
    };
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    Node *getroot()
    {
        return root;
    }
    void addTree(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        newnode->LC = NULL;
        newnode->RC = NULL;
        newnode->index = 0;
        if (root == NULL)
        {
            root = newnode;
            root->index = newnode->index + 1;
        }
        else
        {

            Node *temproot;
            temproot = root;
            while (1==1)
            {
                if (newnode->data < temproot->data)
                {
                    if (temproot->LC == NULL)
                    {
                        temproot->LC = newnode;
                        newnode->index = 2 * temproot->index;
                        break;
                    }
                    else
                    {
                        temproot = temproot->LC;
                    }
                }
                else
                {
                    if (temproot->RC == NULL)
                    {
                        temproot->RC = newnode;
                        newnode->index = 2 * temproot->index + 1;
                        break;
                    }
                    else
                    {
                        temproot = temproot->RC;
                    }
                }
            }
        }
    }
    void inOrderDisplay(Node *temproot)
    {
        if (temproot->LC != NULL)
        {
            inOrderDisplay(temproot->LC);
        }
        cout << temproot->data << endl;
        if (temproot->RC != NULL)
        {
            inOrderDisplay(temproot->RC);
        }
    }
    void SearchNode(int number)
    {
        Node *ptr = root;
        while (ptr != NULL)
        {

            if (number < ptr->data)
            {
                ptr = ptr->LC;
            }
            else if (number > ptr->data)
            {
                ptr = ptr->RC;
            }
            else
            {
                cout << "Number found at " << ptr->index << " tree index" << endl;
                return;
            }
        }
        cout << "Number not found" << endl;
    }
    ~BinaryTree()
    {
        delete root;
    }
};
int main()
{
    BinaryTree obj;
    obj.addTree(15);
    obj.addTree(5);
    obj.addTree(10);
    obj.addTree(11);
    obj.addTree(9);
    obj.addTree(3);
    obj.addTree(25);
    obj.inOrderDisplay(obj.getroot());
    obj.SearchNode(10);
}