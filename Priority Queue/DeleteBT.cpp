#include <iostream>
using namespace std;

void DeleteTree(int *array, int size)
{
    int i = 1;
    int j = 1;
    array[1] = 'd';
    while (i <= size)
    {
        if (j * 2 > size)
        {
            j--;
        }
        else if (array[j] == 'd' && array[j * 2] < array[(j * 2) + 1])
        {
            array[j] = array[j * 2];
            array[j * 2] = 'd';
            j = j * 2;
        }
        else if (array[j] == 'd')

        {
            array[j] = array[(j * 2) + 1];
            array[(j * 2) + 1] = 'd';
            j = j * 2 + 1;
        }
        i++;
    }
    for (int i = 1; i <= size; i++)
    {
        if (array[i] == 'd')
        {
            if (array[size] == 'd')
            {
                array[i] = array[size - 1];
            }
            else{
                array[i]=array[size];
            }
        }
    }
}
int main()
{
    int size;
    cout << "Enter Number of Elements: ";
    cin >> size;
    int arr[size + 1];
    int input;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter Number: ";
        cin >> input;
        arr[i] = input;
    }
    DeleteTree(arr, size);
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}