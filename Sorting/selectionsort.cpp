#include <iostream>
using namespace std;
void selectionsort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = array[i];
        int count = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < temp)
            {
                temp = array[j];
                count = j;
            }
        }
        array[count] = array[i];
        array[i] = temp;
        for (int k = 0; k < size; k++)
        {
            cout << array[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {6, 3, 9, 5, 2, 8, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, length);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}