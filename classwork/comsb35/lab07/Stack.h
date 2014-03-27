
#ifndef H_Stack
#define H_Stack 

//#include "linkedList.h"
#include "stackADT.h"
#include <iostream>
#include <string>

template <class Type>
struct Node{
    Type info;
    Node<Type> *link;
};

template <class Type>
class Stack: public stackADT<Type>{

    Node<Type> *stackTop;


public:
/*
* Constructor
*/
    template <Type>
    Stack(){
        stackTop = NULL;
    }

       //Method to initialize the stack to an empty state.
       //Postcondition: Stack is empty
    template <Type>
    void initializeStack(){
       Node<Type> *temp;

       while( stackTop != NULL ){
           temp = stackTop;
           stackTop = stackTop->link;
           delete temp;
       }
    }

      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.
    template <Type>
    bool isEmptyStack() const{
        return (stackTop == NULL);
    }

      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //               otherwise returns false.
    template <Type>
    bool isFullStack() const{
        return false;
    }

      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem
      //               is added to the top of the stack.
    template <Type>
    void push(const Type& newItem){
        Node<Type> *newNode = new Node<Type>;

        newNode->info = newItem;
        newNode->link = stackTop;

        stackTop = newNode;
    }

      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program
      //               terminates; otherwise, the top element
      //               of the stack is returned.
    template <Type>
    Type top() const{
        return stackTop->info;
    }

      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top
      //               element is removed from the stack.
    template <Type>
    void pop(){
        if( stackTop != NULL ){
            stackTop=stackTop->link;
        }
        else 
            std::cout << "cannot remove from empty stack" << std::endl;
    }

    /**
    * Analyzes input string for grouping-symbol (parenthesis, square
    * brackets, and curly braces) mismatches and returns the index of
    * the first mismatch, or -1 if no mismatch is found. If not all 
    * open symbols have matches, reutrn length of input string.
    *
    * @param str string to analyze
    * @return either index of first mismatch, length of string if
    * closing grouping symbol is missing, or -1 if mo mismatch found. 
    */

};

#endif
