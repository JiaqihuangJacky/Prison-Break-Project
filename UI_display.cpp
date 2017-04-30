#include <iostream>
#include <iomanip>
#include <string>
#include "IO.h"
#include "UI.h"
#include "UI_function.h"
#include "UI_display.h"
using namespace std;

void start_display() {
	cout << " " << setw(60) << setfill('-') << "-" << endl;
	cout << "|" << setw(32) << setfill(' ') << "PRESS" << setw(28) << setfill(' ') << "|" << endl;
	cout << "|" << setw(60) << setfill(' ') << "|" << endl;
	cout << "|" << setw(40) << setfill(' ') << "1 - Create a new prison" << setw(20) << setfill(' ') << "|" << endl;
	cout << "|" << setw(60) << setfill(' ') << "|" << endl;
	cout << "|" << setw(34) << setfill(' ') << "2 - Load a prison" << setw(26) << setfill(' ') << "|" << endl;
	cout << "|" << setw(60) << setfill(' ') << "|" << endl;
	cout << " " << setw(60) << setfill('-') << "-" << endl;
}

void operation_display() {
	cout << setw(60) << setfill('-') << "-" << endl;
	cout << setw(32) << setfill(' ') << "PRESS" << setw(28) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(43) << setfill(' ') << "1 - Manage prison (Add, Edit, Delete)" << setw(17) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(39) << setfill(' ') << "2 - Search prison (By name or ID)" << setw(21) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(56) << setfill(' ') << "3 - Display prison info (And hash table statistic)" << setw(4) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(27) << setfill(' ') << "4 - Save current data" << setw(33) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(18) << setfill(' ') << "5 - About us" << setw(42) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(28) << setfill(' ') << "6 - Quit manage system" << setw(32) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill('-') << "-" << endl;
}

void manage_display() {
	cout << setw(60) << setfill('-') << "-" << endl;
	cout << setw(32) << setfill(' ') << "PRESS" << setw(28) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(22) << setfill(' ') << "1 - Add prisoner" << setw(38) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(33) << setfill(' ') << "2 - Edit prisoner (Disable)" << setw(27) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(25) << setfill(' ') << "3 - Delete prisoner" << setw(35) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(14) << setfill(' ') << "4 - Back" << setw(46) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill('-') << "-" << endl;
	cout << "- Enter your option: ";
}


//-------------------------------------------------------------------
//UI_operation_search sub-function definition
/*
------------------------------------------------------------
PRESS                           |
|
1 - Search by prisoner's name                        |
|
2 - Search by prisoner's ID                          |
|
------------------------------------------------------------
*/
void manage_search_display() {

	cout << setw(60) << setfill('-') << "-" << endl;
	cout << setw(32) << setfill(' ') << "PRESS" << setw(28) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(35) << setfill(' ') << "1 - Search by prisoner's name" << setw(25) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(33) << setfill(' ') << "2 - Search by prisoner's ID" << setw(27) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(14) << setfill(' ') << "3 - Back" << setw(46) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill('-') << "-" << endl;
}


//-------------------------------------------------------------------
//UI_operation_display sub-function definition
/*
------------------------------------------------------------
PRESS                           |
|
1 - Display all prisoners sorted by ID               |
|
2 - Display all prisoners sorted by name             |
|
3 - Display all prisoners in unsorted order          |
|
4 - Display the indented list                        |
|
5 - Display the statistic of the prison              |
|
------------------------------------------------------------
*/
void display_display() {

	cout << setw(60) << setfill('-') << "-" << endl;
	cout << setw(32) << setfill(' ') << "PRESS" << setw(28) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(44) << setfill(' ') << "1 - Display all prisoners sorted by ID" << setw(16) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(46) << setfill(' ') << "2 - Display all prisoners sorted by name" << setw(14) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(49) << setfill(' ') << "3 - Display all prisoners in unsorted order" << setw(11) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(35) << setfill(' ') << "4 - Display the indented list" << setw(25) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(38) << setfill(' ') << "5 - Display hash table statistic" << setw(22) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(14) << setfill(' ') << "6 - Back" << setw(46) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill('-') << "-" << endl;
}


/*
------------------------------------------------------------
PRESS                           |
|
1 - Add prisoner from wanted list randomly		   |
|
2 - Add prisoner by typing prisoner's info manually  |
|
------------------------------------------------------------
*/
void menage_add_prison_display() {
	cout << setw(60) << setfill('-') << "-" << endl;
	cout << setw(32) << setfill(' ') << "PRESS" << setw(28) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(48) << setfill(' ') << "1 - Add prisoner from wanted list randomly" << setw(12) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(57) << setfill(' ') << "2 - Add prisoner by typing prisoner's info manually" << setw(3) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill(' ') << "|" << endl;
	cout << setw(60) << setfill('-') << "-" << endl;
	cout << "- Enter your option: ";
}

/*
- Current slot:
-------------------
| DEFAULT 0         |
| SLOT    1         |
| SLOT    2 <EMPTY> |
| SLOT    3 <EMPTY> |
| SLOT    4 <EMPTY> |
| SLOT    5 <EMPTY> |
-------------------
*/
void slot_display(const string SAVE_FILE, const string EMPTY, const int NUM_SLOT, bool showDefault) {

	bool* tempArr = new bool[NUM_SLOT];
	//Total number of 6 slots

	for (int i = 0; i < NUM_SLOT; i++) {
		string temp = SAVE_FILE;
		temp += (i + 48);
		temp += ".prison";
		tempArr[i] = IO_checkDATA(temp);
		temp.clear();
	}

	cout << "\n- Current slot: " << endl;
	cout << "  -------------------" << endl;

	if (showDefault) {
		if (tempArr[0] == 1)
			cout << " | DEFAULT 0 " << "        |" << endl;
		else
			cout << " | DEFAULT 0 " << EMPTY << " |" << endl;
	}
	for (int i = 1; i < NUM_SLOT; i++) {
			if (tempArr[i] == 1)
				cout << " | SLOT    " << i << "         |" << endl;
			else
				cout << " | SLOT    " << i << " " << EMPTY << " |" << endl;
	}
	cout << "  -------------------" << endl;

	delete[] tempArr;
}

void developer_Info() {
	cout << endl;
	cout << endl;
	displayLogo();
	cout << endl;
	cout << endl;
	cout << setw(15) << left << setfill('~') << " ";
	cout << " Developers information";
	cout << setw(15) << left << setfill('~') << " ";

	cout << "\n|" << setw(52) << setfill(' ') << " " << "|";
	
	cout << "\n|" << setw(5) << setfill(' ') << " ";
	cout << setw(45) << left <<  "Chenglin Lu - niko7ultra@gmail.com";
	cout << setw(3) << right << "|";

	cout << "\n|" << setw(52) << setfill(' ') << " " << "|";

	cout << "\n|" << setw(5) << setfill(' ') << " ";
	cout << setw(45) << left << "Jiaqi Huang - huangjiaqi2397056Hjq@gmail.com";
	cout << setw(3) << right << "|";

	cout << "\n|" << setw(52) << setfill(' ') << " " << "|";

	cout << "\n|" << setw(5) << setfill(' ') << " ";
	cout << setw(45) << left << "Jun Li      - junli.julie@gmail.com";
	cout << setw(3) << right << "|";

	cout << "\n|" << setw(52) << setfill(' ') << " " << "|";

	cout << "\n|" << setw(5) << setfill(' ') << " ";
	cout << setw(45) << left << "Runchen Tao - taorunchen@gmail.com";
	cout << setw(3) << right << "|";

	cout << "\n|" << setw(52) << setfill(' ') << " " << "|";

	cout << "\n|" << setw(5) << setfill(' ') << " ";
	cout << setw(45) << left << "Wing Kei Ho - hilaaryy@gmail.com";
	cout << setw(3) << right << "|";

	cout << "\n|" << setw(52) << setfill(' ') << " " << "|";
	
	cout << endl;
	cout << " " << setw(53) << right << setfill('~') << " ";
	cout << endl;
	cout << endl;
}

void displayLogo() {
	cout << "                                                             \n";
	cout << "     ######   ######   ######   ######   ######   ##  ##     \n";
	cout << "     ##   #   ##    #    ##     ##       #    #   ### ##     \n";
	cout << "     ######   ######     ##     ######   #    #   ## ###     \n";
	cout << "     ##       ##  ##     ##         ##   #    #   ##  ##     \n";
	cout << "     ##       ##   ##  ######   ######   ######   ##  ##     \n";
	cout << "                                                             \n";
	cout << "              ####   ####   #####  #####  #   #            \n";
	cout << "              #   #  #   #  #      #   #  #  #             \n";
	cout << "              ####   ####   #####  #####  # #              \n";
	cout << "              #   #  #  #   #      #   #  ## #             \n";
	cout << "              ####   #   #  #####  #   #  #   #            \n";
	cout << "                                                             \n";
	cout << "                                                             \n";
}