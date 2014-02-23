
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
    orderedList();
    void insert(const T& item);
    bool find(const T& item) const;
    string toString() const;
private:
    std::vector<T> container;
    typename std::vector<T>::iterator it;
};
#endif /* ORDEREDLIST_H */

// constructor
template <class T>
orderedList<T>::orderedList(){
}

/**
* inserts item in list in order without using vector::sort()
* (alphabetical or numerical depending on type)
* @param T& item the item to insert
*/
template <class T>
void orderedList<T>::insert(const T& item){
    bool inserted = false;

    //if container is empty, add item automatically
    if(container.size() == 0){
        container.push_back(item);
        return;
    }
    // insert item after largest value is found (using iterator)
    for(it=container.begin(); it < container.end() && !inserted; it++){
        if (*it > item){
            inserted = true;
            container.insert(it, item);
        }
    }
    // if the item being inserted is larger than the largest element
    // add item to the end of the container
    if( !inserted ){
        container.push_back(item);
    }
    return;
}

/**
* returns true if item exists in list
* @param T& item
* @return true if found, false if not found
*/
template <class T> 
bool orderedList<T>::find(const T& item) const{
    for(unsigned int i=0; i<container.size(); i++){
        if( container[i] == item){
            return true;
        }
    }
    return false;
}

/*
* puts all of the items in a string with newlines in between each
* @return string of items
*/
template <class T> 
string orderedList<T>::toString() const{
    ostringstream os;
    int size = container.size();
    string str= "";

    for(int i=0; i< size; i++){
        // change any type read to string
        os << container[i];

        //add string to accumulation
        str = str + os.str() + "\n";

        // reset string buffer
        os.str("");
    }
    return str;

}
