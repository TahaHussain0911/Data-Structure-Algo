#include <iostream>
using namespace std;
void insertionsort(int *array, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (array[j] < array[j - 1])
            {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
        for (int k = 0; k < size; k++)
        {
            cout << array[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {6, 31, 19, 2145, 35, 28, 0};
    int length = sizeof(arr) / sizeof(arr[0]);
    insertionsort(arr, length);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}