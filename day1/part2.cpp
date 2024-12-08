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
        }
    }

    sort(list1.begin(), list1.end(), comp);
    sort(list2.begin(), list2.end(), comp);

    int prev = 0;
    int idx2 = 0;
    int sum = 0;

    for(int idx1 = 0; idx1 < list1.size();idx1++){
        // New number
        if(prev != list1[idx1]){
            int count = 0;
            // Skip over all lower numbers
            while(idx2 < list2.size() && list2[idx2] < prev){
                idx2++;
            }
            while(idx2 < list2.size() && list2[idx2] == prev){
                idx2++;
                count++;
            }
            sum += prev * count;
        }

        prev = list1[idx1];
        
    }

    cout << "final: " << sum << endl;
    
}