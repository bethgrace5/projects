/**
 *  Simulates a stack using linked lists
 *  @author         Bethany Armitage
 *  course:         COMS B35
 *  created:        Thu 03/20/2014 
 *  source file:    Stack.h 
 */

#ifndef H_Stack
#define H_Stack 
#include "stackADT.h"
#include "unorderedLinkedList.h"

template <class Type>
class Stack: public stackADT<Type>{
    
public:
    //constructor
    Stack();
    //destructor
    ~Stack();
    /*Method to initialize the stack to an empty state.
    */
    void initializeStack();

    /*Function to determine whether the stack is empty.
    * @return true if stack is empty, false if stack is not empty.
    */
    bool isEmptyStack() const;

    /*Function to determine whether the stack is full.
    * @return false stack is never full.
    */
    bool isFullStack() const;

    /*Function to add newItem to the stack.
    * @param Type& newItem the item to be added.
    */
    void push(const Type& newItem);

    /*Function to return the top element of the stack.
    * @return the top element of Type in list
    */
    Type top() const;

    /*Function to return the top element of the stack.
    */
    void pop();

private:
    unorderedLinkedList<Type> list;
};
#endif
    //constructor
    template <class Type> Stack<Type>::Stack(){

    }
    //destructor
    template <class Type> Stack<Type>::~Stack(){
        list.destroyList();
    }

    template <class Type> void Stack<Type>::initializeStack(){
       list.initializeList();
       return;
    }

    template <class Type> bool Stack<Type>::isEmptyStack() const{
       return list.isEmptyList();
    }

    template <class Type> bool Stack<Type>::isFullStack() const{
        return false;
    }

    template <class Type> void Stack<Type>::push(const Type& newItem){
        list.insertFirst(newItem);
    }

    template <class Type> Type Stack<Type>::top() const{
        return list.front();
    }

    template <class Type> void Stack<Type>::pop(){
        if( !list.isEmptyList() ){
           list.deleteNode(list.front()); 
        }
        else 
            std::cout << "cannot remove from empty stack" << std::endl;
        return;
    }
