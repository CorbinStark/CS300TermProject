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

/*
*                                           MANAGER TERMINAL HELPER FUNCTIONS
*   This section contains manager terminal helper functions that call database functions. Basically these just
*   exist to make main neater. I couldn't decide which file these belong in, so I slapped 'em down here. 
*   Feel free to put them somewhere else. Also, obviously to use them. 
*   -Max
*/
//Gathers input from user to pass to database addMember function
void getMember(Database & database) {
    string inputName;
    string inputStreet;
    string inputCity;
    string inputState;
    string inputZip;
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
    cout << "\n\nMember added to database.";
    return;
}

//Same as getMember but for providers
void getProvider(Database & database) {
    string inputName;
    string inputStreet;
    string inputCity;
    string inputState;
    string inputZip;

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
    cout << "\n\nProvider added to database.";
    return;
}

//Prompts user for ID to delete, displays name to confirm with user, 
//prompts for confirmation, deletes if confirmation is provided
void deleteMember(Database & database) {
    string inputID;
    char input;
    
    cout << "\nPlease input the ID of the member to delete: ";
    getline(cin, inputID);
    Member memberToDelete = database.members.at(inputID);
    cout << "\nThat member ID matches the following member: " << memberToDelete.name;
    cout << "\nAre you sure you want to delete? y/n: ";
    cin >> input;
    
    if(toupper(input) == 'Y'){
        cout << "\nMember has been removed";
        database.removeMember(inputID);
        database.update();
    }
    else {
        cout << "\nThe member has not been removed.";
    }
    return;
}
//Same as deleteMember, but for providers
void deleteProvider(Database & database) {
    string inputID;
    char input;

    cout << "\nPlease input the ID of the provider to delete: ";
    getline(cin, inputID);
    Provider providerToDelete = database.providers.at(inputID);
    cout << "\nThat provider ID matches the following provider: " << providerToDelete.name;
    cout << "\nAre you sure you want to delete? y/n: ";
    cin >> input;
    if(toupper(input) == 'Y'){
        cout << "\nProvider has been removed";
        database.removeProvider(inputID);
        database.update();
    }
    else {
        cout << "\nThe provider has not been removed.";
    }
    return;
}

//prompts user for ID to pass to database editMember function
void changeMember(Database & database) {
    string inputID;
    
    cout << "\nPlease input the name of the member to edit: ";
    getline(cin, inputID);
    database.editMember(inputID);
    return;
}

//Again, same as member but for provider
void changeProvider(Database & database) {
    string inputID;
    
    cout << "\nPlease input the name of the provider to edit: ";
    getline(cin, inputID);
    database.editProvider(inputID);
    return;
}