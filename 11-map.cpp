/*Write a program in C++ to use map associative container. The keys will be the names of
states, and the values will be the populations of the states. When the program runs, the
user is prompted to type the name of a state. The program then looks in the map, using
the state name as an index, and returns the population of the state. */

# include <iostream>
# include <map>
# include <string>
# include <utility>
using namespace std;

int main()
{
    typedef map<string , int> mapType;
    mapType populationMap;

    populationMap.insert (pair <string , int> ("China" , 1339));
    populationMap.insert (pair <string , int> ("India" , 1187));
    populationMap.insert (mapType :: value_type ("US" , 310));
    populationMap.insert (mapType :: value_type ("Indonesia" , 234));
    populationMap.insert (make_pair ("brazil" , 193));
    populationMap.insert (make_pair ("Pakistan" , 170));
    mapType :: iterator iter = --populationMap.end();
    populationMap.erase(iter);

    cout << "Size of PopulationMap : " << populationMap.size() << '\n';
    for (iter = populationMap.begin() ; iter != populationMap.end(); ++iter)
    {
        cout <<" "<< iter->first << " "<< iter->second << " million\n";
    }

    string country ("Indonesia");
    iter = populationMap.find(country);
    if (iter != populationMap.end())
        cout << country << "'s population is" << iter->second << "million\n";
    else
        cout << "Key is not in populationMap" << '\n';

    populationMap.clear();
}