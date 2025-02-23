#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayGitHubCard(const string& username) {
    clearScreen();
    cout << "\n=== GitHub Profile ===" << endl;
    cout << "======================" << endl;
    cout << "| Username: " << username << endl;
    cout << "| Profile:  https://github.com/" << username << endl;
    cout << "======================" << endl;
    cout << "\nCheck out my awesome projects!" << endl;
}

int main() {
    string githubUsername;
    char choice;
    
    cout << "Let's set up your GitHub redirector!" << endl;
    cout << "Enter your GitHub username: ";
    getline(cin, githubUsername);

    do {
        displayGitHubCard(githubUsername);
        
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Open GitHub profile in browser" << endl;
        cout << "2. Change username" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice (1-3): ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch(choice) {
            case '1':
                #ifdef _WIN32
                    system(("start https://github.com/" + githubUsername).c_str());
                #else
                    system(("xdg-open https://github.com/" + githubUsername).c_str());
                #endif
                break;
            case '2':
                cout << "Enter new GitHub username: ";
                getline(cin, githubUsername);
                break;
            case '3':
                cout << "Thanks for using the GitHub redirector!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-3." << endl;
        }
        
        if (choice != '3') {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        
    } while (choice != '3');

    return 0;
}
