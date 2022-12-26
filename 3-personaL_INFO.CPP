/*Develop an object oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. and other.
Construct the database with suitable member functions for initializing and destroying the
data viz constructor, default constructor, Copy constructor, destructor, static member
functions, friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete.*/

# include <iostream>
# include <string.h>
# include <iomanip>

using namespace std;

class db
{
    int roll;
    char name[20];
    char Class[10];
    char Div[10];
    char dob[10];
    char bg[3];
    char Address[10];
    char license[12];
    char phone[10];

    public:
    static int stdno;

    static void count()
    {
        cout<<"\nNo. of objects created : "<<stdno;
    }

    void fin()
    {
        cout<<"\nInline function!";
    }

    db()
    {
        roll=0;
        strcpy(name , "Saurabh");
        strcpy(Class , "SE");
        strcpy(Div , "2");
        strcpy(dob , "22/06/2003");
        strcpy(bg , "o+");
        strcpy(Address, "Pune");
        strcpy(license , "S15220098754");
        strcpy(phone , "1213456789");
        ++stdno;
    }

    db(db *ob)
    {
        strcpy(name , ob -> name);
        strcpy(Class , ob -> Class);
        strcpy(Div , ob -> Div);
        strcpy(dob , ob -> dob);
        strcpy(bg , ob -> bg);
        strcpy(Address, ob -> Address);
        strcpy(license , ob -> license);
        strcpy(phone , ob -> phone);
        ++stdno;
    }

    void getdata()
    {
        cout<<"\n\nEnter : Name , roll , class , div , dob , bg , address , license , phone \n\n";
        cin>>name>>roll>>Class>>Div>>dob>>bg>>Address>>license>>phone;
    }

    friend void display(db d);
    ~db()
    {
        cout<<"\n\n"<<this -> name<<"(Object) is destroyed!";
    }
};

void display(db d)
{
    cout<<"\n"<<setw(20)<<d.name<<" "<<setw(5)<<d.roll<<" "<<setw(10)<<d.Class<<" "<<setw(10)<<d.Div<<" "<<setw(10)<<d.dob<<" "<<setw(10)<<d.bg<<" "<<setw(10)<<d.Address<<" "<<setw(12)<<d.license<<" "<<setw(10)<<d.phone;
}

int db :: stdno;

int main()
{
    int n , i;
    db d1 , *ptr[5];
    cout<<"\nDefault values: ";
    display(d1);

    d1.getdata();
    display(d1);

    db d2(&d1);
    cout<<"\n\nUse of copy constructors : \n";
    display(d2);

    cout<<"\nHow many objects you wamt to create? ";
    cin>>n;

    for(i=0 ; i<n ; i++)
    {
        ptr[i]=new db();
        ptr[i]->getdata();
    }

    cout<<"\n"<<setw(20)<<"name"<<" "<<setw(5)<<"roll"<<" "<<setw(10)<<"Class"<<" "<<setw(10)<<"Div"<<" "<<setw(10)<<"dob"<<" "<<setw(10)<<"bg"<<" "<<setw(10)<<"Address"<<" "<<setw(12)<<"license"<<" "<<setw(10)<<"phone";

    for(i=0 ; i<n ; i++)
    display(*ptr[i]);
    db :: count();

    for(i=0 ; i<n ;i++)
    {
        delete(ptr[i]);
    }
    cout<<"\nObjects deleted!";

    return 0;
}

