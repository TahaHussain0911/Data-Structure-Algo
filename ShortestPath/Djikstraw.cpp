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
        if (!array[i]) //0
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
    int v = 3; //source
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
                if (array[v][i] != 0 && distance[v] /*0*/ + array[v][i]  /* array[0][3]=1*/ < distance[i] /*2*/ )  //v=0
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
                if (smallest >= distance[j])
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
    cout<<ignoreline<<endl;
    string veredge;
    getline(Myfile, veredge);
    // 7 5
    // cout<<veredge.length();
    char vevalues[veredge.length()];
    strcpy(vevalues, veredge.c_str());
    // char *ptr; //7 5 9
    int const vertices = atoi(strtok(vevalues, " ")); //7
    int const edges = atoi(strtok(NULL, "")); //5
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
        //0,1,2 chardata[5] char["0",",","1",",","2"]
        int X = atoi(strtok(chardata, ",")); //0
        int Y = atoi(strtok(NULL, ",")); //1
        int value = atoi(strtok(NULL, ""));  //2
        if (value == 0)
        {
            arr[X][Y] = 1;
        }
        else
        {
            arr[X][Y] = value;
            // arr[Y][X]=value;
        }
    }
    Myfile.close();
    // Outdegree(arr, vertices);
    // Indegree(arr, vertices);
    // DisplayArray(arr, vertices);
    Djikstraw(arr, vertices);
}