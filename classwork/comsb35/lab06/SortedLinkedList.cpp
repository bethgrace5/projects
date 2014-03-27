/**
* Implements functionality of SortedLinkedList.h
*
* @author:      Bethany Armitage
* Course:       COMS B35
* Created:      Mon 03/10/2014 
* Source File:  SortedLinkedList.cpp
*/
//when using dynamically allocated memory you need...
//destructor, overload assignment, copy constructor
using namespace std;

template <class T>
SortedLinkedList<T>::~SortedLinkedList(){
    // for(node *n=head; n!=0; n->tmp){
        //tmp = n->next
        //delete n;
    //}

    while( exists(head->element) && size > 1){
        remove( head->element );
    }
    head = NULL;
}

template <class T>
void SortedLinkedList<T>::add(const T item){

    // avoid adding duplicates
    if( exists(item)){ return; }

    // case for empty list
    if (size == 0 ){
        Node *temp = new Node;
        temp->element = item;
        temp->next = NULL;
        head->next = temp;
        size++;
        return;
    }

    Node *walk = head;  //increments at beginning of loop
    Node *follow = head;//increments at end of loop
    while ( (walk = walk->next) ){
        
        // add item in ascending order
        if(walk->element > item){
            Node *temp = new Node;
            temp->next = walk;
            temp->element = item;
            follow->next = temp;
            size++;
            return;
        }
        // case for item greater than all others (end of list)
        if(walk->next == NULL){
            Node *temp = new Node;
            temp->next = NULL;
            temp->element = item;
            walk->next = temp;
            return;
        }
        follow = follow->next;
    }
}

template <class T>
void SortedLinkedList<T>::remove(const T item){

    // case for empty list
    if( head == NULL ){ return; }

    Node *walk = head;  //increments at beginning of loop
    Node *follow = head;//increments at end of loop
    while ( (walk = walk->next) ){

        if (walk->element == item){
            follow->next = walk->next;
            delete walk;
            size--;
        }
        follow = follow->next;
    }
    return;
}

template <class T>
bool SortedLinkedList<T>::exists(const T item) const{


    for(Node *walk = head; walk->next; walk = walk->next){
        if (walk-> element == item){
            return true; 
        }
    }
    //else
    return false;
}
