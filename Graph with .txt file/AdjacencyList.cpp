#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
struct Source
{
    Source *next;
    int destination;
    int weight;
};
void DisplayArray(Source **array, int size)
{
    // cout<<"hello";
    for (int i = 0; i < size; i++)
    {
        if (array[i] == NULL)
        {
            continue;
        }
        else
        {
            cout << i << "->";
            Source *root = new Source();
            root = array[i];
            while (root->next != NULL)
            {
                cout << root->destination << "," << root->weight << " ";
                root = root->next;
            }
            cout << root->destination << "," << root->weight << endl;
        }
    }
}
void Outdegree(Source **array, int size)
{
    int *OD;
    OD = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (array[i] == NULL)
        {
            OD[i] = 0;
            continue;
        }
        else
        {
            Source *root = new Source();
            root = array[i];
            int count = 1;
            while (root->next != NULL)
            {
                root = root->next;
                count++;
            }
            OD[i] = count;
        }
    }
    cout << "Outdegrees are: ";
    for (int i = 0; i < size; i++)
    {
        cout << OD[i] << " ";
    }
    cout << endl;
}
void Indegree(Source **array, int size)
{
    int *IN;
    IN = new int[size];
    for (int i = 0; i < size; i++)
    {
        IN[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i] == NULL)
        {
            continue;
        }
        else
        {
            Source *root = new Source();
            root = array[i];
            while (root->next != NULL)
            {
                IN[root->destination] += 1;
                root=root->next;
            }
            IN[root->destination] += 1;
        }
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
    Source *graph[vertices];
    // memset(graph,NULL,vertices);
    for (int i = 0; i < vertices; i++)
    {
        graph[i] = NULL;
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
        Source *ptr = new Source();
        ptr->destination = Y;
        ptr->weight = value;
        ptr->next = NULL;
        if (graph[X] == NULL)
        {
            graph[X] = ptr;
        }
        else
        {
            Source *root = new Source();
            root = graph[X];
            while (root->next != NULL)
            {
                root = root->next;
            }
            root->next = ptr;
        }
    }
    Myfile.close();
    DisplayArray(graph, vertices);
    Outdegree(graph, vertices);
    Indegree(graph, vertices);
    return 0;
}