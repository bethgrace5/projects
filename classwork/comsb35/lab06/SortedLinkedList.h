/**
 * SortedLinkedList is a template for a class that stores data of type T in a
 * singly-linked list that is always in kept in order. It is assumed that items
 * of type T can be compared with ==, != and <=
 *
 * @author 	Hal Mendoza
 * Course: 	COMS B35
 * Created: 	March 7, 2014
 * Source File: SortedLinkedList.h
*/


#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_
#include <iostream>

template<typename T>
class SortedLinkedList {
private:
	struct Node {
		T element;
		Node *next;
	};
	Node *head; // head node of the list
	long size; // number of nodes in the list
public:
	SortedLinkedList() {
		// Dummy node reduces need for special cases - does not store data
		head = new Node;
		head->next = 0;
		size = 0;
	}
	~SortedLinkedList();

	/**
	 * Adds item to the list in the proper place - no duplicates allowed
	 * If item already exists in list, add() silently does nothing
	 * @param item - item to add to list
	 */
	void add(const T item);

	/**
	 * Removes all elements from list that match item. Does nothing if item
	 * is not in list
	 * @param item - item to remove from list
	 */
	void remove(const T item);

	/**
	 * Searches for item in list
	 * @param item - item to search for
	 * @return true if item exists in list, false otherwise
	 */
	bool exists(const T item) const;

	friend std::ostream& operator<<(std::ostream& out, const SortedLinkedList<T>& x) {
		for (Node *n = x.head->next; n != 0; n = n->next)
			out << (n == x.head->next ? "" : "->")<< n->element;
		return out;
	}
public:
	void mystery() {mystery(head->next);}
private:
	void mystery(Node *node) {
		if (node == 0)
			return;
		mystery(node->next);
		std::cout << node->element << std::endl;
	}

};
#include "SortedLinkedList.cpp"
#endif /* SORTEDLINKEDLIST_H_ */
