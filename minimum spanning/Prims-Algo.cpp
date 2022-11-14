#include <iostream>
#include <fstream>
#include <cstring>
// #include <string>
using namespace std;

void DisplayArray(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
// void minimum(int **array,int vertex1,int vertex2, int size,bool *boolarray,int temp)
// {
//     for (int k = 0; k < size; k++)
//     {
//         if (temp > array[vertex2][k])
//         {
//             if (!boolarray[k] && array[vertex2][k] != 0)
//             {
//                 temp = array[vertex2][k];
//                 vertex1 = vertex1;
//                 vertex2 = k;
//             }
//         }
//     }
// }
void Prim(int **array, int size)
{
    int connected[size];
    for (int i = 0; i < size; i++)
    {
        connected[i] = -1;
    }
    connected[0] = 0;
    int total=0;
    for (int i = 0; i < size - 1; i++)
    {
        int temp = 88888;
        int v1 = 0, v2 = 0;
        for (int j = 0; j < size; j++)
        {
            if (connected[j]==0)
            {
                for (int k = 0; k < size; k++)
                {
                    if (temp>array[j][k])
                    {
                        if (connected[k]!=0 && array[j][k]!=0)
                        {
                            temp=array[j][k];
                            v1=j;
                            v2=k;
                        }

                    }

                }
                // v1=j;
                // minimum(array,v1, v2,size,connected,temp);
            }
        }
        connected[v2] = 0;
        cout << v1 << " " << v2 << " " << temp << endl;
        total+=temp;
        
    }
    cout<<"Minimum cost = "<<total;
}
int main()
{
    ifstream Myfile;
    Myfile.open("graph.txt");
    string ignoreline;
    getline(Myfile, ignoreline);
    string veredge;
    getline(Myfile, veredge);
    // cout<<veredge.length();
    char vevalues[veredge.length()];
    strcpy(vevalues, veredge.c_str());
    char *ptr;
    int const vertices = atoi(strtok(vevalues, " "));
    int const edges = atoi(strtok(NULL, ""));
    int **arr;
    *arr = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        arr[i] = new int[vertices];
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            arr[i][j] = 0;
        }
    }
    while (!Myfile.eof())
    {
        string data;
        getline(Myfile, data);
        char chardata[data.length()];
        strcpy(chardata, data.c_str());
        int X = atoi(strtok(chardata, ","));
        int Y = atoi(strtok(NULL, ","));
        int value = atoi(strtok(NULL, ""));
        if (value == 0)
        {
            arr[X][Y] = 1;
        }
        else
        {
            arr[X][Y] = value;
            arr[Y][X] = value;
        }
    }
    Myfile.close();
    // DisplayArray(arr, vertices);
    Prim(arr, vertices);
}