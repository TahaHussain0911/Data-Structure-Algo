#include <iostream>
#include <string>
using namespace std;

void MaxHeap(int *array, int arrsize)
{
    int j = 2;
    while (j <= arrsize)
    {
        // j=1
        if (array[j] > array[j / 2])
        {
            int temp = array[j / 2];
            array[j / 2] = array[j];
            array[j] = temp; // swaping
            if (j >= 4)
            {
                j = j / 2;
            }
        }
        else
        {
            j++;
            continue;
        }
    }
    return;
}

void MinHeap(int *array, int arrsize)
{
    int j = 2;
    while (j <= arrsize)
    {
        // j=1
        if (array[j] < array[j / 2])
        {
            int temp = array[j / 2];  // parent = 1 rc=2 lc=3   2/2=1 3/2 = 1
            array[j / 2] = array[j];  
            array[j] = temp;

            if (j >= 4)
            {
                j = j / 2;
            }
        }
        else
        {
            j++;
            continue;
        }
    }
    return;
}
int main()
{
    int size;
    cout << "Enter Number of Elements: ";
    cin >> size;
    int arr[size];
    int input;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter Number: ";
        cin >> input;
        arr[i] = input;
    }
    // MaxHeap(arr,size);
    MinHeap(arr, size);
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << endl;
    }
}