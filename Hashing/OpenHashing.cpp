#include <iostream>
using namespace std;
struct OpenHash
{
    int value;
    OpenHash *next;
};
const int HS = 10;
OpenHash *HT[HS];
void addKey(int number)
{
    int key = number % HS;
    OpenHash *ptr = new OpenHash();
    if (HT[key] == NULL)
    {
        ptr->value = number;
        ptr->next = NULL;
        HT[key] = ptr;
    }
    else
    {
        OpenHash *root = new OpenHash();
        root = HT[key];
        while (root->next != NULL)
        {
            root = root->next;
        }
        root->next=ptr;
        ptr->value=number;
        ptr->next=NULL;
    }
    // cout << HT[key]->value << " " << root->next;
}
void getKey(int number)
{
    int key = number % HS;
    if (HT[key]->value == number)
    {
        // cout << key;
    }
    else{
        OpenHash* root=new OpenHash();
        root=HT[key];
        while (root->next!=NULL)
        {
            root=root->next;
        }
        // cout<<key;
    }
}
void getFromIndex(int index){
    OpenHash* root=new OpenHash();
    root=HT[index];
    while (root!=NULL)
    {
        cout<<root->value<<endl;
        root=root->next;
    }
    cout<<root->value;
    
}
int main()
{
    for (int i = 0; i < HS; i++)
    {
        HT[i] = NULL;
    }

    addKey(16);
    addKey(32);
    addKey(26);
    addKey(95);
    addKey(17);
    addKey(36);

    // getKey(16);
    getFromIndex(6);
    // obj.getKey();
    return 0;
}