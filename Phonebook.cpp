#include <iostream>
#include <cstring>
using namespace std;
class phone
{
public:
    char number[50];
    char name[30];
    phone *prev, *next;
    phone(char n[], char r[])
    {
        strcpy(name, n);
        strcpy(number, r);
        next = NULL;
        prev = NULL;
    }
    friend class phonebook;
};
class phonebook
{
    phone *head, *temp, *ptr;
    phone *ptr1, *ptr2, *dup;

public:
    phone *prevn;

    void insert();
    void sort();
    void deletecontact(char n[20]);
    void deletesamenumber();
    void deletesamename();
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void display();
    void update(char ch[10]);
    phonebook()
    {
        head = NULL;
        temp = NULL;
        ptr = NULL;
        ptr1 = NULL;
        ptr2 = NULL;
        dup = NULL;
    }
};
void phonebook::display()
{
    ptr = head;         // start the node
    while (ptr != NULL) // traverse till last
    {
        cout << "Name: " << ptr->name << endl;
        cout << "Number: +92-" << ptr->number<< endl;
        ptr = ptr->next;
    }
}

void phonebook::insert()
{
    char number[50]; // number of contact
    char name[30];   // name of contact
    char ans;        // answer for continue
    do
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
        while (strlen(number) != 10)
        {
            cout << "Enter valid number:";
            cin >> number;
        }
        temp = new phone(name, number);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}
void phonebook::sort()
{
    phone *i, *j;
    int temp;
    char n[10];
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            temp = strcmp(i->name, j->name);
            if (temp > 0)
            {
                strcpy(n, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, n);
            }
        }
    }
}
void phonebook::deletecontact(char s[20])
{
    int c = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(s, ptr->name) == 0)
        {
            c = 1;
            break;
        }
        else
        {
            c = 2;
        }
        ptr = ptr->next;
    }
    if (c == 1 && ptr != head && ptr->next != NULL)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    else if (ptr == head)
    {
        head = head->next;
        head->prev = NULL;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    else if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    else if (c == 2)
    {
        cout << "YOUR ENTERED NAME IS NOT IN THE PHONEBOOK\n\n";
    }
}
void phonebook::deletesamename()
{
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->name, ptr2->next->name) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}
void phonebook::deletesamenumber()
{
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->number, ptr2->number) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}
void phonebook::searchbyname(char na[10])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(na, ptr->name) == 0)
        {
            cout << "Name Found" << endl;
            cout << "Contact details are below: \n"
                 << endl;
            cout << "\n\nName:\t" << ptr->name;
            cout << "\nNumber:\t+92-" << ptr->number;
        }
        ptr = ptr->next;
    }
}
void phonebook::searchbynumber(char num[20])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(num, ptr->number) == 0)
        {
            cout << "Number found!\n"
                 << endl;
            cout << "Contact details are below: \n"
                 << endl;
            cout << "\n\nName:\t" << ptr->name;
            cout << "\nNumber:\t+92-" << ptr->number;
        }
        ptr = ptr->next;
    }
}
void phonebook::update(char n[20])
{
    char ans;
    int c;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(n, ptr->name) == 0)
        {
            do
            {
                cout << "What do you want to update? \n1. Name \n2. Number \n";
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "Enter new name: \n";
                    cin >> ptr->name;
                    break;
                case 2:
                    cout << "Enter new number: \n";
                    cin >> ptr->number;
                    while (strlen(ptr->number) != 10)
                    {
                        cout << "Enter valid number: \n";
                        cin >> ptr->number;
                    }
                    break;
                }
                cout << "Do you want to update more? (y/n) \n";
                cin >> ans;
            } while (ans == 'y');
        }
        ptr = ptr->next;
    }
}
int main()
{
    char n[20]; char nam[20]; char name[10]; char number[10];
    phonebook d1;
    char ans;
    int ch, a;
    cout << "**************               PHONE BOOK                ********************";
    cout << "\n\n ENTER YOUR NAME: ";
    cin.getline(name, 20);
    cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME " << name << "   !!!!!!!!!!!!!!!!!!!!!";
    cout << "\n\n\nLET'S CREATE YOUR PHONEBOOK " << name << "  \n\n";
    d1.insert();
    d1.sort();
    do
    {
        cout << "\n\n\n\n1) Display your phonebook \n2) Insert new contact \n3) Update details on existing contacts\n4) Delete a contact from phonebook\n5) Delete same names from phonebook\n6) Delete same numbers from phonebook\n7) Search a contact from phonebook\n";
        cin >> ch;
        switch (ch)
        {
        case 2:
            d1.insert();
            d1.sort();
            break;

        case 1:
            d1.display();
            break;
        case 3:
            cout << "\n\nEnter the name of the contact to be updated:";
            cin >> n;
            d1.update(n);
            d1.sort();
            break;
        case 4:
            cout << "\nEnter the name of the contact to be deleted: ";
            cin >> name;
            d1.deletecontact(name);
            break;
        case 5:
            d1.deletesamename();
            d1.display();
            break;
        case 6:
            d1.deletesamenumber();
            d1.display();
            break;
        case 7:
            do
            {
                cout << "1.Search by name \n2.Search by number\n";
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Enter the name to be searched: \n";
                    cin >> name;
                    d1.searchbyname(name);
                    break;
                case 2:
                    cout << "Enter the name to be searched: \n";
                    cin >> number;
                    d1.searchbynumber(number);
                    break;
                default:
                    cout << "\nNo proper input given";
                }
                cout << "\nDo you want to search more? (y/n)";
                cin >> ans;
            } while (ans == 'y');
            break;
        default:
            cout << "\n No proper input given";
        }
        cout << "\n\nDo you want to continue the operations? (y/n)";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}