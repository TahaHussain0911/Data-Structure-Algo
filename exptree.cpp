#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
class ExpTree
{
private:
    struct Node
    {
        char ch;
        Node *RightCH, *LeftCH;
    };
    string postfixexp;
    Node *root;

    int isOperator(char c)
    {
        if (c == '*' || c == '+' || c == '-' || c == '/' || c == '^' || c == '%')
        {
            return 0;
        }
        return -1;
    }

public:
    ExpTree(string exp)
    {
        this->postfixexp = exp;
        root=NULL;
    }
    Node *getroot()
    {
        return root;
    }
    void PostfixTOTree()
    {
        stack <Node *> s;
        const int postfixlen = postfixexp.length();
        for (int i = 0; i < postfixlen; i++)
        {
            Node *ptr = new Node();
            ptr->RightCH = NULL, ptr->LeftCH = NULL;
            ptr->ch = postfixexp[i];
            if (isOperator(postfixexp[i]) == -1)
            {
                s.push(ptr);
            }
            else
            {
                ptr->RightCH = s.top();
                s.pop();
                ptr->LeftCH = s.top();
                s.pop();
                s.push(ptr);
            }
        }
        root = s.top();
    }
    void inOrder(Node *temproot)
    {
        if (temproot->LeftCH != NULL)
        {
            inOrder(temproot->LeftCH);
        }
        cout << temproot->ch << " ";
        if (temproot->RightCH != NULL)
        {
            inOrder(temproot->RightCH);
        }
    }
    void PreOrder(Node *temproot)
    {
        cout << temproot->ch << " ";
        if (temproot->LeftCH != NULL)
        {
            inOrder(temproot->LeftCH);
        }
        if (temproot->RightCH != NULL)
        {
            inOrder(temproot->RightCH);
        }
    }
    void PostOrder(Node *temproot)
    {
        if (temproot->LeftCH != NULL)
        {
            inOrder(temproot->LeftCH);
        }
        if (temproot->RightCH != NULL)
        {
            inOrder(temproot->RightCH);
        }
        cout << temproot->ch << " ";
    }
};

int main()
{
    string expression = "ab+cd-*";
    ExpTree obj(expression);
    obj.PostfixTOTree();
    obj.inOrder(obj.getroot());
}