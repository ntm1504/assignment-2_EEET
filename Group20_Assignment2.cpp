#include "Item.h"
#include "CommonFunction.h"
#include <fstream>
#include <vector>
#include <sstream>
//using namespace std;
//Read file-----------------------------------------------------------------------
//Remove all instances of items in database
void DeleteItem (const string fileName,string itemId)
{
    //Initualize
    string line;
    const char* tempName="temp.txt";
    //open file 
    ifstream inFile(fileName,ios::in);
    ofstream outFile(tempName,ios::app);//create a new file and replace the current
    //check if file has open successfully
    if(!inFile||!outFile)
    {
        cerr<<"Fail to open file for reading"<<endl;
        return;//is a empty list
    }
    //ignore the first line
    string delimiter=",";
    int deleteLineCount=0;
   while(getline(inFile,line))
   {
       //get line by line
       //extract id from line 
       int firstComma=line.find(delimiter);
       string currentId=line.substr(0,firstComma);
       //compare with item id to remove
       if(itemId==currentId)
       {
           //this item needed to be remove
           cout<<"Deleting Item:"<<itemId<<endl;
           deleteLineCount++;
       }
       else{
           //add line to file
           outFile<<line<<endl;
       }
   }
   //check if any item has been deleteds
   if(deleteLineCount==0)
   {
       cout<<"Cannot find the item"<<endl;
   }
    //close file
    inFile.close();
    outFile.close();
    //replace file
    remove(fileName.c_str());
    rename(tempName,fileName.c_str());
}
//Update Item
void UpdateItem(string fileName,Item item)
{
    //Initualize
    string line;
    const char* tempName="temp.txt";
    //open file 
    ifstream inFile(fileName,ios::in);
    ofstream outFile(tempName,ios::app);//create a new file and replace the current
    //check if file has open successfully
    if(!inFile||!outFile)
    {
        cerr<<"Fail to open file for reading"<<endl;
        return;//is a empty list
    }
    //ignore the first line
    string delimiter=",";
    int deleteLineCount=0;
   while(getline(inFile,line))
   {
       //get line by line
       //extract id from line 
       int firstComma=line.find(delimiter);
       string currentId=line.substr(0,firstComma);
        //check if there has been instance update
       if(deleteLineCount!=0)
       {
           //there has been an instance update
           outFile<<line<<endl;
           continue;
       }
        //compare with item id to remov
       if(item.GetID()==currentId)
       {
           //this item needed to be Update
           deleteLineCount++;
           outFile<<item.GetID()<<","<<item.GetTitle()<<","<<item.GetRentalType()<<","<<item.GetLoanType()<<","<<item.GetCopieInStock()<<","<<item.GetRentFee()<<endl;
       }
       else{
           //add line to file
           outFile<<line<<endl;
       }
   }
   //check if any item has been deleteds
   if(deleteLineCount==0)
   {
       cout<<"Cannot find the item"<<endl;
   }
    //close file
    inFile.close();
    outFile.close();
    //replace file
    remove(fileName.c_str());
    rename(tempName,fileName.c_str());
}
void UpdateItem(string fileName,DVDItem item)
{
    //Initualize
    string line;
    const char* tempName="temp.txt";
    //open file 
    ifstream inFile(fileName,ios::in);
    ofstream outFile(tempName,ios::app);//create a new file and replace the current
    //check if file has open successfully
    if(!inFile||!outFile)
    {
        cerr<<"Fail to open file for reading"<<endl;
        return;//is a empty list
    }
    //ignore the first line
    string delimiter=",";
    int deleteLineCount=0;
   while(getline(inFile,line))
   {
       //get line by line
       //extract id from line 
       int firstComma=line.find(delimiter);
       string currentId=line.substr(0,firstComma);
        //check if there has been instance update
       if(deleteLineCount!=0)
       {
           //there has been an instance update
           outFile<<line<<endl;
           continue;
       }
        //compare with item id to remov
       if(item.GetID()==currentId)
       {
           //this item needed to be Update
           deleteLineCount++;
           outFile<<item.GetID()<<","<<item.GetTitle()<<","<<item.GetRentalType()<<","<<item.GetLoanType()<<","<<item.GetCopieInStock()<<","<<item.GetRentFee()<<","<<item.GetGenre()<<endl;
       }
       else{
           //add line to file
           outFile<<line<<endl;
       }
   }
   //check if any item has been deleteds
   if(deleteLineCount==0)
   {
       cout<<"Cannot find the item"<<endl;
   }
    //close file
    inFile.close();
    outFile.close();
    //replace file
    remove(fileName.c_str());
    rename(tempName,fileName.c_str());
}

//Display Item
void DisplayItem(string fileName,int sortType=0)
{
    //sort Type 0 for none, 1 for id a-z, 2 for id z-a, 3 for title a-z, 4 for title z-a
    vector<Item> itemList;
    vector<string> row;
    //Initualize
    string line,word;
    //open file 
    ifstream inFile(fileName,ios::in);
    //check if file has open successfully
    if(!inFile)
    {
        cerr<<"Fail to open file for reading"<<endl;
        return;//is a empty list
    }
    //cout<<"get the first line"<<endl;
    //ignore the first line
    getline(inFile,line);
    //track
    int count=1;

    //read and save record
   while(getline(inFile,line))
   {
       count++;
       //reset row
       row.clear();
       //get line by line
       //get individual section
       stringstream str(line);
       while(getline(str,word,','))
       {
           row.push_back(word);
       }
        //convert row to item

        //check copies and fee
        if(isCopiesValid(row.at(4))&&isFeeValid(row.at(5))&&isRentalValid(row.at(2))&&isLoanTypeValid(row.at(3))&&isIdValid(row.at(0)))
        {
            int copiesAmount=stoi(row.at(4));
            float fee=stof(row.at(5));
            //check if the current item is dvd
            if(row.at(2)!="DVD")
            {
                Item obj(row.at(0),row.at(1),row.at(2),row.at(3),copiesAmount,fee);
                itemList.push_back(obj);
                continue;
            }
            else if(row.size()==7&&isDVDGenreValid(row.at(6))){
                //cout<<"any DVD"<<row.at(0)<<endl;
                DVDItem obj(row.at(0),row.at(1),row.at(2),row.at(3),copiesAmount,fee,row.at(6));
                itemList.push_back(obj);
                continue;
            }
            else{
                //dvd genre
                cerr<<"Error has occured due to invalid DVD Genre"<<endl;
                cerr<<"it is recommended that you check DVD genre of datafile at line"<<count<<endl;
            }
        }
        else{
            //
            cerr<<"Fail to build item of id "<<row.at(0)<<" due to invalid property"<<endl;
            cerr<<"It is recommended that you recheck your data file at line "<<count<< endl;
        }
    }
    if(sortType==0)
    {
        //display all information within list
        DisplayList(itemList);
    }
    else if(sortType==1)
    {
        //sort list with id from a to z
        SortListAZ(itemList);
        DisplayList(itemList);
    }
    else if(sortType==2)
    {
        //sort list with id from z to a
        SortListZA(itemList);
        DisplayList(itemList);
    }
    else if(sortType==3)
    {
        //sort list with title from a to z
        SortListAZ(itemList,false);
        DisplayList(itemList);
    }
    else if(sortType==4)
    {
        //sort list with title from z to a
        SortListZA(itemList,false);
        DisplayList(itemList);
    }
    //close file
    inFile.close();
}
//display items that has no copies
void DisplayNoStockItem(string fileName, int sortType=0)
{
    //sort Type 0 for none, 1 for id a-z, 2 for id z-a, 3 for title a-z, 4 for title z-a
    vector<Item> itemList;
    vector<string> row;
    //Initualize
    string line,word;
    //open file 
    ifstream inFile(fileName,ios::in);
    //check if file has open successfully
    if(!inFile)
    {
        cerr<<"Fail to open file for reading"<<endl;
        return;//is a empty list
    }
    //cout<<"get the first line"<<endl;
    //ignore the first line
    getline(inFile,line);
    //track
    int count=1;

    //read and save record
   while(getline(inFile,line))
   {
       count++;
       //reset row
       row.clear();
       //get line by line
       //get individual section
       stringstream str(line);
       while(getline(str,word,','))
       {
           row.push_back(word);
       }
        //convert row to item

        //check copies and fee
        if(isCopiesValid(row.at(4))&&isFeeValid(row.at(5))&&isRentalValid(row.at(2))&&isLoanTypeValid(row.at(3))&&isIdValid(row.at(0)))
        {
            int copiesAmount=stoi(row.at(4));
            if(copiesAmount!=0)
            {
                continue;
            }
            float fee=stof(row.at(5));
            //check if the current item is dvd
            if(row.at(2)!="DVD")
            {
                Item obj(row.at(0),row.at(1),row.at(2),row.at(3),copiesAmount,fee);
                itemList.push_back(obj);
                continue;
            }
            else if(row.size()==7&&isDVDGenreValid(row.at(6))){
                //cout<<"any DVD"<<row.at(0)<<endl;
                DVDItem obj(row.at(0),row.at(1),row.at(2),row.at(3),copiesAmount,fee,row.at(6));
                itemList.push_back(obj);
                continue;
            }
            else{
                //dvd genre
                cerr<<"Error has occured due to invalid DVD Genre"<<endl;
                cerr<<"it is recommended that you check DVD genre of datafile at line"<<count<<endl;
            }
        }
        else{
            //
            cerr<<"Fail to build item of id "<<row.at(0)<<" due to invalid property"<<endl;
            cerr<<"It is recommended that you recheck your data file at line "<<count<< endl;
        }
    }
    if(sortType==0)
    {
        //display all information within list
        DisplayList(itemList);
    }
    else if(sortType==1)
    {
        //sort list with id from a to z
        SortListAZ(itemList);
        DisplayList(itemList);
    }
    else if(sortType==2)
    {
        //sort list with id from z to a
        SortListZA(itemList);
        DisplayList(itemList);
    }
    else if(sortType==3)
    {
        //sort list with title from a to z
        SortListAZ(itemList,false);
        DisplayList(itemList);
    }
    else if(sortType==4)
    {
        //sort list with title from z to a
        SortListZA(itemList,false);
        DisplayList(itemList);
    }
    //close file
    inFile.close();
}

//Search Item

//Write to File
void AddItemToDatabase(string fileName,Item item)
{
    //open file 
    ofstream fout(fileName,ios::out|ios::app);
    //check if file has open successfully
    if(!fout)
    {
        cerr<<"File failed to open"<<endl;
        return;
    }
    // write to file
    fout<<item.GetID()<<","<<item.GetTitle()<<","<<item.GetRentalType()<<","<<item.GetLoanType()<<","<<item.GetCopieInStock()<<","<<item.GetRentFee()<<endl;
    fout.close();
}
//Write DVD to FIle
void AddItemToDatabase(string fileName,DVDItem item)
{
    //open file 
    ofstream fout(fileName,ios::app);
    //check if file has open successfully
    if(!fout)
    {
        cerr<<"File failed to open"<<endl;
        return;
    }
    // write to file
    fout<<item.GetID()<<","<<item.GetTitle()<<","<<item.GetRentalType()<<","<<item.GetLoanType()<<","<<item.GetCopieInStock()<<","<<item.GetRentFee()<<","<<item.GetGenre()<<endl;
    fout.close();
}
//
int main(int argc, char const *argv[])
{
    //sample text file
    string databaseFile="items.txt";
    //Item obj1("123","Toy","Game","2-day",3,100.2f);
    //DVDItem obj2("234","Bad Toy","DVD","1-week",100,"Drama");
    //AddItemToDatabase(databaseFile,obj2);
    //DeleteItem(databaseFile,obj2.GetID());
    //obj2.SetCopiesInStock(12);
    //UpdateItem(databaseFile,obj2);
    //display 
    //DisplayItem(databaseFile,4);
    DisplayNoStockItem(databaseFile);
    return 0;
}
