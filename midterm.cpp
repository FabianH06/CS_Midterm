#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;

//Members: Fabian Hasin, Sajid Rahman, and Felix de los Santos

int main() {
    //defining the encrypted and decrypted text
    string Encrypted;
    vector<char> Decrypted;

    //list of all the given keys
    vector<string> Keys= {
        "savory", "weary", "colorful", "ducks", "time", "slimy", "travel", "aware",
        "dry", "troubled", "queue", "expect", "splendid", "unsuitable", "workable",
        "middle", "evanescent", "zephyr", "brave", "wind", "apparatus", "sand",
        "complete", "disappear", "invincible", "sedate", "test", "rustic", "steady",
        "rainstorm", "foolish", "gabby", "cherry", "daily", "heal", "rose", "boat",
        "reward", "trust", "tremble", "discreet", "enormous", "settle", "fit",
        "vessel", "parched", "chickens", "desire", "practice", "terrific", "imminent",
        "fuzzy", "debt", "medical", "industry", "run", "tow", "raise", "juice",
        "plant", "range", "unusual", "breakable", "quiet", "early", "mother",
        "tomatoes", "woebegone", "psychedelic", "shocking", "elated", "deranged",
        "bouncy", "wood", "three", "deceive", "flavor", "blind", "brick", "spray",
        "fretful", "hanging", "hallowed", "hurry"
    };

    string answer;

    while (true) {
        //asks you to type one of the three options
        cout<<"Do you want to DECRYPT or ENCRYPT? Type EXIT to stop."<<endl;
        cin>> answer;
        cin.ignore();
        int m;
        //turns the answer to lower to go to the designated if statement
        for (m=0; m<answer.size();m++){
            answer.at(m)= tolower(answer.at(m));
        }
        if (answer == "decrypt") {
            //input the given encrypted message
            cout<<"Paste the encrypted text here:"<<endl;
            getline(cin, Encrypted);
    
            //Lines 55-66 is with the help of ChatGPT
            
            // this finds each unique letter in the text and 
            // adds to the fequency count of that letter 
            map<char, int> frequency;
    
            int n;
    
            for (n= 0; n<Encrypted.size(); n++) {
                if (isalpha(Encrypted.at(n))) {
                    frequency[toupper(Encrypted.at(n))]++;
                }
            }
    
            // removes spaces from the encrypted text in order to decipher
            Encrypted.erase(remove(Encrypted.begin(), Encrypted.end(), ' '), Encrypted.end());
    
            //make the size the same to hold same amount of characters
            Decrypted.resize(Encrypted.size());
    
            cout<<endl;
    
            int i;
            int j;
            int k;
    
            //nested loop that will be used to decrypt the hidden message until it finds the correct key
            for (i= 0; i<Keys.size(); i++) {
                cout<<"Current key is: "<<Keys[i]<<endl;
                for (j= 0; j<Encrypted.size(); j++) {
                    if (isalpha(Encrypted.at(j))) {
                        char keyChar = Keys[i].at(j % Keys[i].size());
                        if (isupper(Encrypted.at(j))) {
                            Decrypted.at(j) = 
                            (Encrypted.at(j) - 'A' - (keyChar - 'a') + 26) % 26 + 'A';
                        } else if (islower(Encrypted.at(j))) {
                            Decrypted.at(j) = 
                            (Encrypted.at(j) - 'a' - (keyChar - 'a') + 26) % 26 + 'a';
                        } 
                    } else {
                        Decrypted.at(j) = Encrypted.at(j);
                    }
                }
    
                //copies the vector, Decrypted, as a string
                string decryptedStr(Decrypted.begin(), Decrypted.end());
    
                // The code checks for a key word "ANTARCTICA"
                // if it is present, the program exists loop and displays the result
                //line 101 is with the help of ChatGPT
                if (decryptedStr.find("ANTARCTICA") != string::npos) {
                    cout<<endl<<"-------------------------------------"<<endl;
                    cout << "The correct key is: " << Keys[i] << endl;
                    cout<< "The number of letters in the encrypted text is: "<<decryptedStr.size()<<endl;
                    cout << "\nFrequency analysis of encrypted text:\n";
                    for (char letter = 'A'; letter <= 'Z'; ++letter) {
                        cout << letter << ": " << frequency[letter] << endl;
                    }
                    cout << endl;
                    cout<<"Original message: "<<endl<<decryptedStr<<endl;
                    break; // Stop checking further keys once found
                } else {
                    cout<<"Key is incorrect!"<<endl;
                }
                cout<<endl;
            }
            cout<<endl;
        } else if (answer== "encrypt") {
            cout<<"awaiting for code..."<<endl;
        } else if (answer== "exit") {
            break;
        }
    }

    return 0;
}
