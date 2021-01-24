#include<iostream>
using namespace std;

class phonebook;

class contact
{
    string contact_name;
    string contact_number;
    string contact_email;
    contact *forw;
    contact *prev;
    public:
    friend class phonebook;
};

class phonebook
{
    string name;
    string number;
    string email;
    contact *start;
    public:
    phonebook()
    {
        start = NULL;
    }
    void add_contact();
   // void delete_contact();
    void display();
    void create(contact *);
};

void phonebook::add_contact()
{
    cout<<"\nenter the name(use underscore for space): ";
    cin>>name;
    cout<<"\nenter phone number: ";
    cin>>number;
    cout<<"\nenter email: ";
    cin>>email;

    //Creating a new contact and assigning the parameters
    contact *new_contact = new contact;
    new_contact->contact_name = name;
    new_contact->contact_number = number;
    new_contact->contact_email = email;
    new_contact->forw = NULL;
    new_contact->prev = NULL;
    cout<<"\ncreating the contact\n";
    create(new_contact);
}

void phonebook::create(contact *new_contact)
{
    contact *ptr,*bef;

    if(start == NULL)
    {
        start = new_contact;
    }

    else
    {
        if(start->forw == NULL)
        {
            if(new_contact->contact_name < start->contact_name )
            {
                new_contact->forw = start;
                start->prev = new_contact;
                start = new_contact;   
            }
            else
            {
                start->forw = new_contact;
                new_contact->prev = start;
            }
        }

        else
        {
            if(new_contact->contact_name < start->contact_name)
            {
                new_contact->forw = start;
                start->prev = new_contact;
                start = new_contact;
            }

            else
            {
                bef = start;
                ptr = start->forw;
                while(bef != NULL)
                {
                    cout<<"111\n";
                    if(bef->forw == NULL)
                    {
                        bef->forw = new_contact;
                        new_contact->prev = bef;
                        cout<<"444\n";
                    }

                    else
                    {
                        if(new_contact->contact_name > bef->contact_name && new_contact->contact_name < ptr->contact_name)
                        {
                            new_contact->forw = ptr->forw;
                            ptr->prev = new_contact;
                            bef->forw = new_contact;
                            new_contact->prev = bef;
                            cout<<"222\n";
                        }
                    }

                    bef = ptr;
                    ptr = ptr->forw;
                    cout<<"555\n";
                }
            }
        }
    }
}

void phonebook::display()
{
    contact *ptr;
    ptr = start;
    cout<<"\n----------------------------------------\n";
    while(ptr != NULL)
    {
        cout<<"\nName: "<<ptr->contact_name<<endl;
        cout<<"\nNumber: "<<ptr->contact_number<<endl;
        cout<<"\nEmail: "<<ptr->contact_email<<endl;
        cout<<"\n----------------------------------------\n";
        ptr = ptr->forw;
    }
}
main()
{
    phonebook ph;
    int op;
    do
    {
        cout<<"\n1.Add a contact    2.Delete    3.Display\n";
        cout<<"\nenter your option: ";
        cin>>op;
        switch (op)
        {
            case 1: ph.add_contact();break;
            //case 2: ph.delete_contact();break;
            case 3: ph.display();break;          
            default: cout<<"\ninvalid option\n";break;
        }
    } while (op>=1 && op<=3);
}