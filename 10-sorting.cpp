/*Write C++ program using STL for sorting and searching with user defined records such as
person record(Name, DOB, Telephone number), Item record (Item code, name,
cost,quantity) using vector container*/

# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
using namespace std;

class student
{
    public:
    int rollno;
    string name;
    char dob[15];

    bool operator==(const student &student1)
    {
        return (rollno == student1.rollno);
    }
    bool operator<(const student &student1)
    {
        return (rollno < student1.rollno);
    }

    friend ostream & operator << (ostream &out , const student &);
    friend istream & operator >> (istream &in , const student &k);
};

ostream & operator << (ostream &out , const student &k)
{
    out << "\n\t\t" << k.rollno << "\t\t" << k.name << "\t\t" << k.dob;
    return out;
}

istream & operator >> (istream &in , student &k)
{
    cout << "\nEnter roll no : ";
    in >> k.rollno;
    cout << "\nEnter Name : ";
    in >> k.name;
    cout << "\nEnter DOB : ";
    in >> k.dob;
    return in;
}

bool myfunc(const student &k , const student &i2)
{
    return (k.rollno<i2.rollno);
}

vector<student>read()
{
    int n;
    student k;
    vector <student> j;
    cout << "\nEnter total number of students : ";
    cin >> n;
    for (int i=0 ; i<n ; i++)
    {
        cin >> k;
        j.push_back(k);
    }
    return j;
}

void printfunction (const student &k)
{
    cout << k;
}

void print (const vector <student> &j)
{
    cout << "\n\t\tROLL NO\t\tNAME\t\tDATE OF BIRTH";
    for_each (j.begin() , j.end() , printfunction);
}

void insert (vector<student> &j)
{
    student k;
    cin >> k;
    j.push_back(k);
}

void delet (vector<student> &j)
{
    student k;
    cout << "\nEnter student roll no to delete : ";
    cin >> k.rollno;
    vector<student> :: iterator p;
    p=find(j.begin() , j.end() , k);
    if (p!=j.end())
        j.erase(p);
    else
        cout << "\nNot Found ";
}

void search (vector<student> &j)
{
    student k;
    cout << "\nEnter student roll no to search : ";
    cin >> k.rollno;
    cout << "\n\n\tROLLNO\t\tNAME\t\tDATE OF BIRTH";
    vector<student> :: iterator p;
    p=find (j.begin() , j.end() , k);
    if (p!=j.end())
        cout << *p;
    else
        cout << "\nNot Found";    
}

void sort (vector<student> &j)
{
    sort (j.begin() , j.end() , myfunc);
}

int main()
{
    vector<student> j;
    int op;

    do
    {
        cout << "\n\n\t\t----------<< MENU >>----------";
        cout << "\n\t\t1.CREATE ";
        cout << "\n\t\t2.DISPLAY ";
        cout << "\n\t\t3.INSERT ";
        cout << "\n\t\t4.DELETE ";
        cout << "\n\t\t5.SEARCH ";
        cout << "\n\t\t6.SORT ";
        cout << "\n\t\t7.QUIT ";
        cout << "\n\n\t\t------------------------------";
        cout << "\n\t\tEnter your choice : ";
        cin >> op;

        switch(op)
        {
            case 1:
                j=read ();
                break;
            case 2:
                print (j);
                break;
            case 3:
                insert (j);
                break;
            case 4:
                delet (j);
                break;
            case 5:
                search (j);
                break;
            case 6:
                sort (j);
                print (j);
                break;
        }

    } while (op!=7);
    
}