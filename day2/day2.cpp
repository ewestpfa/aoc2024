#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

bool comp(int a, int b){
    return a <= b;
}

bool isValid(vector<string> nums){
    bool isValid = true;
    int dir = 0;

    // Compare all pairs of elements
    for(int i = 0; i < nums.size()-1; i++){
        int comp = stoi(nums[i+1]) - stoi(nums[i]);
        int thisSign = comp > 0;
        // dir is true if going up, 0 if going down
        if(i == 0){
            dir = thisSign;
        }

        // If no change, direction of change is different, or gap is greater than 3, not valid
        if(comp == 0 || thisSign != dir || abs(comp) > 3){
            isValid = false;
        }
    }
    return isValid;
}

bool isValidish(vector<string> nums, bool hadProblem){
    bool isValid = true;
    int dir = 0;

    // Compare all pairs of elements
    for(int i = 0; i < nums.size()-1; i++){
        int comp = stoi(nums[i+1]) - stoi(nums[i]);
        int thisSign = comp > 0;
        // dir is 1 if comp is positive, 0 otherwise
        if(i == 0){
            dir = thisSign;
        }

        // If no change, direction of change is different, or gap is greater than 3, not valid
        if(comp == 0 || thisSign != dir || abs(comp) > 3){
            // If there was previously an issue, cannot be fixed
            if(hadProblem){
                isValid = false;
            // If there wasn't previously an issue, try all subsets with one element removed to see if that is valid
            }else{
                hadProblem = true;
                bool either = false;
                for(int j = 0; j < nums.size(); j++){
                    vector<string> subset(nums);
                    subset.erase(subset.begin()+j);
                    either = either || isValidish(subset, hadProblem);
                }
                // If one of the second layer options is valid, then the original set is valid as well
                return either;
            }
        }
    }
    return isValid;
}

int main()
{
    ifstream myfile ("input.txt");
    string mystring;

    int safeCount, safeishCount = 0;

    if(myfile.is_open()){
        // Loops through file
        while(!myfile.eof()){
            getline(myfile, mystring);

            string split;
            stringstream ss(mystring);
            vector<string> nums;

            // Added resulting split strins to a vector
            while(getline(ss, split, ' ')){
                nums.push_back(split);
            }
            
            if(isValid(nums)){
                safeCount++;
            }

            if(isValidish(nums, false)){
                safeishCount++;
            }
        }
    }
    
        cout << "Part 1: " << safeCount << endl;
        cout << "Part 2: " << safeishCount << endl;
}
