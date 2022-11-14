#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

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
int NotaVertex(bool *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!array[i])
        {
            return 1;
        }
    }
    return 0;
}
void Djikstraw(int **array, int size)
{
    bool connected[size];
    int distance[size];
    int previous[size];
    memset(connected, false, size);
    int v = 0;
    for (int i = 0; i < size; i++)
    {
        distance[i]=99999;
    }
    distance[v] = 0;
    while (true)
    {
        connected[v] = true; // starting with source as v1
        if (NotaVertex(connected, size) == 0)
        {
            break;
        }
        for (int i = 0; i < size; i++)
        {
            if (!connected[i])
            {
                if (array[v][i] != 0 && distance[v] + array[v][i] < distance[i])
                {
                    distance[i] = distance[v] + array[v][i];
                    previous[i]=v;
                }
            }
        }
        int smallest = 8888;
        for (int j = 0; j < size; j++)
        {
            if (!connected[j])
            {
                if (smallest > distance[j])
                {
                    smallest = distance[j];
                    v = j;
                }
            }
        }
        
        cout<<previous[v]<<" "<<v<<" "<<smallest<<endl;
    }
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
        }
    }
    Myfile.close();
    // Outdegree(arr, vertices);
    // Indegree(arr, vertices);
    // DisplayArray(arr, vertices);
    Djikstraw(arr, vertices);
}