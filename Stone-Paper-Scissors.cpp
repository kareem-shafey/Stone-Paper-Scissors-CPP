#include <iostream>
#include <time.h> 
using namespace std;

enum enChooseNumber { Stone = 1, Paper = 2, Scissors = 3 };

int ReadNumber()
{
	int number;
	cout << "\nHow Many Round 1 to 10 ? \n";
	cin >> number;
	return number;
}

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

enChooseNumber ReadRandomNumberToComputer()
{
	return (enChooseNumber)(RandomNumber(1, 3));

}

enChooseNumber ReadNumberInEnum(int Number)
{
	if (Number == 1)
		return enChooseNumber::Stone;
	else if (Number == 2)
		return enChooseNumber::Paper;
	else
		return enChooseNumber::Scissors;
}


string CheckNumber(int Number)
{
	if (ReadNumberInEnum(Number) == enChooseNumber::Stone)
		return "Stone";
	else if (ReadNumberInEnum(Number) == enChooseNumber::Paper)
		return "Paper";
	else if (ReadNumberInEnum(Number) == enChooseNumber::Scissors)
		return "Scissors";
	return 0;
}



void ManyRounds()
{
	bool Return = true;
	char Reuse = 'u';
	while (Return)
	{
		int Number = ReadNumber();

		int Player = 0, itsComputer = 0, Equal = 0;
		int P = 0, C = 0;


		for (int i = 0; i < Number; i++)
		{
			cout << "\nRound [" << i + 1 << "] begins:\n\n";
			cout << "Your Choise [1]:Stone, [2]:Paper, [3]:Scissors ? ";
			int User = 0;
			cin >> User;
			cout << endl;

			enChooseNumber ComputerNumber = ReadRandomNumberToComputer();

			if ((CheckNumber(User) == "Stone") && (CheckNumber(ComputerNumber) == "Scissors") || (CheckNumber(User) == "Scissors") && (CheckNumber(ComputerNumber) == "Paper") || (CheckNumber(User) == "Paper") && (CheckNumber(ComputerNumber) == "Stone"))
			{
				system("color 2F");
				Player++;
				P++;
			}
			else if ((CheckNumber(User) == "Paper") && (CheckNumber(ComputerNumber) == "Scissors") || (CheckNumber(User) == "Stone") && (CheckNumber(ComputerNumber) == "Paper") || (CheckNumber(User) == "Scissors") && (CheckNumber(ComputerNumber) == "Stone"))
			{
				system("color 4F");
				itsComputer++;
				C++;
			}
			else if ((CheckNumber(User) == "Stone") && (CheckNumber(ComputerNumber) == "Stone") || (CheckNumber(User) == "Paper") && (CheckNumber(ComputerNumber) == "Paper") || (CheckNumber(User) == "Scissors") && (CheckNumber(ComputerNumber) == "Scissors"))
			{
				system("color 6F");
				Equal++;
			}

			cout << "_______________Round [" << i + 1 << "] ________________\n\n";
			cout << "Player1  Choise: " << CheckNumber(User) << endl;;
			cout << "Computer Choice: " << CheckNumber(ComputerNumber) << endl;


			if (P > C)
			{
				cout << "Round Winner   : [Player]\n";
				P = 0;
			}

			else if (C > P)
			{
				cout << "Round Winner   : [Computer]\n";
				C = 0;
			}
			else
			{
				cout << "Round Winner   : [No Winner]\n";
			}

			cout << "\n-----------------------------------------\n";
		}

		cout << "\n\t______________________________________________________\n\n";
		cout << "\t\t\t++ G a m e O v e r +++\t\t";
		cout << "\n\t______________________________________________________\n\n";
		cout << "\t________________ [Game Results]_______________________\n";
		cout << "\tGame Round         : " << Number << "\n";
		cout << "\tPalayer1 Won Times : " << Player << "\n";
		cout << "\tComputer Won Times : " << itsComputer << "\n";
		cout << "\tDraw Times         : " << Equal << "\n";
		if (Player > itsComputer)
			cout << "\tFinal Winner       : Player\n";
		else if (itsComputer > Player)
			cout << "\tFinal Winner       : Computer\n";
		else
			cout << "\tFinal Winner       : No Winner\n";

		cout << "\t______________________________________________________\n";

		cout << "\tDo you want to play again ? Y / N ? ";
		cin >> Reuse;

		if (Reuse == 'Y' || Reuse == 'y')
		{
			Return = true;
			system("cls");
			system("color 0F");
		}
		else
			Return = false;
	}


}



int main()
{
	srand((unsigned)time(NULL));

	ManyRounds();
	return 0;
}
