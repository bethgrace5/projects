
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
#include <sstream>
#include <iostream>

using namespace std;


template <class T>
class orderedList {
public:
    void insert(const T& item);
    bool find(const T& item) const;
    string toString() const;
    void putInOrder();
private:
    std::vector<T> container;
};

#endif /* ORDEREDLIST_H */

/**
* inserts item in list in order
* (alphabetical or numerical depending on type)
* @param T& item the item to insert
*/
template <class T>
void orderedList<T>::insert(const T& item){
    container.push_back(item);
    return;
}

/**
* returns true if item exists in list
* @param T& item
* @return true if found, false if not found
*/
template <class T> 
bool orderedList<T>::find(const T& item) const{
    int stop = container.size();
    for(int i=0; i<stop; i++){
        if( ((T) container.at(i)) == item)
            return true;
        }
    return false;
}

/*
* puts all of the items in a string with newlines in between each
* @return string of items
*/
template <class T> 
string orderedList<T>::toString() const{

    //putInOrder();

    ostringstream os;
    int stop = container.size();
    string tmp= "";
    for(int i=0; i< stop; i++){
        // change any type read to string
        os << container[i];

        //add string to accumulation
        tmp = tmp + os.str() + "\n";

        // reset string buffer
        os.str("");
    }
    return tmp;

}
void putInOrder(){

// put vector in numerical or alphabetical order

}



