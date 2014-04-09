/**
*  program displays discrepancies in sorting algorithms
*  @author         Bethany Armitage
*  course:         COMS B35
*  created:        Thu 04/03/2014 
*  source file:    sortExploration.cpp
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
using namespace std;

/*
* partitions a list into halves
* @param list the list to sort
* @param &compare count of comparisons used in algorithm
* @param &assign count of assignments used in algorithm
* @return smallIndex the small index
*/
template <class T>
int partition(T list[], int first, int last, int &compare, int &assign);
/** recursive quick sort algorithm
* @param list the list to sort
* @param first the first index
* @param last the last index
* @param &compare count of comparisons used in algorithm
* @param &assign count of assignments used in algorithm
*/
template <class T>
void recQuickSort(T list[], int first,int last, int &compare, int &assign);

/** sorts an array by using the quick sort algorithm
* @param list the list to sort
* @param length the length of the list
* @param &compare count of comparisons used in algorithm
* @param &assign count of assignments used in algorithm
*/
template <class T>
void quickSort(T list[], int length, int &compare, int &assign);

/** sorts an array by using the insertion sort algorithm
* @param list the list to sort
* @param length the length of the list
* @param &compare count of comparisons used in algorithm
* @param &assign count of assignments used in algorithm
*/
template <class T>
void insertionSort(T list[], int length, int &compare, int &assign);

/** 
* @param list the list to search for minLocation
* @param first the first index
* @param last the last index
* @param &compare count of comparisons used in algorithm
* @param &assign count of assignments used in algorithm
* @return minIndex the minimum index
*/
template <class T>
int minLocation(T list[], int first, int last, int &compare, int &assign);

/** swaps two elements
* @param first the first element
* @param second the second element
* @param &compare count of comparisons used in algorithm
* @param &assign count of assignments used in algorithm
*/
template <class T>
void swap(T list[], int first, int second, int &compare, int &assign);

/** sorts an array by using the selection sort algorithm
* @param list the list to sort
* @param length the length of the list
* @param &compare count of comparisons used in algorithm
* @param &assign  count of assignments used in algorithm
*/
template <class T>
void selectionSort(T list[], int length, int &compare, int &assign);

/** sorts an array by using the bubble sort algorithm
* @param list the list to sort
* @param length the length of the list
* @param &compare count of comparisons used in algorithm
* @param &assign  count of assignments used in algorithm
*/
template <class T>
void bubbleSort(T list[], int length, int &compare, int &assign);
//end function prototypes


int main(){
    //variable declarations
    int bubbleSortArray    [5000];
    int quickSortArray     [5000];
    int selectionSortArray [5000];
    int insertionSortArray [5000];
    int randomNumber;
    int compare;
    int assign;
    //end variable declarations


    //print chart header
    cout << "Sort Type/run   #comparisons   #Assignments\n";
   
    for(int i=0; i<3; i++){
        cout << "-------------------------------------------------\n";

        //initialize each array with list of random integers [0, 20000]
        for(int j=0; j< 5000; j++){
            randomNumber = rand() %20000;

            bubbleSortArray   [j] = randomNumber;
            selectionSortArray[j] = randomNumber;
            insertionSortArray[j] = randomNumber;
            quickSortArray    [j] = randomNumber;
        }

        //clear compare and assign
        compare = 0;
        assign = 0;

        //call bubble sort on array
        bubbleSort(bubbleSortArray, 5000, compare, assign);
        printf("     Bubble/%d %14d %14d\n", i, compare, assign);

        //reset compare and assign
        compare = 0;
        assign = 0;

        //call Selection sort on array
        selectionSort(selectionSortArray, 5000, compare, assign);
        printf("  Selection/%d %14d %14d\n", i, compare, assign);

        //reset compare and assign
        compare = 0;
        assign = 0;

        //call insertion sort on array
        insertionSort(insertionSortArray, 5000, compare, assign);
        printf("  Insertion/%d %14d %14d\n", i, compare, assign);

        //reset compare and assign
        compare = 0;
        assign = 0;

        //call quick sort on array
        quickSort(quickSortArray, 5000, compare, assign);
        printf("      Quick/%d %14d %14d\n", i, compare, assign);
    }

    return 0;
} //end main

template <class T>
void bubbleSort(T list[], int length, int &compare, int &assign)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration; index++)
        {
            compare++;
            if (list[index] > list[index + 1])
            {
                assign+=3;
                T temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
} //end bubbleSort

template <class T>
void selectionSort(T list[], int length, int &compare, int &assign)
{
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1, compare, assign);
        swap(list, loc, minIndex, compare, assign);
    }
    assign -= 3;
} //end selectionSort

template <class T>
void swap(T list[], int first, int second, int &compare, int &assign)
{
    T temp;
    assign += 3;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;


} //end swap

template <class T>
int minLocation(T list[], int first, int last, int &compare, int &assign)
{
    int loc, minIndex;

    minIndex = first;

    for (loc = first + 1; loc <= last ; loc++){
        if (list[loc] < list[minIndex]){
            minIndex = loc;
        }
            compare++;
    }

    return minIndex;
} //end minLocation

template <class T>
void insertionSort(T list[], int length, int &compare, int &assign)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length;
                                  firstOutOfOrder++){
        compare++;
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            T temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;
            assign+=2;

            do
            {
                compare++;
                assign++;
                list[location] = list[location - 1];
                location--;

            } while(location > 0 && list[location - 1] > temp);
            
            list[location] = temp;
            assign++;
        }
    }
} //end insertionSort

template <class T>
void quickSort(T list[], int length, int &compare, int &assign)
{
    recQuickSort(list, 0, length - 1, compare, assign);
} //end quickSort

template <class T>
void recQuickSort(T list[], int first, int last, int &compare, int &assign)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition(list, first, last, compare, assign);
        recQuickSort(list, first, pivotLocation - 1, compare, assign);
        recQuickSort(list, pivotLocation + 1, last, compare, assign);
    }
} //end recQuickSort

template <class T>
int partition(T list[], int first, int last, int &compare, int &assign)
{
    T pivot;

    int index, smallIndex;

    swap(list, first, (first + last) / 2, compare, assign);

    assign++;
    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            compare++;
            smallIndex++;
            swap(list, smallIndex, index, compare, assign);
        }
        else{
            compare++;
        }

    swap(list, first, smallIndex, compare, assign);

    return smallIndex;
} //end partition
