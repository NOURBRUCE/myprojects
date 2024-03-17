// File: rational Number Calculator

// Purpose: Calculate Two rational Numbers

// Author1: Nour Alaa Hasan ==> ID: 20230445 ==> Emails: nwrlanwrla56@gmail.com

// Author2: Adam Samir Farouk Ibrahim ==> ID: 20230040 ==> Emails: adamsamir@Hotmail.com 

// Author3: Aya Magdi Ali Ahmed ==> ID: 20230084 ==> Emails: A.M.A2004@xed.aucegypt.edu

// Part one: Summation & Handeling Code & Defensive Programming
// Part two: Subtraction & Part of Division
// Part three: Multiplication & Part of Division

// Part one: Done By   ==> Nour Alaa Hasan
// Part two: Done By   ==> Adam Samir Farouk Ibrahim
// Part three: Done By ==> Aya Magdi Ali Ahmed
// And we all share to do this program


#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "=====================================\n";
    cout << "Welcome To Rational Number Calculator \n"; // welcome message
    cout << "=====================================\n\n";

    while (true)
    {   
        int ov = 0;
        cout << "Please choose (A) to start program or any character to (exit) \n"; // start or end
        string c1; // take desire
        getline(cin, c1);
        string c2 = "";

        // handle the desire input
        for(int i=0; i<c1.length(); i++){
            if(islower(c1[i])){
                c2 += char(toupper(c1[i]));
            }
            else if(isspace(c1[i])){
                continue;
            }
            else{ c2 += c1[i]; }
        }

        int count1 = 0; // numerator
        int count2 = 0; // denominator
        if(c2 == "A"){

            cout << "Please enter the rarional number operations likes (a/b +-*/ c/d) \n"; // take input
            k:
            string rational_1; getline(cin, rational_1); // take the rational number
            string rational_2 = "";

            if(rational_1[0] >= '0' && rational_1[0] <= '9'){
                // delete spaces
                for(int i=0; i<rational_1.length(); i++){
                    if(isspace(rational_1[i])){ continue; }
                    else{ rational_2 += rational_1[i]; }
                }

                // check on rational_1
                for(int i=0; i<rational_2.length(); i++){
                    if(rational_2[i] >= '0' && rational_2[i] <= '9'){
                        continue;
                    } // the operations that will be done
                    else if(rational_2[i] == '/' || rational_2[i] == '*' || rational_2[i] == '+' || rational_2[i] == '-'){
                        continue;
                    }
                    else{
                        cout << "invalid input, please enter valid value\n"; // make sure validation
                        goto k; // return to input valid value
                    }
                }

                cc:
                if(rational_2.length() != 0){ // if input not empty
                    int over = 0;
                    for(int i=0; i<rational_2.length(); i++){ // know the number of (/)
                        if(rational_2[i] == '/'){
                            over++; // the number of (/)
                        }
                    }
                    int operats = 0;
                    for(int i=0; i<rational_2.length(); i++){
                        if(rational_2[i] == '+' || rational_2[i] == '-' || rational_2[i] == '*'){
                            operats++;
                        }
                    }

                    int valid = 0;
                    for(int i=0; i<rational_2.length()-1; i++){ // make sure that no double operation frequantly
                        if(rational_2[i] == '+' && rational_2[i+1] == '+'){ valid++ ;}
                        if(rational_2[i] == '-' && rational_2[i+1] == '-'){ valid++ ;}
                        if(rational_2[i] == '*' && rational_2[i+1] == '*'){ valid++ ;}
                        if(rational_2[i] == '/' && rational_2[i+1] == '/'){ valid++ ;}
                    }
                    if(valid > 0){
                        cout << "invalid input, please enter valid value\n";
                        goto k; // return input valid value
                    }
                    
                    
                    if(over >= 2){
                        x:
                        int index; // the position of operations
                        int df = 0;
                        // تحديد اماكن ال operations
                        for(int i=0; i<rational_2.length(); i++){
                            if(rational_2[i] == '/'){
                                df++;
                            }
                            if(rational_2[i] == '*' || rational_2[i] == '+' || rational_2[i] == '-' || (rational_2[i] == '/' && df == 2)){
                                index = i; break;
                            }
                        }

                        int ratio_0 = 0; // the first numerator
                        int ratio_2 = 0; // the first denominator
                        int ratio_4 = 0; // the second numerator
                        int ratio_6 = 0; // the second denominator

                        for(int i=0; i<index; i++){ // convert to integer

                            if(rational_2[i] == '/'){
                                
                                string g1 = rational_2.substr(0, i);
                                ratio_0 = stoi(g1);
                                
                                string g2 = rational_2.substr(i+1, index);
                                ratio_2 = stoi(g2);
                                
                            }
                        }

                        for(int i=index+1; i<rational_2.length(); i++){ // convert to integer

                            if(rational_2[i] == '/'){
                            
                                string g3 = rational_2.substr(index+1, i);
                                ratio_4 += stoi(g3);
                                
                                string g4 = rational_2.substr(i+1, rational_2.length()); 
                                ratio_6 += stoi(g4);
                                
                            }
                        }
                                                
                        if(rational_2[index] == '+'){ // if the operation is sum

                            if(ratio_2 == 0 || ratio_6 == 0){
                            
                                cout << "Please input valid operation\n";
                                goto k;
                            }

                            count1 = (ratio_2*ratio_4 + ratio_6*ratio_0);
                            count2 = ratio_2*ratio_6;
                            int count3 = max(count1, count2); int count4 = 1;

                            for(int j=1; j<=count3; j++){
                                if(count2 % j == 0 && count1 % j == 0){ count4 = j; }
                            }

                            count1 /= count4; count2 /= count4;
                            cout << "The result is: ";
                            if(count2 != 1){
                                cout << count1 << "/" << count2 << "\n";
                            }

                            else{ cout << count1 << "\n";}
                        }

                        if(rational_2[index] == '-'){ // if the operation is sub

                            if(ratio_2 == 0 || ratio_6 == 0){
                            
                                cout << "Please input valid operation\n";
                                goto k;
                            }

                            count1 = (ratio_6*ratio_0 - ratio_2*ratio_4);
                            count2 = ratio_2*ratio_6;
                            int count3 = max(count1, count2); int count4 = 1;

                            for(int j=1; j<=count3; j++){
                                if(count2 % j == 0 && count1 % j == 0){ count4 = j; }
                            }

                            count1 /= count4; count2 /= count4;
                            cout << "The result is: ";

                            if(count2 != 1){
                                cout << count1 << "/" << count2 << "\n";
                            }

                            else{ cout << count1 << "\n";}
                        }

                        if(rational_2[index] == '*'){ // if the operation is multiply

                            if(ratio_2 == 0 || ratio_6 == 0){
                            
                                cout << "Please input valid operation\n";
                                goto k;
                            }

                            count1 = ratio_0*ratio_4;
                            count2 = ratio_2*ratio_6;
                            int count3 = max(count1, count2); int count4 = 1;
                            for(int j=1; j<=count3; j++){
                                if(count2 % j == 0 && count1 % j == 0){ count4 = j; }
                            }
                            count1 /= count4; count2 /= count4;
                            cout << "The result is: ";
                            if(count2 != 1){
                                cout << count1 << "/" << count2 << "\n";
                            }
                            else{ cout << count1 << "\n";}
                        }
                        if(rational_2[index] == '/'){ // if the operation is division
                            
                            count1 = ratio_0*ratio_6;
                            count2 = ratio_2*ratio_4;
                            
                            ///////////////////////////////////
                            if(count1 == 0 && count2 == 0){ // if division three numbers ==> the space is important
                                
                                cout << "The space is sensative to this case ==> ";
                                    
                                int sp = 0;
                                int ala = 0;
                                for(int i=0; i<rational_1.length(); i++){
                                    if(isspace(rational_1[i])){
                                        sp++; break;
                                    }
                                    else if(rational_1[i] == '/'){
                                        ala++; break;
                                    }
                                }

                                if(ala > sp){ // like 2 / 2/3 ==> division 2 over 2/3
                                              // like 2/2 / 3 ==> division 2/2 over 3
                                    rational_2 += "/1"; ov++;
                                    goto x;
                                }

                                else{
                                    int b;
                                    for(int i=0; i<rational_2.length(); i++){
                                        if(rational_2[i] == '/'){
                                            b = i; break;
                                        }
                                    }
                                    string z = rational_2.substr(0, b);
                                    z += "/1";
                                    string z2 = rational_2.substr(b, rational_2.length());
                                    z += z2;
                                    rational_2 = ""; rational_2 += z;
                                    ov++;
                                    goto x;

                                }
                            }
                            ///////////////////////////////////
                            if(ratio_2 == 0 || ratio_6 == 0 || ratio_4 == 0){
                            
                                cout << "Please input valid operation\n";
                                goto k;
                            }
                            int count3 = max(count1, count2); int count4 = 1;
                            for(int j=1; j<=count3; j++){
                                if(count2 % j == 0 && count1 % j == 0){ count4 = j; }
                            }

                            count1 /= count4; count2 /= count4;
                            if(ov == 0){
                                cout << "The result is: ";
                            }

                            if(count2 != 1){
                                cout << count1 << "/" << count2 << "\n"; // erase the one from denominator
                            }

                            if(count2 == 1){ cout << count1 << "\n";}

                        }

                    }

                    else if(over == 1 && operats > 0){ // if exist one rational with integer number
                        int sign = 0;
                        int al = 0;

                        for(int i=0; i<rational_2.length(); i++){
                            // define the priority of operations
                            if(rational_2[i] == '+' || rational_2[i] == '-' || rational_2[i] == '*'){
                                sign = i;
                            }
                            else if(rational_2[i] == '/'){
                                al = i;
                            }
                        }

                        if(sign < al){
                            string x1 = rational_2.substr(0, sign);
                            x1 += "/1";
                            string x2 = rational_2.substr(sign, rational_2.length());
                            x1 += x2;
                            rational_2 = ""; rational_2 += x1;
                            goto cc;
                        }

                        else if(sign > al){
                            rational_2 += "/1";
                            goto cc;
                        }
                    }
                    else{  // if one operation only like a + b
                    cout << "The result is: ";
                        int plus = 0;
                        int minus = 0;
                        int multi = 0;
                        int div = 0;
                        int cyrc = 0;

                        for(int i=0; i<rational_2.length(); i++){
                            if(rational_2[i] == '+'){ plus++; }
                            else if(rational_2[i] == '-'){ minus++; }
                            else if(rational_2[i] == '*'){ multi++; }
                            else if(rational_2[i] == '/'){ div++; }
                        }
                        string b1 = "";
                        string b2 = "";
                        for(int i=0; i<rational_2.length(); i++){
                            if(rational_2[i] == '+' || rational_2[i] == '-' || rational_2[i] == '*' || rational_2[i] == '/'){
                                cyrc++;
                                continue;
                            }
                            if(cyrc > 0){
                                b2  += rational_2[i];
                            }
                            else{
                                b1 += rational_2[i];
                            }
                        }
                        if(plus > 0){ cout << stoi(b1) + stoi(b2) << "\n"; }
                        if(minus > 0){ cout << stoi(b1) - stoi(b2) << "\n"; }
                        if(multi > 0){ cout << stoi(b1) * stoi(b2) << "\n"; }
                        if(div > 0){
                            int j;
                            for(int i=1; i<=stoi(b1); i++){
                                if(stoi(b1) % i == 0 && stoi(b2) % i == 0){
                                    j = i;
                                }
                            }
                            if(stoi(b2) == 0){
                                cout << "invalid logic operation, please enter vaild operation\n";
                                goto k;
                            }
                            else if(stoi(b1) == 0){
                                cout << 0 << "\n";
                            }
                            
                            else if(stoi(b2) != 1 || stoi(b2) != 0){
                                cout << stoi(b1) / j << "/" << stoi(b2) / j << "\n";
                            }
                            else if(stoi(b2) == 1){
                                cout << stoi(b1) / j << "\n";
                            }
                            
                        }
                    }
                }
            }

            else{
                cout << "invalid input, please enter valid value\n";
                goto k; // return to input valid value
            }
        }

        else{
            cout << "Thank You For Using Rational Number Calculator\n";
            break; // Exit program
        }
    }
    


    return 0;
}

/////////////////////////////////////////////// <(Algorithm)> ///////////////////////////////////////////////

// Display welcome message for the Rational Number Calculator.
// Enter into a loop that continues until explicitly exited.
// Ask the user to choose either to start the program or exit.

// Read the user's choice.
// If the choice is to start the program:

// a. Ask the user to input rational number operations in the form of "a/b +-*/ c/d".
// b. Read the input rational number operations.
// c. Remove spaces from the input.
// d. Check the validity of the input:
// Ensure that it contains only digits, '/', '*', '+', '-'.

// Avoid consecutive operations.
// e. Handle cases where there are multiple operations by:

// Locating the position of the operation.
// Splitting the input into two rational numbers based on the operation position.
// Converting substrings to integers to get numerators and denominators.

// Perform the specified arithmetic operation.
// Simplify the result by finding the greatest common divisor (GCD) of the numerator and denominator.
// f. Handle special cases where there's a mix of integers and rationals:
// Adjust the input to make the rational number valid.

// Proceed with the calculation.
// If the choice is to exit:
// Display a thank you message and exit the program.