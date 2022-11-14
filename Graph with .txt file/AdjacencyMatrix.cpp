#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
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
    // int **temparr;
    // *temparr=new int[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     temparr[i]=new int[5];
    // }
    // temparr[0][1]=2;
    // Outdegree(arr, vertices);
    // Indegree(arr, vertices);
    cout << "Hello world" << endl;
    // cout<<arr[0][1];
    cout << vertices;
    int i=0;
    while (i<vertices)
    {
        // for (int j = 0; j < 7; j++)
        // {
            cout << "ndwaniudaw" << endl;
        // }
        i++;
    }
    return 0;
}