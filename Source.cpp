#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class GameWord
{
private:
	string _word;
	string _wordFound;
	int _letters;
	int _lettersFound;
public:
	GameWord()
	{
		_word = "";
		_wordFound = "";
		_letters = 0;
		_lettersFound = 0;
	}
	void setRandom()
	{
		ifstream file{ "words.txt" };
		while (file.is_open())
		{
			for (int i = 0; i < rand() % 466427; i++)//counting amount of the lines is taking too much time
			{
				getline(file, _word);
			}
			file.close();
		}
		_letters = _word.length();
		_lettersFound = 0;
		_wordFound.clear();
		_wordFound = "";
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
		if (_wordFound.find(letter) != -1 && _wordFound.find(toupper(letter)) != -1)// if letter was already guessed
		{
			return true;
		}
		else if(_word.find(letter) != -1 || _word.find(toupper(letter)) != -1)// if there is letter
		{
			for (int i = 0; i < _letters; i++)
			{
				if (_word[i] == letter)
				{
					_wordFound[i] = letter;
					_lettersFound++;
				}
				if (_word[i] == toupper(letter))
				{
					_wordFound[i] = toupper(letter);
					_lettersFound++;
				}
			}
			return true;
		}
		return false;
	}
	bool isFound()
	{
		return (_lettersFound == _letters);
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

	void playerTurn(GameWord& word, int _attemps)
	{
		string choise;// in case there are more that 1 character
		system("cls");
		loadScreen(_attemps);
		word.showFound();
		cout << "Enter a letter: "; cin >> choise;
		if (!word.find(tolower(choise[0])))
		{
			_attemps--;
		}
	}
	void play()
	{
		srand(time(0));
		while (_gameRepeat) // loop for repeating the game
		{
			GameWord word;
			word.setRandom();
			_attemps = 6;
			while (!_didWin) // loop for one game
			{
				playerTurn(word, _attemps);
				if (word.isFound())
					_didWin = true;
				if (_attemps == 0)
					break;
			}
			
		}
	}
};

int main()
{
	Game game;
	game.play();
}