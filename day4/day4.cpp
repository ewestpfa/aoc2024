#include <fstream>
#include <regex>
#include <iostream>
#include <string.h>
using namespace std;

int findIdx(vector<char> v, char val){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == val){
            return i;
        }
    }
    return -1;
}

int countXMAS(vector<vector<char>> matrix){
    int sum = 0;

    vector<char> key = {'X','M','A','S'};
    vector<vector<int>> directions = {{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1}};
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j]== key[0]){
                for(int dir = 0; dir < directions.size(); dir++){
                    int x = directions[dir][0];
                    int y = directions[dir][1];
                    bool match = true;
                    for(int k = 0; k < key.size(); k++){
                        if(i+x*k >= 0 && i+x*k < matrix.size() && j+y*k >= 0 && j+y*k < matrix[0].size() && matrix[i+x*k][j+y*k] == key[k]){
                            continue;
                        }else{
                            match = false;
                            break;
                        }
                    }
                    if(match){
                        sum++;
                    }
                }
            }
        }
    }

    return sum;
}

int countX_MAS(vector<vector<char>> matrix){
    int count = 0;

    char center = 'A';
    vector<char> tails = {'M','S'};
    vector<vector<vector<int>>> directions = {{{1,-1},{-1,1}},{{-1,-1},{1,1}}};
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == center){
                bool isX = true;
                for(int diag = 0; diag < directions.size(); diag++){
                    vector<int> point1 = directions[diag][0];
                    vector<int> point2 = directions[diag][1];
                    if(i+point1[0] >= 0 && i+point1[0] < matrix.size() && j+point1[1] >= 0 && j+point1[1] < matrix[0].size() && 
                    i+point2[0] >= 0 && i+point2[0] < matrix.size() && j+point2[1] >= 0 && j+point2[1] < matrix[0].size()){
                        if((matrix[i+point1[0]][j+point1[1]] == 'M' && matrix[i+point2[0]][j+point2[1]] == 'S') ||
                        (matrix[i+point1[0]][j+point1[1]] == 'S' && matrix[i+point2[0]][j+point2[1]] == 'M')){
                            continue;
                        }else{
                            isX = false;
                        }
                    }else{
                        isX = false;
                    }
                }
                if(isX){
                    count++;
                }
            }
        }
    }

    return count;

}

int main()
{
    ifstream myfile ("input.txt");
    string mystring;
    vector<vector<char>> matrix;

    if(myfile.is_open()){
        // Loops through file
        while(!myfile.eof()){
            getline(myfile, mystring);
            vector<char> line;
            for(int i = 0; i < mystring.length(); i++){
                line.push_back(mystring[i]);
            }
            matrix.push_back(line);
        }
    }

    cout << "Part 1: " << countXMAS(matrix) << endl;
    cout << "Part 2: " << countX_MAS(matrix) << endl;

}