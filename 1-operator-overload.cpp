/*Implement a class Complex which represents the Complex Number data type. Implement the following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.4. Overloaded << and >> to print and read Complex Numbers.*/


# include <iostream>
using namespace std;

class complex
{
    float x;
    float y;

public:
    complex()
    {
        x=0;
        y=0;
    }

    complex operator+(complex);
    complex operator*(complex);
    friend istream & operator >>(istream & input , complex & t);
    friend ostream & operator <<(ostream & output , complex & t);

};

complex complex :: operator+(complex c)
{
    complex temp;
    temp.x = x+c.x;
    temp.y = y+c.y;
    return (temp);
}

complex complex :: operator*(complex c)
{
    complex temp2;
    temp2.x = (x*c.x)+(y*c.y);
    temp2.y = (y*c.x)-(x*c.y);
    return (temp2);
}

istream & operator>>(istream & input , complex & t)
{
    cout<<"Enter the real part : ";
    cin>>t.x;
    cout<<"Enter thr imaginary part: ";
    cin>>t.y;

    return (input);
}

ostream & operator<<(ostream & output , complex & t)
{
    cout<<t.x<<" + "<<t.y<<"i\n";

    return (output);
}

int main()
{
    complex c1 , c2 , c3 , c4;

    cout<<"\nDefault constructor value is = ";
    cout<<c1;

    cout<<"\nEnter the first number :-\n";
    cin>>c1;
    cout<<"\nEnterthe second number :-\n";
    cin>>c2;

    c3=c1+c2;
    c4=c1*c2;

    cout<<"\nFirst number is = ";
    cout<<c1;
    cout<<"\nSecond number is = ";
    cout<<c2;

    cout<<"\nAddition of the two numbers is : ";
    cout<<c3;
    cout<<"\nMultiplication of the two numbers is : ";
    cout<<c4;

    return 0;
}