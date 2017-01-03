#include "Game_2048.hpp"
#include "Power_of_2.hpp"
#include "Blank.hpp"

#include <random>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using namespace z;

/* Lire les commentaires dans Game_2048.hpp pour toute information sur
    ses fonctions */

void merge_to_the_left(Grid *grid)
{
    ElementPtr e = ElementPtr(new Blank());
    push_left(*grid, Element_type::BLANK);
    merge_left(*grid, e.get());
    push_left(*grid, Element_type::BLANK);
}

void merge_to_the_right(Grid *grid)
{
    ElementPtr e = ElementPtr(new Blank());
    push_right(*grid, Element_type::BLANK);
    merge_right(*grid, e.get());
    push_right(*grid, Element_type::BLANK);
}

void merge_to_the_up(Grid *grid)
{
    ElementPtr e = ElementPtr(new Blank());
    push_up(*grid, Element_type::BLANK);
    merge_up(*grid, e.get());
    push_up(*grid, Element_type::BLANK);
}

void merge_to_the_down(Grid *grid)
{
    ElementPtr e = ElementPtr(new Blank());
    push_down(*grid, Element_type::BLANK);
    merge_down(*grid, e.get());
    push_down(*grid, Element_type::BLANK);
}

void restart_game(Grid *grid)
{
    ElementPtr e = ElementPtr(new Blank());
    fill_with(*grid, e.get());

    Indice indice = z::random_element(*grid, Element_type::BLANK);
    (*grid)[indice.i][indice.j] = z::ElementPtr(new z::Power_of_2(1));
}

//-------------------------------------------------

void Game_2048::find_max()
{
    int max_1 = 0;

    for (int i = 0; i != m; ++i)
    {
	for (int j = 0; j != n; ++j)
	    if (grid[i][j]->get_type() == Element_type::POWER_OF_2)
	    {
		int temp = stoi(grid[i][j]->printable);
		if (temp > max_1)
		    max_1 = temp;
	    }
    }

    max = max_1;
}

void Game_2048::start_grid()
{
    Indice indice = z::random_element(grid, Element_type::BLANK);
    grid[indice.i][indice.j] = z::ElementPtr(new z::Power_of_2(1));

    indice = z::random_element(grid, Element_type::BLANK);
    grid[indice.i][indice.j] = z::ElementPtr(new z::Power_of_2(1));
}

void Game_2048::display_grid()
{
    system("clear");
    cout << "\n  ::[  THE ORIGINAL GAME ]::\t\t\t\tDeveloped by ZIDANE [-_-]\n\n\t";

    cout << "\t\t\t\t\t\tSCORE::" << score << " \n\n\n\n";

    for (int i = 0; i != m; i++)
    {
	cout << "\t\t     |";

	for (int j = 0; j != n; j++)
	{
	    if (grid[i][j]->get_type() != Element_type::BLANK)
		printf("%4s    |", grid[i][j]->printable.c_str());
	    else
		printf("%4c    |", ' ');
	}

	cout << endl
	     << endl;
    }

    cout << "\n\n Controls (+ :: o)\t\t\t\tu - undo\tr - restart\n\n\tZ\t\t     ^\t\t\th - help\te - exit\n\t\t\t\t\t\t\t\t"

	 << " \n   Q    S    D\t\t<    v    >\t\t\t     ."
	 << " \n\t\t\t\t                             ";
}

void Game_2048::command_press()
{
	char control;

	for(;;) {
		system("stty raw");
		cin >> control;
		system("stty cooked");

		switch (control)
		{
		case 'q':
			command = Cmd(merge_to_the_left, &grid);
			return;
		case 'd':
			command = Cmd(merge_to_the_right, &grid);
			return;
		case 'z':
			command = Cmd(merge_to_the_up, &grid);
			return;
		case 's':
			command = Cmd(merge_to_the_down, &grid);
			return;
		case 'h':
			display_help_screen();
			break;
		case 'e':
			{
				system("clear");
				bool quit = display_yes_no_question(3);
				if (quit)
					exit(0);
				else
					break;	
			}
		case 'r':
			{
				system("clear");
				bool restart = display_yes_no_question(2);
				if (restart) {
					command = Cmd(restart_game, &grid);
					return;	
				}
				else
					break;
			}
		default:
			break;
		}
		system("clear");
		display_grid();
	}
}

void Game_2048::logic_flow()
{
    command();
    find_max();

    if (max >= win)
		game_win = true;
    if (is_blocked())
		game_over = true;
    display_grid();
}

bool Game_2048::is_blocked()
{
    return false;
}

int Game_2048::if_win_or_lose()
{
    if (game_win)
    {
	display_win_screen();
	return display_yes_no_question() ? 1 : 0;
    }

    if (game_over)
    {
	return display_yes_no_question() ? 1 : 0;
    }

    Indice indice = z::random_element(grid, Element_type::BLANK);
    grid[indice.i][indice.j] = z::ElementPtr(new z::Power_of_2(1));

    return 2;
}

void Game_2048::display_win_screen()
{
    system("clear");

    cout << endl
	 << endl;
    cout << "\n\t\t\t  :: [  YOU MADE " << win << "!  ] ::"
	 << "\n\n\t\t\t  :: [ YOU WON THE GAME ] ::"
	 << "\n\n\n\n\t\t\t TILE\t     SCORE\t    NAME";
    printf("\n\n\t\t\t %4d\t    %6d\t    ", max, score);

    cout << "\n\n\t\t> The maximum possible tile is 65,536 ! So go on :)";
}

bool Game_2048::display_yes_no_question(int i)
{
    char answer;

    switch (i)
    {
    case 1:
		cout << "\n\n\n\t    > Would you like to try again (y/n) ? :: ";
		break;
    case 2:
		cout << "\n\n\n\t    > Would you like to restart the game (y/n) ? :: ";
		break;
    case 3:
		cout << "\n\n\n\t    > Would you like to exit the game (y/n) ? :: ";
		break;
    }

    system("stty raw");
    cin >> answer;
    system("stty cooked");

    return (answer == 'y') ? true : false;
}

void Game_2048::display_help_screen()
{
	system("clear");
	
	cout<<endl<<"  ::[  THE 2048 PUZZLE  ]::\t\t\t\tDeveloped by ZIDANE [-_-]";
	
	vector<string> text;
	text.push_back("> The game starts with 1 or 2 randomly placed numbers in a n*m grid (n*m cells).");
	text.push_back("> Use the controls to move the cells. ( Press Z/Q/S/D ).");
	text.push_back("> 2 cells of the same number will merge and add up.");
	text.push_back("> New 2s and 4s will appear randomly on an empty cell with each move you make.");
	text.push_back("> Your objective is to make 2048 in a cell without getting stuck!");
	text.push_back("> Press Key to continue...");

	for(int i=0; i!=text.size() ; i++)
	{
	    if(text[i][0]=='>')
	    {
	    cout<<"\n\n\n";
	    }
    
	    cout<<text[i];
	}
	system("stty raw");
	cin.get();
	system("stty cooked");
}