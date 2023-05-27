//FFig.19.04:fig.19_04.cpp
//BinarySearch test program
#include<iostream>
#include"BinarySearch.h"
using namespace std;

int main()
{
    int searchInt; //searchKey
    int position;  //location of search key in vector

    //create vector and output it
    BinarySearch searchVector(15);
    searchVector.displayElements();

    //get input form user
    cout<<"\n\nPlease enter an integer value(-1 to quit): ";
    cin>>searchInt; //read an int from user
    cout<<endl;

    //repestedly input an integer; -1 terminates the program
    while(searchInt!=-1)
    {
        //use binary search to try to find integer
        position=searchVector.binarySearch(searchInt);

        //return value -1 indicates integer was not found
        if(position==-1)
            cout<<"The integer "<<searchInt<<" was not found\n";
        else
            cout<<"The integer "<<searchInt
            <<" was found in position "<<position<<"\n";

        //get input from user
    cout<<"\n\nPlease enter an integer value(-1 to quit):";
    cin>>searchInt;
    cout<<endl;
    } //end while


} //end main
