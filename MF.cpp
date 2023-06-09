//Fig.19.3:BinarySearch.cpp
//BinarySearch class MF definitions
#include<iostream>
#include<cstdlib> //prototypes fpr functions srand and rand
#include<ctime> //prototype for function time
#include<algorithm> //prototype for sort function
#include"BinarySearch.h"
using namespace std;

//constructor initializes vector with random ints and sorts the vector
BinarySearch::BinarySearch(int vectorSize)
{
    size=(vectorSize>0 ? vectorSize :10); //validate vectorSize
    srand(time(0)); //seed using current time

    //fill vector with random ints in range 10-99
    for(int i=0; i<size; ++i)
        data.push_back(10+rand()%90); //10-99

    sort(data.begin(), data.end()); //sort the data
} //end BinarySearch constructor

//perform a binary search on the data
int BinarySearch::binarySearch(int searchElement)const
{
    int low=0; //low end of the search data
    int high=size-1; //high end of the search area
    int middle=(low+high+1)/2; //middle element
    int location=-1; //return value; -1 if not find

    do //loop to search for element
    {
        //print remaining elements of vector to be searched
        displaySubElements(low,high);

        //output spaces for alignment (выравнивание, сравнение)
        for(int i=0; i<middle; ++i)
            cout<<"  ";

        cout<<" * "<<endl; //indicate current middle




        //if the element is found at the middle
        if(searchElement==data[middle])
            location=middle;  //location is the curent middle
        else if(searchElement<data[middle]) //middle is too high
            high=middle-1; //eliminate the higher half
        else //middle element is too low
            low=middle+1; //eliminate the lower half

    middle=(low+high+1)/2; //recalculate the middle
    } while((low<=high) && (location==-1));

    return location; //return location of search key
} //end function BinarySearch

//display values in vector
void BinarySearch::displayElements()const
{
    displaySubElements(0,size-1);
} //end function displayElements

void BinarySearch::displaySubElements(int low, int high)const
{
    for(int i=0; i<=low;++i)//output spaces for alignment
        cout<<" ";

    for(int i=low; i<=high; ++i) //output elements left in vector
        cout<<data[i]<<" ";

    cout<<endl;
} //end function displaySubElements





