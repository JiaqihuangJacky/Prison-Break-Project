/*
UI DISIGNER RUNCHEN TAO
ASSISSTANCE : WINGKEI HO
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "DLinklist.h"
#include "Criminals.h"
#include "Prison.h"
#include "IO.h"
#include "UI.h"
#include "UI_function.h"
#include "UI_display.h"
using namespace std;

/////////////////////////////////////////////////////////////////////
//Main function's definition
 /*---------------------------------------------------------
 UI_initialization:
					- Read user's option and load Prison.
					- No return value?
 */
void UI_initialization(const string WANTED_FILE,
					   const string SAVE_FILE,
					   const string EMPTY, 
				       int NUM_SLOT, Prison *main_prison, DLinklist<Wantedperson>* FBIWanted) {
	
	start_display();

	cout << "- Enter your option: ";
	string user_option;
	//cin >> user_option;	//replace cin
	getline(cin, user_option);

	while (	!(user_option == "1" || user_option == "2")	) {
		cout << "Invalid input, please enter 1 or 2.\n";
		user_option.clear();
		//cin.ignore();
		getline(cin, user_option);
		//cin >> user_option;
	}

	if (user_option == "1") {
		//Read initial population
	    cout << "- Enter the initial population of the new prison: ";
		string population;
		//cin >> population;
		//cin.ignore();
		getline(cin, population);

		int tempInt = atoi(population.c_str());
		
		UI_operation_GetPrisoners(main_prison, FBIWanted, tempInt);	//95 total number of wanted person

		cout << "\n=== Prison has been initialized ===\n\n";

	}
	else if(user_option == "2"){
		

		slot_display(SAVE_FILE, EMPTY, NUM_SLOT, true);

		//Read profile number
		cout << "- Enter the profile number that you want to load: ";
		string profile_Num;
		//cin >> profile_Num;
		//cin.ignore();
		getline(cin, profile_Num);

		string temp = SAVE_FILE;
		//temp += (profile_Num + 48);
		temp += profile_Num;
		temp += ".prison";

		//Load prison
		if (IO_loadDATA(main_prison->prisoner_Base, temp)) {
			for (int i = 1; i <= main_prison->prisoner_Base->getCount(); i++) {
				Prisoner* tempPrisoner;

				main_prison->prisoner_Base->get(i, tempPrisoner);
				main_prison->id_Base->insertItem(tempPrisoner, getID);
				main_prison->name_Base->insert(tempPrisoner, getName);
				main_prison->sortedID_Base->insert(tempPrisoner, getID);
			}

			cout << "\n=== Prison has been initialized ===\n\n";
		}
		else {
			//cout << "UI::LOAD PRISON : loadDATA failure\n\n";
			cout << "\n- There is no file to read! Create a prison first.\n\n";
			UI_initialization(WANTED_FILE, SAVE_FILE, EMPTY, NUM_SLOT, main_prison, FBIWanted);
		}
	}

	
	//delete
}

 /*---------------------------------------------------------
	UI_operation:
					- Display opration menu.
					- Read user's option and execute it.
					- No return value.
 */
void UI_operation(const string SAVE_FILE, Prison* &main_prison, DLinklist<Wantedperson>* &FBIWanted) {

	bool flag = true;

	do {
		//Display and read user's option
		operation_display();

		cout << "- Enter your option: ";
		string user_option;
		//cin >> user_option;	//replace cin
		//cin.ignore();
		getline(cin, user_option);

		//Validation		
		while (!(user_option == "1" || user_option == "2" || user_option == "3" ||
			user_option == "4" || user_option == "5" || user_option == "6")) {
			cout << "Invalid input, please enter a number between 1 and 5.\n";
			//cin >> user_option;
			user_option.clear();
			//cin.ignore();
			getline(cin, user_option);
		}

		//Execute user's option

		int tempInt = atoi(user_option.c_str());

		switch (tempInt) {
		case 1 :
			UI_operation_manage(main_prison, FBIWanted); //perameter is (FBIWanted, thePrison) 
			break;
		case 2:
			UI_operation_search(main_prison);
			break;
		case 3:
			UI_operation_display(main_prison);
			break;
		case 4:
			UI_operation_save(main_prison);
			break;
		case 5:
			developer_Info();
			break;
		case 6:
			flag = false;
			break;
		}//end switch
	} while (flag);

}

 /*---------------------------------------------------------

 */
void UI_quit(const string SAVE_FILE, Prison* &main_prison) {

	IO_saveDATA(main_prison->prisoner_Base, SAVE_FILE + "0.prison");
	
	for (int i = 1; i <= main_prison->prisoner_Base->getCount(); i++) {
		Prisoner* temp;
		main_prison->prisoner_Base->get(i, temp);
		delete temp;
	}

	delete main_prison->id_Base;
	delete main_prison->name_Base;
	delete main_prison->prisoner_Base;
	delete main_prison->sortedID_Base;
	delete main_prison;
}//end UI_quit---------------------------------------------


