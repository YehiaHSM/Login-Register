#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string dataFilePath = "user_data.txt"; // Highlighted: Specify the file path

// Function to register a new user
void registerUser() {
	string username, password;

	cout << "Enter your desired username: ";
	cin >> username;

	// Check if the username already exists
	ifstream userFile(dataFilePath); // Highlighted: Use specified file path
	string storedUsername;

	while (userFile >> storedUsername) {
		if (storedUsername == username) {
			cout << "Username already exists. Please choose a different one." << endl;
			userFile.close();
			return;
		}
	}

	userFile.close();

	cout << "Enter your password: ";
	cin >> password;

	// Save user credentials to the file
	ofstream userDataFile(dataFilePath, ios::app); // Highlighted: Use specified file path, open in append mode
	userDataFile << username << " " << password << endl;
	userDataFile.close();

	cout << "Registration successful. You can now log in." << endl;
}

// Function to authenticate a user
bool loginUser() {
	string username, password, storedUsername, storedPassword;

	cout << "Enter your username: ";
	cin >> username;

	// Check if the username exists
	ifstream userFile(dataFilePath); // Highlighted: Use specified file path

	bool userFound = false;
	while (userFile >> storedUsername >> storedPassword) {
		if (storedUsername == username) {
			userFound = true;
			break;
		}
	}

	userFile.close();

	if (!userFound) {
		cout << "User not found. Please register first." << endl;
		return false;
	}

	cout << "Enter your password: ";
	cin >> password;

	// Check if the entered password matches the stored password
	if (password == storedPassword) {
		cout << "Login successful. Welcome, " << username << "!" << endl;
		return true;
	}
	else {
		cout << "Incorrect password. Login failed." << endl;
		return false;
	}
}
