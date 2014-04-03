#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>

using namespace std;
//function prototypes
template <class T>
int partition(T list[], int first, int last, int &compare, int &assign);

template <class T>
void recQuickSort(T list[], int first, int last, int &compare, int &assign);

template <class T>
void quickSort(T list[], int length, int &compare, int &assign);

template <class T>
void insertionSort(T list[], int length, int &compare, int &assign);

template <class T>
int minLocation(T list[], int first, int last, int &compare, int &assign);

template <class T>
void swap(T list[], int first, int second, int &compare, int &assign);

template <class T>
void selectionSort(T list[], int length, int &compare, int &assign);

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
        // does there need to be a new list for each 'run'?
        for(int j=0; j< 5000; j++){
            randomNumber = rand() %20000;

            bubbleSortArray   [j] = randomNumber;
            selectionSortArray[j] = randomNumber;
            insertionSortArray[j] = randomNumber;
            quickSortArray    [j] = randomNumber;
        }

        //call bubble sort on array
        bubbleSort(bubbleSortArray, 5000, compare, assign);
        printf("     Bubble/%d %14d %14d\n", i, compare, assign);

        //call Selection sort on array
        selectionSort(selectionSortArray, 5000, compare, assign);
        printf("  Selection/%d %14d %14d\n", i, compare, assign);

        //call insertion sort on array
        insertionSort(insertionSortArray, 5000, compare, assign);
        printf("  Insertion/%d %14d %14d\n", i, compare, assign);

        //call quick sort on array
        quickSort(quickSortArray, 5000, compare, assign);
        printf("      Quick/%d %14d %14d\n", i, compare, assign);
    }
    return 0;
}
/*
* sorts a list of 
*/
//why aren't there any assignments counted in bubbleSort?
template <class T>
void bubbleSort(T list[], int length, int &compare, int &assign)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration;
                            index++)
        {
            if (list[index] > list[index + 1])
            {
                compare++;
                T temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
            else
                compare++;
        }
    }
    assign = 0;
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
    compare = 0;
    assign = 0;
} //end selectionSort

template <class T>
void swap(T list[], int first, int second, int &compare, int &assign)
{
    T temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

template <class T>
int minLocation(T list[], int first, int last, int &compare, int &assign)
{
    int loc, minIndex;

    minIndex = first;

    for (loc = first + 1; loc <= last; loc++)
        if (list[loc] < list[minIndex])
            minIndex = loc;

    return minIndex;
} //end minLocation

template <class T>
void insertionSort(T list[], int length, int &compare, int &assign)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length;
                                  firstOutOfOrder++)
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            T temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;
            } while(location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
    compare = 0;
    assign = 0;
} //end insertionSort

template <class T>
void quickSort(T list[], int length, int &compare, int &assign)
{
    recQuickSort(list, 0, length - 1, compare, assign);
    compare = 0;
    assign = 0;
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

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index, compare, assign);
        }

    swap(list, first, smallIndex, compare, assign);

    return smallIndex;
} //end partition


