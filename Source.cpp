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
			for (int i = 0; i < rand() % 466427; i++)
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
};


class Interface
{
public:
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
};
class Game
{
private:
	Interface _gameInterface;
	int _attemps;
public:
	Game()
	{
		_attemps = 0;
	}
	void playerTurn(GameWord word)
	{
		
	}
	void play()
	{
		srand(time(0));
		while (true)
		{
			GameWord word;
			playerTurn(word);
			if (!_attemps)
			{

			}
		}
	}
};

int main()
{
	
	string _word;
	ifstream file{ "words.txt" };
	int randomLine = rand() % 466427; //counting amount of the lines is taking too much time
	cout << "Line: " << randomLine << "\n";
	while (file.is_open())
	{
		for (int i = 0; i < rand() % 466427; i++)
		{
			getline(file, _word);
		}
		break;
	}
	file.close();
	cout << "Word: " << _word << "\n";
}