//****************************************************************************************************
//
//		File:					customer.h
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
//								node.h
//								queue.h
//								server.h
//								sim1q3s.cpp
//								customerList.txt
//								trace.txt								
//								assumptions.txt
//		
//****************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

//****************************************************************************************************

struct Customer
{
	int id;
	int arrivalTime;
	int serviceTime;

	Customer();
};

//****************************************************************************************************

Customer::Customer()
{
	id = 0;
	arrivalTime = 0;
	serviceTime = 0;
}

//****************************************************************************************************

#endif

