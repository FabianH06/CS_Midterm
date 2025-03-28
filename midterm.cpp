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
        cout<<"Do you want to DECRYPT or ENCRYPT? Type EXIT to stop."<<endl;
        cin>> answer;
        cin.ignore();
        int m;
        for (m=0; m<answer.size();m++){
            answer.at(m)= tolower(answer.at(m));
        }
        if (answer == "decrypt") {
            //defining the encrypted and decrypted text
            string Encrypted;
            vector<char> Decrypted;

            //input the given encrypted message
            cout<<"Paste or type the encrypted text below:"<<endl;
            getline(cin, Encrypted);
    
            //Lines 53-64 is with the help of ChatGPT
            
            //this finds each unique letter in the text and 
            //adds to the fequency count of that letter 
            map<char, int> frequency;
    
            int n;
    
            for (n= 0; n<Encrypted.size(); n++) {
                if (isalpha(Encrypted.at(n))) {
                    frequency[toupper(Encrypted.at(n))]++;
                }
            }
    
            //removes spaces from the encrypted text in order to decipher
            Encrypted.erase(remove(Encrypted.begin(), Encrypted.end(), ' '), Encrypted.end());
    
            //make the size the same to hold same amount of characters
            Decrypted.resize(Encrypted.size());
    
            cout<<endl;
    
            int i;
            int j;
    
            //nested loop that will be used to decrypt the hidden message 
            //using one of the given keys at a time
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
                //line 99 is with the help of ChatGPT
                if (decryptedStr.find("ANTARCTICA") != string::npos) {
                    cout<<endl<<"----------------------------------------------"<<endl;
                    cout << "The correct key is: " << Keys[i] << endl;
                    cout<< "The number of letters in the encrypted text is: "<<decryptedStr.size()<<endl;
                    cout << "\nFrequency analysis of encrypted text:\n";
                    for (char letter = 'A'; letter <= 'Z'; ++letter) {
                        cout << letter << ": " << frequency[letter] << endl;
                    }
                    cout << endl;
                    cout<<"Original message: "<<endl<<decryptedStr<<endl;
                    break;
                } else {
                    cout<<"Key is incorrect!"<<endl;
                }
                cout<<endl;
            }
            cout<<endl;
        } else if (answer== "encrypt") {

            //the program generates a random seed value for the secret key
            // using the pseudorandom number equation
            srand(time(NULL));
            int seed= ((4756*rand())+1999)%47;
            int secretKey= (((1423*seed)+579)%26);
            if (secretKey==0) {
                secretKey+=1;
            }
            string Message;
            vector<char> Encrypted2;

            //takes the input of the original message here
            cout<< "Paste or type your message below: "<< endl;
            getline(cin, Message);

            Encrypted2.resize(Message.size());

            cout<<endl;

            int a;
            int b;

            //the for loop is used to shift the position of the original letter 
            //to a different letter
            for (a=0; a<Message.size(); a++) {
                if (isalpha(Message.at(a))) {
                    if (isupper(Message.at(a))) {
                        Encrypted2.at(a)= ((Message.at(a) - 'A' + secretKey) % 26) + 'A';
                    } 
                    else if (islower(Message.at(a))) {
                        Encrypted2.at(a)= ((Message.at(a) - 'a' + secretKey) % 26) + 'a';
                    }
                } else {
                    Encrypted2.at(a)= Message.at(a);
                }
            }

            //it prints out the random key that was used to shift the letter position
            //then it prints out the encrypted text
            cout<<"----------------------------------------------"<<endl;
            cout<<"The encryption key is: "<<secretKey<<endl;
            cout<<"The encrypted message is: "<<endl;
            for (b=0; b<Encrypted2.size(); b++) {
                cout<<Encrypted2.at(b);
            }
            cout<<endl<<endl;

        } else if (answer== "exit") {
            break;
        }
    }

    return 0;
}
