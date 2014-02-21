
/**
 * orderedList is a container class that can hold a list of any
 * type for which the insertion operator (<<) and the less than
 * operator (<) is defined.
 *
 * @author 		Bethany Armitage
 * Course: 		COMS B35
 * Created: 	Feb 18, 2013
 * Source File: orderedList.h
 */

#ifndef ORDEREDLIST_H_
#define ORDEREDLIST_H_

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


template <class T>
class orderedList {
public:
    void insert(const T& item);
    bool find(const T& item) const;
    string toString() const;
private:
    //friend ostream& operator 
    std::vector<T> container;
    //TODO: helper function to order list? mergesort?
};

#endif /* ORDEREDLIST_H */

/**
* inserts item in list in order
* (alphabetical or numerical depending on type)
* @param T& item the item to insert
* 
*/
template <class T>
void orderedList<T>::insert(const T& item){
    //container.insert(item);
    return;

}

/**
* returns true if item exists in list
* @param T& item
* @return true if found, false if not found
*/
template <class T> 
bool orderedList<T>::find(const T& item) const{
    return std::find(container.begin(), container.end());
}

/*
* puts all of the items in a string with newlines in between each
* @return string of items
*
*/
template <class T> 
string orderedList<T>::toString() const{
    int stop = container.size();
    string tmp;
    for(int i=0; i< stop; i++){
        //concatenate tmp
        tmp += container[i] + "\n";
    }
    //suggested to use ostringstream or stringstream object to
    //accumulate objects in the list
    return tmp;

}



