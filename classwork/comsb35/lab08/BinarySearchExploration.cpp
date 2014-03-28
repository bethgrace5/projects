/**
* Shows that the average number of comparisons for a binary search 
* algorithm approaches 2log(N)-3
*
* @author       Bethany Armitage
* Course:       Comsb35
* Created:      Fri 03/28/2014 
* Source File:  BinarySearchExploration.cpp 
*/

#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

/**
* This function counts the number of comparisons done in a binary 
* search algorithm
* @param list[] array to search through
* @param length the length of the array
* @param item the item to search for
* @return count the count of comparisons done to find item in list[]
*/
template <class elemType>
int BinarySearchCount(const elemType list[], int length, 
                 const elemType& item)
{
    int count = 0;
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        count++;

        if (list[mid] == item)
            return count;

        else if (list[mid] > item){
            count++;
            last = mid - 1;
        }    
        else{
            count++;
            first = mid + 1;
        }
    }
    return count;
} //end binarySearch

int main(){

    int totalComparisons = 0;
    double avgComparisons;
    int numbers[131072];
    int n_Squared = 0;

    //print chart header
    cout << "\n     N | #Comparisons| Avg #Comparisons | 2log(N) - 3\n";
    cout <<  " -----------------------------------------------------\n";

    // initialize array with range [0, 2^17]
    for(int i=0; i<131073; i++)
        numbers[i] = i;

    for(int n=1; n<18; n++){
        n_Squared = pow(2,n);

        //run binary search for each value from 0 to 2^n
        for(int i=0; i<n_Squared; i++)
            totalComparisons += BinarySearchCount(numbers, n_Squared, i); 

        //calculate average number of comparisons
        avgComparisons = (double) totalComparisons/n_Squared;

        //print chart
        printf("%7d| %12d| %16f | %f\n", n_Squared, totalComparisons, 
             avgComparisons ,(2*(log(n_Squared)/log(2))-3));

        //reset totalComparisons
        totalComparisons = 0;

        //reset avgComparisons
        avgComparisons = 0;
    }

    return 0;

} // end main
