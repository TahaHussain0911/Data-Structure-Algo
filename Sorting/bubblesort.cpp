#include <iostream>
using namespace std;

void bubblesort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
        for (int k = 0; k < size; k++)
        {
            cout<<array[k]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int arr[] = {12, 49, 9, 15, 9, 18, 27};
    int length = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, length);
    for (int i = 0; i < length ;i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}