#include <string>
#include <iostream>
#include "Customer.h"

using namespace std;
Customer::Customer() {
	name = "NA";
	id = "NA";
	address = "NA";
	phone = "NA";
	rank = "NA";
}
Customer::Customer(string name, string id, string address, string phone,string rank) {
	this->name = name;
	this->id = id;
	this->address = address;
	this->phone = phone;
	this->rank = rank;
}
void Customer::newCustomer() {
	system("CLS");
	cout << "~~Creating new customer~~" << endl;
	string name = "";
	string id = "";
	string address = "";
	string phone = "";
	string rank = "Guest";
	cout << "Name: ";
	cin >> name;
	cin.clear();
	cout << "Id: ";
	cin >> id;
	cin.clear();
	cout << "Address: ";
	cin >> address;
	cin.clear();
	cout << "Phone: ";
	cin >> phone;
	this->name = name;
	this->id = id;
	this->address = address;
	this->phone = phone;
	this->rank = rank;
	cout << "Customer created..." << endl;
	system("Pause");
}
void Customer::displayAllInformation() {
	cout << "Name: " << this->name << endl;
	cout << "Id: " << this->id << endl;
	cout << "Address: " << this->address << endl;
	cout << "Phone: " << this->phone << endl;
	cout << this->rank << " member" << endl;
	system("Pause");
}
void Customer::setName(string name) {
	this->name = name;
}
string Customer::getName() {
	return this->name;
}
void Customer::setId(string id) {
	this->id = id;
}
string Customer::getId() {
	return this->id;
}
void Customer::setRank(string rank) {
	this->rank = rank;
}
string Customer::getRank() {
	return this->rank;
}
void Customer::print() {
	cout << "Name: " << this->name << endl;
}
