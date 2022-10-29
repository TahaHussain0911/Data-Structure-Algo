#include <iostream>
using namespace std;

class ClosedHash
{
private:
    int *HT;
    int HS;
    int HI;

public:
    ClosedHash(int size)
    {
        this->HS = size;
        HT = new int[HS];
        for (int i = 0; i < HS; i++)
        {
            HT[i] = -1;
        }
    }
    void AddKey(int number)
    {
        HI = number % HS;
        if (HT[HI] == -1)
        {
            HT[HI] = number;
        }
        else
        {
            // linear probing
            int i = HI;
            int count = 0;
            while (HT[i] != -1)
            {
                count++;
                if (i == (HS - 1))
                {
                    i = (i + 1) % HS;
                }
                else
                {
                    i++;
                }
                //If the array is full then on inserting it will through error
                if (count==HS)
                {   
                    cout<<"Array is full, cannot insert number "<<number<<endl;
                    break; 
                }
                
            }
            if (HT[i] == -1)
            {
                HT[i] = number;
            }
        }
    }
    void DisplayHashT()
    {
        for (int i = 0; i < HS; i++)
        {
            cout << i << ": " << HT[i] << endl;
        }
    }
    void Search(int number)
    {
        HI = number % HS;
        if (HT[HI] == number)
        {
            cout << "Number found at index " << HI;
        }
        else
        {
            int i = HI;
            int count = 0;
            while (HT[i] != number || HT[i]==-1)
            {
                count++;
                if (i == (HS - 1))
                {
                    i = (i + 1) % HS;
                }
                else
                {
                    i++;
                }
                if (count == HS)
                {
                    break;
                }
            }
            if (HT[i] == number)
            {
                cout << "Found at index: " << i;
            }
            else
            {
                cout << "Number not found";
            }
        }
    }
};
int main()
{
    ClosedHash obj(10);
    obj.AddKey(100);
    obj.AddKey(12);
    obj.AddKey(33);
    obj.AddKey(11);
    obj.AddKey(26);
    obj.AddKey(54);
    obj.AddKey(48);
    obj.AddKey(65);
    obj.AddKey(69);
    obj.AddKey(28);
    obj.AddKey(18);
    obj.DisplayHashT();
    obj.Search(18);
    return 0;
}