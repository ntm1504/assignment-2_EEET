#include <iostream>
#include <string>
using namespace std;
class base{
    public: 
    virtual void Display()
    {
        cout<<"haha base"<<endl;
    }
};
class child:public base{
    public:
    void Display()
    {
        cout<<"hi hi child"<<endl;
    }
};
int main(int argc, char const *argv[])
{
    base b;
    child c;
    b=c;
    b.Display();
    c.Display();
    return 0;
}
