#include <iostream>
#include <fstream>// files
#include <string> // getline
#include <chrono> // time
#include <random>
#include <windows.h> // sleep

using namespace std;

/*	Encrypting file with words

	ifstream file{ "words.txt" };
	ofstream fileout{ "out.txt "};
	string test;
	while (file.is_open() && fileout.is_open())
	{
		for (int i = 0; i < 416354; i++)
		{
			getline(file, test);
			for(int i = 0; i < test.length(); i++)
				test[i] = tolower(test[i]) - 64;
			fileout << test << "\n";
		}
		file.close();
	}
*/

int randNumber(unsigned int start, unsigned int end)
{
	random_device device;
	uniform_int_distribution<int> distribution(start, end);
	return distribution(device);
}

class GameWord
{
private:
	string _lettersTried;
	string _word;
	string _wordFound;
	int _letters;
	int _lettersFound;
	
public:
	GameWord()
	{
		_word = "";
		_wordFound = "";
		_lettersTried = "";
		_letters = 0;
		_lettersFound = 0;
	}
	void setRandom()
	{
		ifstream file{ "out.txt" };
		while (file.is_open())
		{
			for (int i = 0; i < randNumber(0, 416354); i++)//counting amount of the lines is taking too much time
			{
				getline(file, _word);
			}
			file.close();
		}
		for (int i = 0; i < _word.length(); i++)
			_word[i] += 64;
		_letters = _word.length();
		_lettersFound = 0;
		_wordFound.clear();
		_wordFound = "";
		_lettersTried = "";
		for (int i = 0; i < _letters; i++)
			_wordFound.append("_");
	}
	void showFound()
	{
		cout << "Word: " << _wordFound << "\n";
	}
	string getWord()
	{
		return _word;
	}
	bool find(char letter)
	{
		if (_wordFound.find(letter) != -1)// if letter was already guessed
		{
			return true;
		}
		else if (_word.find(letter) != -1)// if there is letter
		{
			for (int i = 0; i < _letters; i++)
			{
				if (_word[i] == letter)
				{
					_wordFound[i] = letter;
					_lettersFound++;
				}
			}
			return true;
		}
		_lettersTried += letter;
		return false;
	}
	bool isFound()
	{
		return (_lettersFound == _letters);
	}
	int getLettersFound()
	{
		return _lettersFound;
	}
	string getLettersTried()
	{
		return _lettersTried;
	}
};

class Game
{
private:
	int _attemps;
	bool _gameRepeat;
	bool _didWin;
public:
	Game()
	{
		_attemps = 0;
		_gameRepeat = 1;
		_didWin = 0;
	}
	void loadScreen(int attemps)
	{
		switch (attemps)
		{
		case 0:
			cout << "+---+\n";
			cout << "|   |\n";
			cout << "|   O\n";
			cout << "|  /|\\\n";
			cout << "|  / \\\n";
			break;
		case 1:
			cout << "+---+\n";
			cout << "|   |\n";
			cout << "|   O\n";
			cout << "|  /|\\\n";
			cout << "|  /\n";
			break;
		case 2:
			cout << "+---+\n";
			cout << "|   |\n";
			cout << "|   O\n";
			cout << "|  /|\\\n";
			cout << "|\n";
			break;
		case 3:
			cout << "+---+\n";
			cout << "|   |\n";
			cout << "|   O\n";
			cout << "|  /|\n";
			cout << "|\n";
			break;
		case 4:
			cout << "+---+\n";
			cout << "|   |\n";
			cout << "|   O\n";
			cout << "|  /\n";
			cout << "|\n";
			break;
		case 5:
			cout << "+---+\n";
			cout << "|   |\n";
			cout << "|   O\n";
			cout << "|\n";
			cout << "|\n";
			break;
		case 6:
			cout << "+---+\n";
			cout << "|   |\n";
			cout << "|\n";
			cout << "|\n";
			cout << "|\n";
			break;
		default:
			break;
		}
	}
	void loadLogo()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int delay = 200;
		int state;
		SetConsoleTextAttribute(hConsole, 15);
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:
				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:
				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:
				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:
				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:
				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:
				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
			Sleep(delay);
		}
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				SetConsoleTextAttribute(hConsole, 6);
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:
				SetConsoleTextAttribute(hConsole, 15);
				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:
				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:

				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:

				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:
				
				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:
				SetConsoleTextAttribute(hConsole, 6);
				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:
				
				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:

				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:

				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:
				SetConsoleTextAttribute(hConsole, 6);
				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:
				
				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:

				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:
				
				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, 15);
				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, 6);
				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:
				
				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:
				
				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:

				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:

				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:
				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:
				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:

				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:

				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				SetConsoleTextAttribute(hConsole, 4);
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:
				SetConsoleTextAttribute(hConsole, 6);
				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:
				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:

				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:

				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:

				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:
				SetConsoleTextAttribute(hConsole, 4);
				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:
				
				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, 6);
				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:

				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:

				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:
				SetConsoleTextAttribute(hConsole, 4);
				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:
				
				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:

				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:
				
				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, 6);
				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, 4);
				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:
				
				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:

				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:

				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:

				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:
				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:
				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:

				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:

				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				SetConsoleTextAttribute(hConsole, 0);
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:
				SetConsoleTextAttribute(hConsole, 4);
				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:
				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:

				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:

				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:

				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:
				SetConsoleTextAttribute(hConsole, 0);
				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:

				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, 4);
				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:

				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:

				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:
				SetConsoleTextAttribute(hConsole, 0);
				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:

				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:

				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:

				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, 4);
				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, 0);
				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:

				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:

				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		Sleep(delay);
		system("cls");
		for (state = 0; state < 7; state++)
		{
			switch (state)
			{
			case 0:
				cout << " ___  ___  ________  ________   ________  _____ ______   ________  ________\n";
				break;
			case 1:

				cout << "|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\ \n";
				break;
			case 2:

				cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n";
				break;
			case 3:
				cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n";
				break;
			case 4:
				cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n";
				break;
			case 5:

				cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \n";
				break;
			case 6:

				cout << "    \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__| \n";
				break;
			default:
				break;
			}
		}
		system("cls");
		Sleep(delay);
		SetConsoleTextAttribute(hConsole, 15);
	}
	void playerTurn(GameWord& word, int& _attemps)
	{
		string choise;// in case there are more that 1 character
		system("cls");
		loadScreen(_attemps);
		word.showFound();
		cout << "Letters found: " << word.getLettersFound() << "\n";
		cout << "Attemps left: " << _attemps << "\n";
		cout << "Enter a letter: "; cin >> choise;
		if (!word.find(tolower(choise[0])))
		{
			_attemps--;
		}
	}
	void play()
	{
		while (_gameRepeat) // loop for repeating the game
		{
			auto start = chrono::high_resolution_clock::now();
			GameWord word;
			word.setRandom();
			_attemps = 6; 
			_didWin = 0;
			while (!_didWin) // loop for one game
			{
				playerTurn(word, _attemps);
				if (word.isFound())
					_didWin = true;
				else if (_attemps == 0)
					break;
			}
			system("cls");
			loadScreen(_attemps);
			word.showFound();
			cout << "Attemps left out of 6: " << _attemps << "\n";
			cout << "You wrong guesses: " << word.getLettersTried() << "\n";
			if (_didWin)
				cout << "You won!\n";
			else
				cout << "You lost!\n";
			cout << "The word was: " << word.getWord() << "\n";
			cout << "Time spent: " << chrono::duration_cast<chrono::seconds>(chrono::high_resolution_clock::now() - start).count() << " seconds\n";
			cout << "In ordrer to exit press 0... "; cin >> _gameRepeat;
		}
	}
};

int main()
{
	Game game;
	game.loadLogo();
	game.play();
	
}