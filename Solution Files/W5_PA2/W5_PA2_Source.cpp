//This program displays a joke, pulled from one text file, and its punch line, pulled from a different text file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function prototypes
void displayAllLines(ifstream &);		//Display joke
void displayLastLine(ifstream &);		//Display punchline

int main()
{
	/*
	Alternative option to ask the user what the names of the joke and punch line files are - tested and works

	string joke;
	string punchLine;

	cout << "Enter the name of the joke file, then press ENTER: ";
	getline(cin, joke);

	cout << "Enter the name of the punch line file, then press ENTER: ";
	getline(cin, punchLine);

	ifstream file1(joke, ios::in);
	ifstream file2(punchLine, ios::in);

	*/

	cout << "Opening files now..." << endl << endl;

	//Open the files
	ifstream file1("joke.txt", ios::in);
	ifstream file2("punchline.txt", ios::in);

	//If both files were opened successfully, continue and process them
	if (file1 && file2)
	{
		char moveOn;		//Used to pause the system before the punchline

		//Display all lines of text from file 1 (the joke)
		cout << endl << "Joke:" << endl << endl;
		displayAllLines(file1);

		cout << endl << endl << "Press enter for the punch line...";
		cin.get(moveOn);	//Wait until the user has hit ENTER to display the punch line

		//Display the last line of text from file 2 (the punch line)
		cout << endl;
		displayLastLine(file2);

		//Close the files
		file1.close();
		file2.close();
	}

	//Display an error message if one or more files did not open successfully.
	else
	{
		cout << endl << "Error! One or more files could not be opened." << endl << endl;
	}

	system("pause");

	return 0;
}

void displayAllLines(ifstream &infile)
{
	/*
	Alternative: character-based approach - tested and works
	
	char ch;

	while (!infile.eof())		//While there are still characters in the file to be read
	{
		infile.get(ch);			//Get a character from the file

		cout << ch;				//Display the character on the screen
	}

	*/

	//String-based approach

	string str;					//Temporary holder for a line of text

	getline(infile, str, '\n');

	while (infile)				//While the last read operation was successful, continue.
	{
		cout << str << endl;	//Display the string of text that was read

		getline(infile, str, '\n');		//Get the next line of text
	}
}

void displayLastLine(ifstream &infile)
{
	char ch;			//To hold a character as the program searches
	int count = -1;		//Counter variable for position

	//Set the read position to the last character before the end of the file (offset of -1)
	infile.seekg(count, ios::end);

	//Read the last character in the file
	infile.get(ch);

	//Continue reading characters until a newline character is encountered, indicating the beginning of the last line
	while (ch != '\n')		//Continue reading as long as a newline character has not yet been found
	{
		//Display the characters read - for testing purposes only
		//cout << ch;

		//Decrement the counter variable, to move position backward from the EOF
		count--;

		//Get the next character
		infile.seekg(count, ios::end);

		//Read the character there
		infile.get(ch);
	}

	count += 2;

	//For testing purposes only
	//cout << "The current position of count is: " << count << endl << endl;

	while (count < 0)
	{
		//Seek to the position in the file where count is
		infile.seekg(count, ios::end);

		//Read the character at position count
		infile.get(ch);

		//Display the character at position count
		cout << ch;

		//Increment count to move to the next character
		count++;
	}

	cout << endl << endl;
}