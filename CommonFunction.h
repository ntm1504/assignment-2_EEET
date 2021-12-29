#include <string>
#include <iostream>
#include <vector>
using namespace std;
//Checking Function-----------------------------------------------------------------
bool isCopiesValid(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
        {
            cout<<"corrupted amount of copies in Stock: "<<s<<" is not a positive integer"<<endl;
            return false;
        }
    }
    return true;
}
//check fee
bool isFeeValid(string str)
{
    int dot = 1;//allow one dot
    //not allow + or -
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            if (str[0] == ' ')//only first char are allowed to be space
            {
                continue;
            }
            else if (str[i] == '.' && dot == 1)
            {
                dot--;
                continue;
            }
            else
            {         
                // if(str[i]=='\r'&&i == (str.length() -1))//in csv file line contain \r at the end 
                // {
                //     //cout<<"special key found";
                //     cout<<"does here is fine"<<endl;
                //     return true;
                // }  
                cout<<"corrupted item fee "<<str<<" is not a valid fee number"<<endl;
                return false;
            }
        }
        else
        {
            if (i == (str.length() -1))//last key 
            {
                return true;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    
    return false;
}
//check rental Type
bool isRentalValid(string s)
{
    if(s=="Game"||s=="DVD"||s=="Record")
    {
        return true;
    }
    else{
        cerr<<"invalid Rental Type"<< s<<endl;
        return false;
    }
}
//check loan Type
bool isLoanTypeValid(string s)
{
    if(s=="1-week"||s=="2-day")
    {
        return true;
    }
    else{
        cerr<<"invalid Loan Type"<<s<<endl;
        return false;
    }
}
//check id
bool isIdValid(string s)
{
    return true;
}
//check DVD genre
bool isDVDGenreValid(string s)
{
    if(s=="Action"||s=="Drama"||s=="Horror"||s=="Comedy")
    {
        return true;
    }
    return false;
}

//Action function-----------------------------------------------------------------
//sort by id or title
void swapItem(Item &i1,Item &i2)
{
    Item temp=i1;
    i1=i2;
    i2=temp;
}
//sort item list base on key( 0 for id, 1 for title) in alphabetical order
void SortListAZ(vector<Item> &itemList,bool usingId=true)
{
    for(int i=0;i<itemList.size();i++)//outer
    {
        for(int j=i+1;j<itemList.size();j++)//inner
        {
            if(usingId)//using id to sort
            {
                if(itemList.at(i).GetID()>itemList.at(j).GetID())//a-z
                {
                    swapItem(itemList.at(i),itemList.at(j));
                }
            }
            else{//using title
                if(itemList.at(i).GetTitle()>itemList.at(j).GetTitle())//a-z
                {
                    swapItem(itemList.at(i),itemList.at(j));
                }
            }
        }
    }
}
//sortin list from z- a
void SortListZA(vector<Item> &itemList,bool usingId=true)
{
    for(int i=0;i<itemList.size();i++)//outer
    {
        for(int j=i+1;j<itemList.size();j++)//inner
        {
            if(usingId)//using id to sort
            {
                if(itemList.at(i).GetID()<itemList.at(j).GetID())//a-z
                {
                    swapItem(itemList.at(i),itemList.at(j));
                }
            }
            else{//using title
                if(itemList.at(i).GetTitle()<itemList.at(j).GetTitle())//a-z
                {
                    swapItem(itemList.at(i),itemList.at(j));
                }
            }
        }
    }
}
//raw display
void DisplayList(vector<Item> &itemList)
{
    if(itemList.size()==0)
    {
        cout<<"there is no items found";
        return;
    }
    for(int i=0;i<itemList.size();i++)
    {
        itemList.at(i).Display();
    }
}