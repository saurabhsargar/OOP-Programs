/*Imagine a publishing company which does marketing for book and audio cassette
versions. Create a class publication that stores the title (a string) and price (type float) of
a publication.
From this class derive two classes: book, which adds a page count (type int), and tape,
which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data
and displays the data members. If an exception is caught, replace all the data member
values with zero values.*/

# include <iostream>
# include <string>
using namespace std;

class publication                             //Base Class
{
    private:
    string title;
    float price;

    public:
    void getdata()
    {
        cout <<"\nEnter Title : ";
        cin >> title;
        cout <<"\nEnter Price : ";
        cin >> price;
    }
    void putdata() const
    {
        cout << "\nTitle : "<<title;
        cout << "\nPrice : "<<price;
    }
};

class book : private publication                //Derived Class
{
    private:
    int pages;

    public:
    void getdata()
    {
        publication :: getdata();
        cout << "\nEnter the number of pages : ";
        cin >> pages;
    }
    void putdata() const
    {
        publication :: putdata();
        cout << "\nPages : "<<pages;
    }
};

class tape : private publication               //Derived Class
{
    private:
    float time;

    public:
    void getdata()
    {
        publication ::getdata();
        cout << "\nEnter the playing time : ";
        cin >> time;
    }
    void putdata() const
    {
        publication :: putdata();
        cout << "\nPlaying Time : "<<time;
    }
};

int main()
{
    book b1;
    tape t1;
    b1.getdata();
    t1.getdata();
    b1.putdata();
    t1.putdata();

    cout << endl;
    return 0;
}