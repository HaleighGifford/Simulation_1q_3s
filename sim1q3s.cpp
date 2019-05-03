//****************************************************************************************************
//
//		File:					sim1q3s.cpp
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
//								customer.h
//								server.h
//								queue.h
//								customerList.txt
//								trace.txt								
//								assumptions.txt
//		
//****************************************************************************************************

#include <iostream>
#include <fstream>
using namespace std;
#include "queue.h"
#include "customer.h"
#include "server.h"

//****************************************************************************************************

int fillCustomerArray(Customer cust[]);
void processCustomers(int & currCust, int totalCust, ofstream & trace, 
					  Queue<Customer> & q, Customer cust[], int time);
void processServers(ofstream & trace, Queue<Customer> & q, Server serv[], 
					int time);
bool isAllDone(int currCust, int totalCust, Queue<Customer> & q, 
			   Server serv[]);

//****************************************************************************************************

int main()
{
	int time = -1,
		totalCust,
		currCust = 0;
	Customer cust[100];
	Server serv[3];
	Queue<Customer> q;
	ofstream trace("trace.txt");

	totalCust = fillCustomerArray(cust);

	while (!isAllDone(currCust, totalCust, q, serv))
	{
		time++;
		trace << "t = " << time << endl;
		processCustomers(currCust, totalCust, trace, q, cust, time);
		processServers(trace, q, serv, time);
		trace << endl;
	}

	cout << "All customers processed in " << time << " minutes.";

	trace.close();

	return 0;
}

//****************************************************************************************************

int fillCustomerArray(Customer cust[])
{
	int count = 0;
	Customer customer;
	ifstream custFile;
	custFile.open("customerList.txt");

	while (custFile >> cust[count].id)
	{
		custFile >> cust[count].arrivalTime;
		custFile >> cust[count].serviceTime;
		count++;
	}

	custFile.close();

	return count;
}

//****************************************************************************************************

void processCustomers(int & currCust, int totalCust, ofstream & trace, 
					  Queue<Customer> & q, Customer cust[], int time)
{
	Customer c;

	while ((currCust <= totalCust) && (cust[currCust].arrivalTime == time))
	{
		q.enqueue(cust[currCust]);
		trace << "cust-id #" << cust[currCust].id << " added to Q" << endl;
		currCust++;
	}
}

//****************************************************************************************************

void processServers(ofstream & trace, Queue<Customer> & q, Server serv[], 
					int time)
{
	Customer customer;

	for (int i = 0; i < 3; i++)
	{
		if ((!serv[i].busy) || (serv[i].endTime == time))
		{
			if (q.dequeue(customer))
			{
				serv[i].custId = customer.id;
				serv[i].busy = true;
				serv[i].endTime = customer.serviceTime + time;

				trace << "S" << i 
					  << " start serving cust-id #" << serv[i].custId 
					  << ", service length = " << customer.serviceTime 
					  << ", service ends at t = " << serv[i].endTime << endl;
			}
			else
			{
				trace << "S" << i << " not busy" << endl;
				serv[i].busy = false;
			}
		}
		else
		{
			trace << "S" << i 
				  << " serving cust-id #" << serv[i].custId 
				  << " until t = " << serv[i].endTime << endl;
		}
	}
}

//****************************************************************************************************

bool isAllDone(int currCust, int totalCust, Queue<Customer> & q, Server serv[])
{
	return ((currCust >= totalCust) && (q.isEmpty()) && 
		    (!serv[0].busy) && (!serv[1].busy) && (!serv[2].busy));
}

//****************************************************************************************************
