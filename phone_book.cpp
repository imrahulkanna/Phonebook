#include<iostream>
using namespace std;

class phonebook;

class contact
{
    string name;
    int number;
    string email;
    public:
    friend class phonebook;
};

class phonebook
{
    
}