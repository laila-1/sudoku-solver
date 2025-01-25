/**
 * HI!! This will hopefully be my recursion code ( or backtracking if you wanna call it that ) for solving
 * a soduko game in less than a second ( HOPEFULLY ).
 */
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#define ll long long
using namespace std;

// defining variables/**
 * HI!! This will hopefully be my recursion code ( or backtracking if you wanna call it that ) for solving
 * a soduko game in less than a second ( HOPEFULLY ).
 */
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#define ll long long
using namespace std;

// defining variables
char arr[9][9];
// char bc input has '.' for empty spaces in the grid
bool row[9][10] = {};
bool column [9][10] = {};
bool box [3][3][10] = {};
bool done = 0;

//the backtracking 


void rec(int i, int j){

if (done) return;
if ( j == 9){
    j = 0; i++;
    // making the function go through the columns first, then once it goes through them all
    // it resets to the first column but goes down a row
}

if (i == 9){
    done = 1;
    return;
// means we went through the whole soduko grid
}

if (arr[i][j] == '.'){
    for (int k = 1; k <= 9; k++){
        // checking if we can put this number in the slot we're on
        if (row[i][k] == 0 && column[j][k] == 0 && box[(int)i/3][(int)j/3][k] == 0){ 
            arr[i][j] = '0' + k;
            row[i][k] = 1;
            column[j][k] = 1;
            box[(int)i/3][(int)j/3][k] = 1;

            rec(i, j + 1);
            if (done){
                return;
            }
            // if this solution actually is right, then let's leave with that answer
            
            // if not, we'll reset the value because we know this number won't bring us the right answer. 
            // and we'll go on to the next one
            arr[i][j] = '.';
            row[i][k] = 0;
            column[j][k] = 0;
            box[(int)i/3][(int)j/3][k] = 0;

            
        }
    }
}
else {
rec(i, j + 1); }

}


int main()
{
ios::sync_with_stdio(0); cin.tie(0);
 
 cout << "Please input numbers, with the blank spaces as . or 0 or -" << endl;
 for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
        cin >> arr[i][j];
        if (arr[i][j] == '0' || arr[i][j] == '-' ) {arr[i][j] = '.';} 
        // making sure the empty boxes have one value
        if (arr[i][j] != '.'){
            row[i][arr[i][j] - '0'] = 1;
            column[j][arr[i][j] - '0'] = 1;
            box[(int)i/3][(int)j/3][arr[i][j] - '0'] = 1;
            /** i is for rows, j is for columns, and for the boxes 
             * we divided by 3 bc each box in soduko has three rows and three columns.
             * this is just us essentially saving which spots are "taken" and which aren't, and by what number
             */
        }
    }
 }

 rec(0,0); // doing the recursion function

cout << endl << "Solved puzzle:" << endl;

 for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
        cout << arr[i][j] << ' '; 
    }
    cout << endl;
 }

    return 0;
 
}
char arr[9][9];
// char bc input has '.' for empty spaces in the grid
bool row[9][10] = {};
bool column [9][10] = {};
bool box [3][3][10] = {};
bool done = 0;

//the backtracking 


void rec(int i, int j){

if (done) return;
if ( j == 9){
    j = 0; i++;
    // making the function go through the columns first, then once it goes through them all
    // it resets to the first column but goes down a row
}

if (i == 9){
    done = 1;
    return;
// means we went through the whole soduko grid
}

if (arr[i][j] == '.'){
    for (int k = 1; k <= 9; k++){
        // checking if we can put this number in the slot we're on
        if (row[i][k] == 0 && column[j][k] == 0 && box[(int)i/3][(int)j/3][k] == 0){ 
            arr[i][j] = '0' + k;
            row[i][k] = 1;
            column[j][k] = 1;
            box[(int)i/3][(int)j/3][k] = 1;

            rec(i, j + 1);
            if (done){
                return;
            }
            // if this solution actually is right, then let's leave with that answer
            
            // if not, we'll reset the value because we know this number won't bring us the right answer. 
            // and we'll go on to the next one
            arr[i][j] = '.';
            row[i][k] = 0;
            column[j][k] = 0;
            box[(int)i/3][(int)j/3][k] = 0;

            
        }
    }
}
else {
rec(i, j + 1); }

}


int main()
{
ios::sync_with_stdio(0); cin.tie(0);
 
 for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
        cin >> arr[i][j];
        if (arr[i][j] == '0' || arr[i][j] == '-' ) {arr[i][j] = '.';} 
        // making sure the empty boxes have one value
        if (arr[i][j] != '.'){
            row[i][arr[i][j] - '0'] = 1;
            column[j][arr[i][j] - '0'] = 1;
            box[(int)i/3][(int)j/3][arr[i][j] - '0'] = 1;
            /** i is for rows, j is for columns, and for the boxes 
             * we divided by 3 bc each box in soduko has three rows and three columns.
             * this is just us essentially saving which spots are "taken" and which aren't, and by what number
             */
        }
    }
 }

 rec(0,0); // doing the recursion function

 for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
        cout << arr[i][j] << ' '; 
    }
    cout << endl;
 }

    return 0;
 
}
