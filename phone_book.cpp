#include<iostream>
using namespace std;

class phonebook;

class contact
{
    string contact_name;
    int contact_number;
    string contact_email;
    contact *frow;
    contact *prev;
    public:
    friend class phonebook;
};

class phonebook
{
    string name;
    int number;
    string email;
    contact *start;
    public:
    phonebook()
    {
        start = NULL;
    }
    void add_contact();
    void delete_contact();
    void search();
};