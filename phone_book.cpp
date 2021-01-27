#include<windows.h>
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
    int c;
    public:
    phonebook()
    {
        start = NULL;
    }
    void add_contact();
    void delete_contact();
    void del_via_name();
    void del_via_number();
    void del_via_email();
    void display();
    void create(contact *);
};

//function which adds new contacts to the phonebook
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

    if(start == NULL)                                               //incase when the phonebook is empty
    {
        start = new_contact;
    }

    else
    {
        if(start->forw == NULL)                                     //incase when phonebook contains only one contact
        {
            if(new_contact->contact_name < start->contact_name )    //adding to the fornt of the existing contact
            {
                new_contact->forw = start;
                start->prev = new_contact;
                start = new_contact;   
            }
            else                                                    //adding a contact after the existing contact
            {
                start->forw = new_contact;
                new_contact->prev = start;
            }
        }

        else
        {
            if(new_contact->contact_name < start->contact_name)    //adding a new contact at the beginning of the phonebook
            {
                new_contact->forw = start;
                start->prev = new_contact;
                start = new_contact;
            }

            else
            {
                bef = start;
                ptr = start->forw;
                while(ptr != NULL)                                 
                {                                                   //when we adding to new contact to last of the phonebook
                    if(ptr->forw == NULL && new_contact->contact_name > ptr->contact_name)
                    {
                        ptr->forw = new_contact;
                        new_contact->prev = ptr;
                        break;
                    }

                    else                                           //when we are adding a new contact in between two contacts
                    {
                        if(new_contact->contact_name > bef->contact_name && new_contact->contact_name < ptr->contact_name)
                        {
                            new_contact->forw = ptr;
                            ptr->prev = new_contact;
                            bef->forw = new_contact;
                            new_contact->prev = bef;
                            break;
                        }
                    }

                    bef = ptr;
                    ptr = ptr->forw;
                }
            }
        }
    }                                                              //to slow down the output we are writing this chuck of code
    Sleep(1000);                                                   //Sleep function is an in-inbuilt function in (windows.h) 
    cout<<".";                                                     //Sleep function takes time as parameter in milliseconds
    Sleep(1000);
    cout<<"\n.";
    Sleep(1000);
    cout<<"\n.";
    Sleep(1000);
    cout<<"\ncontact saved\n";
}

void phonebook::delete_contact()
{
    int op;
    cout<<"\nHow do you wanna delete a contact?\n";
    cout<<"\n1.via name       2.via number       3.via email\n";
    cout<<"\nenter your choice: ";
    cin>>op;
    cout<<endl;
    switch (op)
    {
        case 1: del_via_name();break;
        //case 2: del_via_number();break;
        //case 3: del_via_email();break;
        default: cout<<"\ninvalid choice\n";
    }
}

void phonebook::del_via_name()
{
    c = 0;
    contact *ptr = start;
    if(start == NULL)
        cout<<"\ncontact list is empty\n";
    else
    {
        cout<<"\nenter the name of the contact: ";
        cin>>name;
        while(ptr != NULL)
        {
            if(ptr->contact_name == name)
            {
                c = 1;
                break;
            }
            ptr = ptr->forw;
        }
    
        if(c == 0)
            cout<<"there is no such contact with name "<<name<<endl;
        else
        {
            if(start->forw == NULL)
                start = NULL;
            else
            {
                if(ptr == start)
                {
                    start = start->forw;
                }
                else
                {
                    ptr->prev->forw = ptr->forw;
                    if(ptr->forw != NULL)
                        ptr->forw->prev = ptr->prev;
                }
            }
            cout<<"\ncontact deleted\n";
            delete ptr;
        }
    }
}

//function which displays the contact in the phonebook
void phonebook::display()
{
    contact *ptr;
    int count=0;
    ptr = start;
    cout<<"\n----------------------------------------\n";
    while(ptr != NULL)
    {
        cout<<"\nName: "<<ptr->contact_name<<endl;
        cout<<"\nNumber: "<<ptr->contact_number<<endl;
        cout<<"\nEmail: "<<ptr->contact_email<<endl;
        cout<<"\n----------------------------------------\n";
        ptr = ptr->forw;
        count++;
    }
    cout<<"\n              "<<count<<" contacts\n\n";
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
            case 2: ph.delete_contact();break;
            case 3: ph.display();break;          
            default: cout<<"\ninvalid option\n\n";break;
        }
    } while (op>=1 && op<=3);
}