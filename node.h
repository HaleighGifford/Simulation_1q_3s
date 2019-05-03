//****************************************************************************************************
//
//		File:					node.h
//		
//		Student:				Haleigh Cates
//
//		Assignment:	 			Program  #13
//
//		Course Name:			Data Structures I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					December 12, 2018
//
//
//		This program determines how long it takes to serve all arriving 
//			customers using one queue and 3 servers.
//
//		Other files required:	
//								queue.h
//								customer.h
//								server.h
//								sim1q3s.cpp
//								customerList.txt
//								trace.txt								
//								assumptions.txt
//		
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE> * next;
	Node<TYPE> * prev;

	Node();
	Node(const TYPE & d, Node<TYPE> * n = nullptr, Node<TYPE> * p = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> ::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> ::Node(const TYPE & d, Node<TYPE> * n, Node<TYPE> * p)
{
	data = d;
	next = n;
	prev = p;
}

//****************************************************************************************************

#endif

