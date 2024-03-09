// File: Baconian Cipher & Affine Cipher & Simple Substitution Cipher
// Purpose: encrypt and decrypt words for 3 programs above

// Author1: Aya Magdi Ali Ahmed ==> ID: 20230084 ==> Emails: A.M.A2004@xed.aucegypt.edu

// Author2: Adam Samir Farouk Ibrahim ==> ID: 20230040 ==> Emails: adamsamir@Hotmail.com 

// Author3: Nour Alaa Hasan ==> ID: 20230445 ==> Emails: nwrlanwrla56@gmail.com

// Affine Cipher is done by==> Adam Samir Farouk Ibrahim
// Baconian Cipher is done by==> Aya Magdi Ali Ahmed
// Simple Substitution Cipher is done by ==> Nour Alaa Hasan



#include <bits/stdc++.h> 
using namespace std;

/////////////////////////////////////////////////// the functions of Affine Cipher ///////////////////////////////////////////////////////

string solve() {
    cout << "Please input your desired sentence: ";
    string str;
    getline(cin, str);

    int final;
    string cipher;
    int len = str.length();
    int x;
    
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    for (int i = 0; i != len; i++) {
        if (isalpha(str[i])) {
            if (str[i] == ' ') {
                cipher += ' ';
            } else {
                x = int(str[i]) - int('A');
                final = (5 * x + 8) % 26;
                cipher += char(final + 'A');
            }
        } else {
            cipher += str[i];
        }
    }
    
    return cipher;
}

string antisolve() {
    cout << "Welcome to decryption, please insert a sentence to decrypt\n";
    string str;
    cin.ignore();
    getline(cin, str);

    string message;
    int y;
    int final;
    int len = str.length();
    
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (str[i] == ' ') {
                message += ' ';
            } else {
                y = int(str[i]) - int('A');
                final = (21 * (y - 8)) % 26;
                if (final < 0) {
                    final += 26;
                }
                message += char(final + 'A');
            }
        } else {
            message += str[i];
        }
    }

    return message;
}

bool menu() {
    cout << "Welcome to the Affine cipher, please select an option (all special characters and numbers aren't encrypted)" << endl;
    
    while (true) {
        cout << "1-Encrypt a message" << endl;
        cout << "2-Decrypt a message" << endl;
        cout << "3-Exit code" << endl;
        
        string response;
        cin >> response;

        if (response == "1") {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Your encrypted code is: " << solve() << endl;
            cout << "==============================" << endl;
        } else if (response == "2") {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Your decrypted code is: " << antisolve() << endl;
            cout << "==============================" << endl;
        } else if (response == "3") {
            cout << "Exiting Affine Cipher program\n";
            return true;
        } else {
            cout << "Please input a correct number" << endl;
        }
    }

    return false;
}

//////////////////////////////////////////////////// the fuctions of  Baconian Cipher //////////////////////////////////////////////////////////////////

string encrypt(string pt)
{
    string key[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I",
                      "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                      "U", "V", "W", "X", "Y", "Z"};
    string value[26] = {"AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA", "AABAB",
                        "AABBA", "AABBB", "ABAAA", "ABAAB", "ABABA", "ABABB",
                        "ABBAA", "ABBAB", "ABBBA", "ABBBB", "BAAAA", "BAAAB",
                        "BAABA", "BAABB", "BABAA", "BABAB", "BABBA", "BABBB", "BBAAA", "BBAAB"};
    string encpt1 = "";
    for (int i = 0; i < pt.length(); i++)
    {
        char c = toupper(pt[i]);  // Convert to uppercase
        if (c >= 'A' && c <= 'Z') // Check if it's a valid alphabet
        {
            encpt1 += value[c - 'A']; // Use ASCII value to map to array index
        }
        // Ignore spaces and other characters
    }
    return encpt1;
}

string decrypt(string encpt)
{
    string value[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I",
                        "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                        "U", "V", "W", "X", "Y", "Z"};
    string key[26] = {"AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA", "AABAB",
                      "AABBA", "AABBB", "ABAAA", "ABAAB", "ABABA", "ABABB",
                      "ABBAA", "ABBAB", "ABBBA", "ABBBB", "BAAAA", "BAAAB",
                      "BAABA", "BAABB", "BABAA", "BABAB", "BABBA", "BABBB", "BBAAA", "BBAAB"};
    string decpt1 = "";
    for (int i = 0; i < encpt.length(); i += 5)
    {
        string chunk = encpt.substr(i, 5); // Extract a chunk of 5 characters
        for (int j = 0; j < 26; j++)
        {
            if (chunk == key[j])
            {
                decpt1 += value[j];
                break;
            }
        }
    }
    return decpt1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
cout << "Welcome To Programs of Ciphers \n";

while(true){
cout << "Please enter 1 || 2 || 3 or any character to exit \n";
cout << "1) Simple Substitution Cipher \n";
cout << "2) Affine Cipher \n";
cout << "3) Baconian Cipher \n";
cout << "Any character to exit \n";

string c;
getline(cin, c);

    if(c == "1"){

/////////////////////////////////////// Welcome To Simple Substitution Cipher /////////////////////////////////////////////////////////////////

    cout << "Welcome To Simple Substitution Cipher \n";  //welcome message

    while(true){  //infinit loop
        cout << "\nA: to incryption \n";
        cout << "B: to decryption \n";
        cout << "Any character: to exit \n";

        char c; cin >> c;
        if(c == 'a' || c == 'A'){
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cout << "Please enter the key to cipher a message \n";  //Ask user input cipher message
            string key; // variable of cipher message
            string k = ""; 
            getline(cin, key);  // include spaces at the input

            for(int i=0; i<key.length(); i++){  // this loop to make all characters small(lowerCase) & avoid any special char or spaces or numbers
                if(isupper(key[i])){
                    k += char(tolower(key[i])); // put new cipher message in variable k
                }
                else if(islower(key[i])){ k += key[i]; }
                else{ continue; }
            }

            // make vector to erase what i would 
            vector <char> s1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            string s2 = ""; 

            for(int i=0; i<k.length(); i++){ // this loop to erase characters of k from vector
                auto it = find(s1.begin(), s1.end(), k[i]);
                s1.erase(it);
            }

            s2 = k + string(s1.begin(), s1.end()); // s2 ==> cipher alphabet
       
            cout << "Please enter the message\n"; // take plain text 
            cout << "Plain message  : ";
            string message;
            string g = "";
            getline(cin, message); // include spaces at plain text

            for(int i=0; i<message.length(); i++){
                if(isupper(message[i])){
                    g += char(tolower(message[i])); // make plain text in lowerCase
                }
                else{ g += message[i]; } // put new plain text in variable g
            }

            cout << "Cipher message : ";
            string x ="abcdefghijklmnopqrstuvwxyz"; // plain alphabet 

            for(int i=0; i<g.length(); i++){
                if(g[i] == ' '){ cout << " "; } // print the spaces as same
                else{
                    for(int j=0; j<x.length(); j++){ // this loop make cipher text
                        if(g[i] == x[j]){
                            cout << s2[j];
                        }
                        else{ continue; } // avoid any special chars or numbers
                    }
                }
            }
        
        }
        else if(c == 'b' || c == 'B'){
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cout << "Please enter the key to decipher a message \n";  //Ask user input cipher message
            string key; // variable of cipher message
            string k = ""; 
            getline(cin, key);  // include spaces at the input

            for(int i=0; i<key.length(); i++){  // this loop to make all characters small(lowerCase) & avoid any special char or spaces or numbers
                if(isupper(key[i])){
                    k += char(tolower(key[i])); // put new cipher message in variable k
                }
                else if(islower(key[i])){ k += key[i]; }
                else{ continue; }
            }

            // make vector to erase what i would 
            vector <char> s1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            string s2 = ""; 

            for(int i=0; i<k.length(); i++){ // this loop to erase characters of k from vector
                auto it = find(s1.begin(), s1.end(), k[i]);
                s1.erase(it);
            }

            s2 = k + string(s1.begin(), s1.end()); // s2 ==> cipher alphabet
            cout << "Please enter the message\n"; // take encrypted text 
            cout << "encrypted message: ";
            string message;
            string g = "";
            getline(cin, message); // include spaces at encrypted text

            for(int i=0; i<message.length(); i++){
                if(isupper(message[i])){
                    g += char(tolower(message[i])); // make encrypted text in lowerCase
                }
                else{ g += message[i]; } // put new encrypted text in variable g
            }

            cout << "decypted message : ";
            string x ="abcdefghijklmnopqrstuvwxyz"; // plain alphabet 

            for(int i=0; i<g.length(); i++){
                if(g[i] == ' '){ cout << " "; } // print the spaces as same
                else{
                    for(int j=0; j<x.length(); j++){ // this loop make decrypted text
                        if(g[i] == s2[j]){
                            cout << x[j];
                        }
                        else{ continue; } // avoid any special chars or numbers
                    }
                }
            }

        }
        else {
            cout << "Exiting Program \n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            break;
        }

    }
    continue;
    }

///////////////////////////////////////////////////////// End of Simple Substitution Cipher ////////////////////////////////////////////////////////////////////

    else if(c == "2"){  // Affine cipher
        menu();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    }

    else if(c == "3"){  // Baconian Cipher
    string pt, encpt, decpt;
    string choice;
    cout << "WELCOME IN Baconian Cipher \n";
    v :
    cout << "1. Encryption\n2. Decryption\n3. EXIt\n Enter your choice (1 or 2 or 3): ";
    
    while(true){
        cin >> choice;
        cin.ignore();
        if (choice =="1")
        {
            cout << "\nEncryption\n";
            cout << "Enter your text: ";
            getline(cin, pt); // Read the entire line
            encpt = encrypt(pt);
            cout << "Encrypted Text: " << encpt << endl;
            goto v;
        }
        else if (choice == "2")
        {
            cout << "\nDecryption\n";
            cout << "Enter your text: ";
            getline(cin, pt); // Read the entire line
            // convert the decrypted text toupper
            for( char & c : pt){
                c = toupper(c);
            }
            decpt = decrypt(pt);
            cout << "Decrypted Text: " << decpt << endl;
            goto v;
        }
        else if (choice =="3"){
            cout<<"Exit the program\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter 1 or 2 or 3" << endl;
        }

    }
    }

    else{
        cout << "Exiting the pragrams of cipher \n";
        break;
    }


}

    return 0;
}