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
        root->next = ptr;
        ptr->value = number;
        ptr->next = NULL;
    }
}
void getKey(int number)
{
    int key = number % HS;
    int count = 1;
    if (HT[key]->value == number)
    {
        cout << "Key: " << key << " at index: " << count;
    }
    else
    {
        OpenHash *root = new OpenHash();
        root = HT[key];
        while (true)
        {
            if (root->value == number)
            {
                cout << "Key: " << key << " at index: " << count;
                break;
            }
            count++;
            root = root->next;
        }
    }
}
void getFromIndex(int index)
{
    OpenHash *root = new OpenHash();
    root = HT[index];
    int count = 1;
    while (root != NULL)
    {
        cout << root->value << " at " << count << endl;
        count++;
        root = root->next;
    }
    cout << root->value << " at " << count << endl;
}
void DisplayHashT()
{
    OpenHash *root = new OpenHash();
    for (int i = 0; i < HS; i++)
    {
        if (HT[i] == NULL)
        {
            continue;
        }
        else
        {
            int count = 1;
            root = HT[i];
            cout << "For Index " << i << " : ";
            while (root->next != NULL)
            {
                cout << root->value << " " ;
                count++;
                root = root->next;
            }
            cout << root->value << " "<<endl;
        }
    }
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

    // getKey(26);
    DisplayHashT();
    // getFromIndex(6);
    // obj.getKey();
    return 0;
}