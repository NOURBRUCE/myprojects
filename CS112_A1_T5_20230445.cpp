//  Program: Nour Alaa Hasan Nim
//  Purpose: A Nim game in Python. 100 game. Two players start from 0 and alternatively 
//           add a number from 1 to 10 to the sum. The player who reaches 100 wins.
//  Author:  Dr Mohammad El-Ramly and Nour Alaa Hasan
//  Date:    1 March 2024
//  ID:      20230445
//  version: 1.0
//  Game:    1

#include<bits/stdc++.h> 
using namespace std;

int main() {
    // Initialize the result to 0ٍٍٍ
    int result = 0;

    // Welcome message
    cout << "Welcome to 100 game" << endl;
    cout << "Please enter a number from 1 to 10" << endl;

    // Main game loop
    while (true) {
        // Player 1's turn
        if (result >= 90) {
            // If result is 90 or more, limit Player 1's input to reach 100
            int sub = 100 - result;

            // Input loop for Player 1
            while (true) {
                try {
                    // Prompt for Player 1 to enter a number in the specified range
                    cout << "Player1: please enter a number from 1 to " << sub << endl;
                    
                    // Input the number from Player 1
                    int num;
                    cin >> num;

                    // Check if the input is within the specified range
                    if (1 <= num && num <= sub) {
                        result += num;
                        break;
                    } else {
                        // If input is not within the specified range, display an error message
                        cout << "Please enter a valid number in the specified range." << endl;
                        
                        // Clear the error state and ignore the invalid input in the buffer
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } catch (const invalid_argument& e) {
                    // Handle non-integer inputs
                    cout << "Invalid input. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } catch (const out_of_range& e) {
                    // Handle input out of range
                    cout << "Input out of range. Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        } else {
            // Input loop for Player 1
            while (true) {
                try {
                    // Prompt for Player 1 to enter a number
                    int player1;
                    cout << "Player1: enter your number" << endl;
                    cin >> player1;

                    // Check if the input is within the specified range
                    if (1 <= player1 && player1 <= 10) {
                        result += player1;
                        break;
                    } else {
                        // If input is not within the specified range, display an error message
                        cout << "Please enter a valid number in the specified range." << endl;
                        
                        // Clear the error state and ignore the invalid input in the buffer
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } catch (const invalid_argument& e) {
                    // Handle non-integer inputs
                    cout << "Invalid input. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } catch (const out_of_range& e) {
                    // Handle input out of range
                    cout << "Input out of range. Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }

        // Print the total after Player 1's turn
        cout << "The total is: " << result << endl;

        // Check if Player 1 has reached 100 and declare the winner
        if (result == 100) {
            cout << "The winner is Player 1" << endl;
            break;
        }

        // Player 2's turn
        if (result >= 90) {
            // If result is 90 or more, limit Player 2's input to reach 100
            int sub = 100 - result;

            // Input loop for Player 2
            while (true) {
                try {
                    // Prompt for Player 2 to enter a number in the specified range
                    cout << "Player2: please enter a number from 1 to " << sub << endl;
                    
                    // Input the number from Player 2
                    int num;
                    cin >> num;

                    // Check if the input is within the specified range
                    if (1 <= num && num <= sub) {
                        result += num;
                        break;
                    } else {
                        // If input is not within the specified range, display an error message
                        cout << "Please enter a valid number in the specified range." << endl;
                        
                        // Clear the error state and ignore the invalid input in the buffer
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } catch (const invalid_argument& e) {
                    // Handle non-integer inputs
                    cout << "Invalid input. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } catch (const out_of_range& e) {
                    // Handle input out of range
                    cout << "Input out of range. Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        } else {
            // Input loop for Player 2
            while (true) {
                try {
                    // Prompt for Player 2 to enter a number
                    int player2;
                    cout << "Player2: enter your number" << endl;
                    cin >> player2;

                    // Check if the input is within the specified range
                    if (1 <= player2 && player2 <= 10) {
                        result += player2;
                        break;
                    } else {
                        // If input is not within the specified range, display an error message
                        cout << "Please enter a valid number in the specified range." << endl;
                        
                        // Clear the error state and ignore the invalid input in the buffer
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } catch (const invalid_argument& e) {
                    // Handle non-integer inputs
                    cout << "Invalid input. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } catch (const out_of_range& e) {
                    // Handle input out of range
                    cout << "Input out of range. Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }

        // Print the total after Player 2's turn
        cout << "The total is: " << result << endl;

        // Check if Player 2 has reached 100 and declare the winner
        if (result == 100) {
            cout << "The winner is Player 2" << endl;
            break;
        }
    }

    return 0;
}