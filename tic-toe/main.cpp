#include <iostream>
#include<cstdlib>
using namespace std;

void playerchoose(string&,string&,char&,char&);
void board(char square[],char,char);
bool checkWin(char[]);
//bool checkchoice(char,char[],char);

int main(){
	string player1,player2;
	int i = 0;
	int choice;
	char plmark1,plmark2;
	char square[10]={'0','1','2','3','4','5','6','7','8','9'};
	char choiceChar[10]={'0','1','2','3','4','5','6','7','8','9'};
	bool win = false;
	playerchoose(player1,player2,plmark1,plmark2);
	do{
		board(square,plmark1,plmark2);


			if(i%2 == 0)
			{
				cout << player1 << " Choose: "; cin >>choice;
				if(square[choice]!=choiceChar[choice])
				{
					cout << "Invalid Move\n";
					cin.get();
				}
				else{
					square[choice] = plmark1;
				}

			}
			else
			{
				cout << player2 << " Choose: "; cin >> choice;
				if(square[choice]!= choiceChar[choice])
				{
					cout << "Invalid Move\n";
					cin.get();
				}
				else{
					square[choice] = plmark2;
				}

			}

			win = checkWin(square);

		i++;
	}while(!win);
	board(square,plmark1,plmark2);

	//board(square);
}


void playerchoose(string &ply1, string &ply2, char& mark1, char& mark2){
	cout << "======Enter name====\n";
	cout << "Player one: "; cin >> ply1;
	cout << "Player two: "; cin >> ply2;
	cout << "====================\n";

	int rand_toast = rand();
	if(rand_toast % 2 == 0)
	{
		mark1 = 'X'; mark2 = 'O';
		cout << ply1 << " = X \n";
		cout << ply2 << " = O \n";
	}
	else
	{
		mark1 = 'O'; mark2 = 'X';
		cout << ply1 << " = O \n";
		cout << ply2 << " = X \n";
	}


}


void board(char square[], char mark1, char mark2){
	system("clear");
	cout << "------- Tic Tac Toe ---------\n";
	//cout << "      |          |      \n";
	cout << "  " << square[1] << "   |    " << square[2] << "     |    " << square[3] << endl;
	cout << "------|----------|----------\n";
	cout << "  " << square[4] << "   |    " << square[5] << "     |    " << square[6] << endl;
	cout << "------|----------|-----------\n";
	cout << "  " << square[7] << "   |    " << square[8] << "     |    " << square[9] << endl;
	cout << "------|----------|-----------\n";
	cout << "player1 = " << mark1 << endl;
	cout << "player2 = " << mark2 << endl;

}

bool checkWin(char square[])
{
	bool win = false;
	for(int a = 1; a < 8 ; a+=3)
	{
		if(square[a] == square[a+1] && square[a+1] == square[a+2])
		{
			win = true;break;
		}
	}
	for(int a = 1; a < 4 ; a++)
	{
		if(square[a] == square[a+3] && square[a+3] == square[a+6])
		{
			win = true;break;
		}
	}
	if(square[1] == square[5] && square[5] == square[9])
	{
		win = true;
	}
	else if(square[3] == square[5] && square[5] == square[7])
	{
		win = true;
	}

	int draw = 1;
	for(int draw = 1; draw<10 ;)
	{
			if(square[draw] != static_cast<char>(draw))
			{
				draw++;
			}
			else{
				break;
			}
	}
	if(draw == 9)
	{
		cout << "Draw\n";
		win = true;
	}



	return win;
}
