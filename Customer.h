#pragma once
#include <string>
#include <iostream>
//#include "QueueType.h"

using namespace std;
class Customer {
	string name;
	string id;
	string address;
	string phone;
	string rank;
	//QueueType<string> rentedVideos;
public:
	Customer();
	Customer(string, string, string, string, string);
	void newCustomer();
	void displayAllInformation();
	void setName(string);
	string getName();
	void setId(string id);
	string getId();
	void setRank(string rank);
	string getRank();
	void print();

};
