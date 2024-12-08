#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

bool comp(int a, int b){
    return a <= b;
}

int main()
{
    ifstream myfile ("input.txt");
    string mystring;
    vector<int> list1;
    vector<int> list2;
    string delimiter = "   ";

    if(myfile.is_open()){
        // Loops through file
        while(!myfile.eof()){
            getline(myfile, mystring);
            
            // Split the string on the delimiter
            string first = mystring.substr(0, mystring.find(delimiter));
            mystring.erase(0, mystring.find(delimiter)+delimiter.length());
            string second = mystring;
            cout << "first: " << first << endl;
            list1.push_back(stoi(first));
            cout << "second: " << second << endl;
            list2.push_back(stoi(second));

            // Added resulting split strins to a vector
            // while(getline(ss, split, ' ')){
            //     v.push_back(split);
            // }

            // Printed the vector
            // for (int i = 0; i < v.size(); i++) {
            //     cout << v[i] << endl;
            // }
            //std::cout << mystring << "\n";
        }
    }

    sort(list1.begin(), list1.end(), comp);
    sort(list2.begin(), list2.end(), comp);

    int sum = 0;

    for(int i = 0; i < list1.size(); i++){
        sum += abs(list1[i] - list2[i]);
    }

    cout << endl << endl << "final: " << sum << endl;
    
}