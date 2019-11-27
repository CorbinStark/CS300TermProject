/**
 * Created by Bela, Cody Potter, Corbin Stark, Dan Scott, Forest Pearson, Max VanRaden
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
                cout << "\nPlease enter the name of the provider to add: ";
                getline(cin, inputName);
                cout << "\nPlease enter the street address of the provider to add: ";
                getline(cin, inputStreet);
                cout << "\nPlease enter the name of the city in which the provider is located: ";
                getline(cin, inputCity);
                cout << "\nPlease enter the state of the provider to add: ";
                getline(cin, inputState);
                cout << "\nPlease enter the zip of the provider to add: ";
                getline(cin, inputZip);
                database.addProvider(inputName, inputStreet, inputCity, inputState, inputZip);
                database.update();
                cout << "\n\nProvider added to database."
                break;
            case 'b':
                cout << "\nPlease enter the name of the member to add: ";
                getline(cin, inputName);
                cout << "\nPlease enter the street address of the member to add: ";
                getline(cin, inputStreet);
                cout << "\nPlease enter the name of the city in which the member is located: ";
                getline(cin, inputCity);
                cout << "\nPlease enter the state of the member to add: ";
                getline(cin, inputState);
                cout << "\nPlease enter the zip of the member to add: ";
                getline(cin, inputZip);
                database.addMember(inputName, inputStreet, inputCity, inputState, inputZip);
                database.update();
                cout << "\n\nMember added.";
                break;
            case 'c':

                break;
            case 'd':
                break;
            case 'e':
                cout << "\nPlease input the ID of the provider to delete: ";
                getline(cin, inputID);
                database.removeProvider(inputID);
                break;
            case 'f':
                cout << "\nPlease input the ID of the member to delete: ";
                getline(cin, inputID);
                database.removeMember(inputID);
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
