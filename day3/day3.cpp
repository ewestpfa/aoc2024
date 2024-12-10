#include <fstream>
#include <regex>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ifstream myfile ("input.txt");
    string mystring;
    string mulRegex = "(mul\\([0-9]+,[0-9]+\\))";
    string doRegex = "|(do\\(\\))";
    string dontRegex = "|(don't\\(\\))";
    regex finalRegex(mulRegex + doRegex + dontRegex);
    regex intRegex("[0-9]+");
    int sum1;
    int sum2 = 0;
    bool enabled = true;

    if(myfile.is_open()){
        // Loops through file
        while(!myfile.eof()){
            getline(myfile, mystring);
            smatch func;
            smatch num;
            // Find next instance of the regex in the string
            while(regex_search(mystring, func, finalRegex)){
                string validFunction = func[0];
                // Enable or disable the analysis of the functions
                if(validFunction.compare("do()") == 0){
                    enabled = true;
                }else if(validFunction.compare("don't()") == 0){
                    enabled = false;
                // Evaluate the value of mul(x, y)
                }else{
                    regex_search(validFunction, num, intRegex);
                    int first = stoi(num[0]);
                    validFunction = num.suffix();
                    regex_search(validFunction, num, intRegex);
                    int second = stoi(num[0]);
                    if(enabled){
                        sum2 += first * second;
                    }
                    
                    // Weird note: If sum2 isn't initialized to 0 this line causes the final result for sum2 to be wrong (on all inputs)
                    //             If either sum2 is initialized, or this line is commented out it works fine, not sure why
                    sum1 += first * second;
                }
                
                // Jump to the end of the regex match to search for more instances in this line
                mystring = func.suffix();
            }
        }
    }

    cout << "Part 1: " << sum1 << endl;
    cout << "Part 2: " << sum2 << endl;
}