#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Node
{
    char ch;
    Node *RightCH, *LeftCH;
};

Node *root = NULL;
int isOperator(char c)
{
    if (c=='*' || c=='+' || c=='-' || c=='/' || c=='^' || c=='%')
    {
        return 0;
    }
    return -1;
}
void PostfixTOTree(string postfixexpression)
{
    Node *stack[5];
    int top = -1;
    const int postfixlen = postfixexpression.length();
    char *postfix = new char[postfixlen];
    strcpy(postfix, postfixexpression.c_str());
    for (int i = 0; i < sizeof(postfix) - 1; i++)
    {
        Node *ptr = new Node();
        ptr->RightCH = NULL, ptr->LeftCH = NULL;
        ptr->ch = postfixexpression[i];
        if (isOperator(postfixexpression[i]) == -1)
        {
            top++;
            stack[top] = ptr;
            // cout<<stack[top];
        }
        else
        {
            ptr->RightCH = stack[top];
            top--;
            ptr->LeftCH = stack[top];
            // top--;
            stack[top] = ptr;
            // cout<<stack[top];
        }
    }
    root = stack[top];
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

int main()
{
    string expression = "ab+cd-*";
    PostfixTOTree(expression);
    inOrder(root);
}