#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
void DisplayArray(int **array,int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void Outdegree(int **array, int size)
{
    int *OD;
    OD = new int[size];
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] != 0)
            {
                count++;
            }
        }
        OD[i] = count;
    }
    cout << "Outdegrees are: ";
    for (int i = 0; i < size; i++)
    {
        cout << OD[i] << " ";
    }
    cout << endl;
}
void Indegree(int **array, int size)
{
    int *IN;
    IN = new int[size];
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[j][i] != 0)
            {
                count++;
            }
        }
        IN[i] = count;
    }
    cout << "Indegrees are: ";
    for (int i = 0; i < size; i++)
    {
        cout << IN[i] << " ";
    }
    cout << endl;
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
            // arr[Y][X] = value;
        }
    }
    Myfile.close();
    DisplayArray(arr,vertices);
    Outdegree(arr, vertices);
    Indegree(arr, vertices);
    return 0;
}