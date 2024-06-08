#include "Fun.h"

int main() {
	int choice;

	do {
		cout << "[1] Register\n[2] Login\n[3] Exit\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			registerUser();
			break;
		case 2:
			if (loginUser()) {
				cout << "Your username and password are correct" << endl;
			}
			else {
				cout << "Incorrect username or password" << endl;
			}
			break;
		case 3:
			cout << "Exiting the program. Goodbye!" << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 3);

	return 0;
}
