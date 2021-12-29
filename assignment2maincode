#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "CustomerListType.h"
#include "UnorderedLinkedListType.h"

using namespace std;



class videoStore {
	//int numberOfVideos;
	int numberOfCustomers;
	Customer customer; //temp customer
	vector<Customer> customerList;
public:
	void showCustomerDetails() {
		system("CLS");
		int customerId;
		for (int i = 0; i < customerList.size(); i++) {
			cout << "~~ Customers ~~" << endl;
			cout << "Customer [" << i << "]: " << customerList[i].getName() << endl;
		}
		cout << "End of list" << endl;
		cout << endl;
		cout << "Show customer: ";
		cin >> customerId;
		system("CLS");
		customerList[customerId].displayAllInformation();
		cin.clear();
	}
	void showCustomerGroupDetails() {
		system("CLS");
		int Group;
		cout << "[1] Guest Customer\n";
		cout << "[2] Regular Customer\n";
		cout << "[3] VIP Customer\n";
		cin >> Group;
		cin.clear();
		switch (Group) {
		case 1:
			cout << "~~ Guest Customers ~~" << endl;
			for (int i = 0; i < customerList.size(); i++) {
				if (customerList[i].getRank() == "Guest") {
					customerList[i].displayAllInformation();
				}
			}
			break;
		case 2:
			cout << "~~ Regular Customers ~~" << endl;
			for (int i = 0; i < customerList.size(); i++) {
				if (customerList[i].getRank() == "Regular") {
					customerList[i].displayAllInformation();
				}
			}
			break;
		case 3:
			cout << "~~ VIP Customers ~~" << endl;
			for (int i = 0; i < customerList.size(); i++) {
				if (customerList[i].getRank() == "VIP") {
					customerList[i].displayAllInformation();
				}
			}
			break;
		}
	}
	void showAllCustomerDetails() {
		system("CLS");
		cout << "~~ Customers ~~" << endl;
		for (int i = 0; i < customerList.size(); i++) {
			customerList[i].displayAllInformation();
		}
	}
	void createNewCustomer() {
		customer.newCustomer();
		customerList.push_back(customer);
	}
	void PromoteCustomer() {
		system("CLS");
		int customerId;
		cout << "~~ Customers ~~" << endl;
		for (int i = 0; i < customerList.size(); i++) {
			//if (customerList[i].getRent()  >= 3) {
				cout << "Customer [" << i << "]: " << customerList[i].getName() << "Returned videos: " /* << customerList[i].getRent() */ << "Rank :" << customerList[i].getRank() << " member" << endl;
			//}
			
		}
		cout << "Choose Customer to promote: ";
		cin >> customerId;
		cout << "\n";
		system("CLS");
		if (customerList[customerId].getRank() == "Guest") {
			customerList[customerId].setRank("Regular");
		}
		else if (customerList[customerId].getRank() == "Regular") {
			customerList[customerId].setRank("VIP");
		}
		else {
			cout << "Already VIP customer";
		}
		cin.clear();
	}
	videoStore() {
		//numberOfVideos = 0;
		numberOfCustomers = 0;
	}
};

int main() {
	videoStore store;
	bool inUse = true;
	int userInp;
	while (inUse) {
		system("CLS");
		cout << "Welcome to Genie’s video store\n";
		cout << "Enter an option below.\n";
		cout << "1. Add a new item, update or delete an existing item\n";
		cout << "2. Add new customer or update an existing customer \n";
		cout << "3. Promote an existing customer\n";
		cout << "4. Rent an item\n";
		cout << "5. Return an item\n";
		cout << "6. Display all items\n";
		cout << "7. Display out-of-stock items\n";
		cout << "8. Display all customers\n";
		cout << "9. Display group of customers\n";
		cout << "10. Search items or customers\n";
		cout << endl;
		cout << "Choose any option [-1 to exit]: ";
		cin >> userInp;
		cin.clear();
		switch (userInp) {
		case 1:
			
			break;
		case 2:
			store.createNewCustomer();
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			store.showAllCustomerDetails();
			break;
		case 9:
			store.showCustomerGroupDetails();
			break;
		case 10:
			store.showCustomerDetails();
			break;
		case -1:
			inUse = false;
			break;
		default:
			cout << "Error... exiting progrom" << endl;
			inUse = false;
			break;
		}
	}
	system("Pause");
	return 0;
}
