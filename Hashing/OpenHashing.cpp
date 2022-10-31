#include <iostream>
using namespace std;

class OpenHashing
{
private:
    int HS;
    struct Node
    {
        int key;
        Node *next;
    };
    Node* HT;
public:
    OpenHashing(int size){
        this->HS=size;
        HT[HS];
    }
};
int main()
{

    return 0;
}