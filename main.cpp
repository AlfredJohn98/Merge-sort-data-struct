#include<iostream>
#include<fstream>

#include<conio.h>
#include<cstring>
#include<stdlib.h>

using namespace std;

void merging(int *,int, int , int );

#define size 10

int sorting_array[size], a, b;

void merge_sorting(int *array_ptr, int lowest, int highest)
{
    int median;

    if (lowest <highest){

        median=(lowest+highest)/2;

        merge_sorting(array_ptr,lowest,median);

        merge_sorting(array_ptr,median+1,highest);


        merging(array_ptr,lowest,highest,median);

        cout<<endl;

        cout << "Merge Sorting : " <<" ";

        for (int i = 0; i < size; i++)

        {
            cout << sorting_array[i] <<"\t";
        }

        }
    }

void merging(int *arr, int lowest, int highest, int median)
{
    int i, c,element;

    int index[50];

    i = lowest;
    element = lowest;

    c = median + 1;

    while (i <= median && c <=highest)
        {
        if (arr[i] < arr[c])
        {
            index[element] = arr[i];
            element++;
            i++;
        }
        else
        {
            index[element] = arr[c];
            element++;
            c++;
        }
    }

    while (i <= median)
    {
        index[element] = arr[i];
        element++;
        i++;
    }

    while (c <=highest)
    {
        index[element] = arr[c];
        element++;
        c++;
    }

    for (i = lowest; i < element; i++)
    {
        arr[i] = index[i];

    }
}

int main()
{

    ifstream input;

    input.open("data.txt", ios::in);

    cout<<endl;

    cout<<"Merge Sorting Steps"<<endl;
    cout<<"---------------------------"<<endl;

    if(input.good())
    {

      for (int i = 0; i < size; i++)
      {
            input >> sorting_array[i];
      }

    }

    merge_sorting(sorting_array, 0, size -1);

    cout<<endl;
    cout<<endl;

    cout<<"The sorted array after merge sorting"<<endl;
    cout<<"-----------------------------------"<<endl;

    cout<<endl;

    cout<<"Array : ";

    for (int i = 0; i < size; i++)
    {
        cout<<sorting_array[i]<<"\t";
    }

    cout<<endl;
}


