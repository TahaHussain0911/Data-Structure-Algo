#include <iostream>
using namespace std;
// array=[6,3,9,5,2,8,7]
void quickSort(int *array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[high];
    int temp;
    if (i == j)
    {
        cout<<"1 element in array which is: ";
    }
    else
    {
        while (i <= j)
        {
            while (array[i] < pivot)
            {
                i++;
            }
            while (array[j] > pivot)
            {
                j--;
            }
            if (i <= j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        if (j > low)
        {
            quickSort(array, low, j);
        }
        if (i < high)
        {
            quickSort(array, i, high);
        }
    }
}

int main()
{
    int array[] = {6, 3, 9, 5, 2, 8, 7};
    int length = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, length - 1);
    // cout << length << endl;
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << endl;
    }

    return 0;
}