/**
 * Created by Bela, Cody Potter, Corbin Stark, Dan Scott, Forest Pearson, Max Van Raden
 */

#include <iostream>
#include "Database.h"
using namespace std;

int main(int argc, char** argv) {
    Database database((char*) "data/sample-db.json");
    

    cout << "Welcome to the ChocAn Simulator." << endl;
    cout << "Would you like to simulate the (m)anager terminal or the (p)rovider terminal?" << endl;
    char res = 0;
    while(res != 'm' && res != 'p') {
        cin >> res;
        if(res != 'm' && res != 'p')
            cout << "Invalid input. Type 'm' for the manager terminal or 'p' for the provider terminal." << endl;
    }

    char choice = 0;
    //Manager Terminal Simulation//
    if(res == 'm') {
        string inputName;
        string inputStreet;
        string inputCity;
        string inputState;
        string inputZip;
        string inputID;
        do {
            cout << "Welcome to the manager terminal. Please select an option." << endl;
            cout << "(a) Add a new provider" << endl;
            cout << "(b) Add a new member" << endl;
            cout << "(c) Edit a provider" << endl;
            cout << "(d) Edit a member" << endl;
            cout << "(e) Delete a provider" << endl;
            cout << "(f) Delete a member" << endl;
            cout << "(x) Exit" << endl;
            cin >> choice;
        }
        while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' && choice != 'f' && choice !='x');

        switch(choice) {
            case 'a': 
                getMember(database);
                break;
            case 'b':
                getProvider(database);
                break;
            case 'c':
                changeMember(database);
                break;
            case 'd':
                changeProvider(database);
                break;
            case 'e':
                deleteProvider(database);
                break;
            case 'f':
                deleteMember(database);
                break;
            case 'x':
                break;
        }
    }

    if(res == 'p') {
        do {
            cout << "Welcome to the provider terminal" << endl;
            cout << "(a) View the provider directory" << endl;
            cout << "(b) Provide service" << endl;
            cout << "(x) Exit" << endl;
            cin >> choice;
        }
        while(choice != 'a' && choice != 'b' && choice != 'x');

        switch(choice) {
            case 'a':
                break;
            case 'b':
                break;
            case 'x':
                break;
        }
    }

    return 0;
}
