#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>

using namespace std;
//function prototypes
template <class elemType>
int partition(elemType list[], int first, int last);

template <class elemType>
void recQuickSort(elemType list[], int first, int last);

template <class elemType>
void quickSort(elemType list[], int length, int &compare, int &assign);

template <class elemType>
void insertionSort(elemType list[], int length, int &compare, int &assign);

template <class elemType>
int minLocation(elemType list[], int first, int last);

template <class elemType>
void swap(elemType list[], int first, int second);

template <class elemType>
void selectionSort(elemType list[], int length, int &compare, int &assign);

template <class elemType>
void bubbleSort(elemType list[], int length, int &compare, int &assign);
//end function prototypes

int main(){
   int bubbleSortArray [5000];
   int quickSortArray [5000];
   int selectionSortArray [5000];
   int insertionSortArray [5000];
   int random;
   int compare;
   int assign;

   for(int i=0; i< 5000; i++){
       random = rand() %20000;

       bubbleSortArray   [i] = random;
       selectionSortArray[i] = random;
       insertionSortArray[i] = random;
       quickSortArray    [i] = random;
   }

   //print chart header
   cout << "Sort Type/run   #comparisons   #Assignments\n";
   
    for(int i=0; i<3; i++){
        cout << "-------------------------------------------------\n";

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
 
template <class elemType>
void bubbleSort(elemType list[], int length, int &compare, int &assign)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration;
                            index++)
        {
            if (list[index] > list[index + 1])
            {
                elemType temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
    compare = 0;
    assign = 0;
} //end bubbleSort

template <class elemType>
void selectionSort(elemType list[], int length, int &compare, int &assign)
{
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
    compare = 0;
    assign = 0;
} //end selectionSort

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

template <class elemType>
int minLocation(elemType list[], int first, int last)
{
    int loc, minIndex;

    minIndex = first;

    for (loc = first + 1; loc <= last; loc++)
        if (list[loc] < list[minIndex])
            minIndex = loc;

    return minIndex;
} //end minLocation

template <class elemType>
void insertionSort(elemType list[], int length, int &compare, int &assign)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length;
                                  firstOutOfOrder++)
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            elemType temp = list[firstOutOfOrder];
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

template <class elemType>
void quickSort(elemType list[], int length, int &compare, int &assign)
{
    recQuickSort(list, 0, length - 1);
    compare = 0;
    assign = 0;
} //end quickSort

template <class elemType>
void recQuickSort(elemType list[], int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition(list, first, last);
        recQuickSort(list, first, pivotLocation - 1);
        recQuickSort(list, pivotLocation + 1, last);
    }
} //end recQuickSort

template <class elemType>
int partition(elemType list[], int first, int last)
{
    elemType pivot;

    int index, smallIndex;

    swap(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }

    swap(list, first, smallIndex);

    return smallIndex;
} //end partition


