/*Write a C++ program that creates an output file, writes information to it, closes the file
andopen it again as an input file and read the information from the file.*/

# include <iostream>
# include <fstream>
using namespace std;

int main()
{
    fstream file; //Object of fstream class

    //opening file "Sample.txt" in out (write) mode
    file.open ("sample.txt" , ios :: out);

    if (!file)
    {
        cout << "Error in creating file!!!!!" << endl;
        return 0;
    }

    cout << "File created successfully." << endl;
    file << "SAURABH" ;
    file.close();

    file.open ("sample.txt" , ios :: in);

    if (!file)
    {
        cout << "Error in opening file!!!!!" << endl;
        return 0;
    }

    char ch;
    cout << "File content : ";

    while(!file.eof())
    {
        file >> ch;
        cout << ch;
    }

    file.close();

    return 0;
}