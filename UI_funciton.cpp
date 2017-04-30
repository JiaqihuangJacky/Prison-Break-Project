/*
PROGRAMMERS :

RUNCHEN TAO
WINGKEI HO
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "HashTable.h"
#include "DLinklist.h"
#include "Criminals.h"
#include "Prison.h"
#include "IO.h"
#include "UI.h"
#include "UI_function.h"
#include "UI_display.h"
using namespace std;

const string SAVE_FILE = "SAVEDATA";
const string EMPTY = "<EMPTY>";
const int NUM_SLOT = 6;

/////////////////////////////////////////////////////////////////////
//UI_operation_manage definition
//void UI_operation_manage(DLinklist<Wantedperson>* &FBIWanted, string FBIFILENAME) {	//(FBIwanted, thePrison)
void UI_operation_manage(Prison* &main_prison, DLinklist<Wantedperson>* &FBIWanted) {	//(FBIwanted, thePrison)
	
	bool flag = true;
	do {
		manage_display();

		string user_option;
		//cin >> user_option;
		user_option.clear();
		getline(cin, user_option);

		int tempInt = stoi(user_option.c_str());

		switch (tempInt) {
		case 1:
			manage_add_prisoner(main_prison,FBIWanted);
			break;
		case 2:
			cout << "PURCHASE FULL EXPERIENCE TO UNLOCK THIS FUNCTION\n";
			cout << "JUST KIDDING, FUNCTION NOT YET AVAILABLE\n";
			break;
		case 3:
			manage_delete_prisoner(main_prison);
			break;
		case 4:
			flag = false;
			break;

		default:
			cout << "Please enter the right number \n" << endl;
			break;
		}//end switch
	} while (flag);
}


void UI_operation_GetPrisoners(Prison* thePrison, DLinklist<Wantedperson>* &FBIWanted, int count) {

	//MAIN VARS
	bool isDuplicate = false;
	Prisoner *newPrisoner = NULL, tempPrisoner;

	//MAX COUNT IN THE FBILIST
	if (count > FBIWanted->getCount()) count = FBIWanted->getCount();

	//LOOP TO GET MAN
	for (int i = 0; i < count; i++) {

		
		do {
			//GET A RAND PRISONER AND CHK IF EXSIST
			IO_getPrisoner(newPrisoner, FBIWanted);
			isDuplicate = thePrison->id_Base->searchByKey(getID, newPrisoner, tempPrisoner);
			if (isDuplicate) delete newPrisoner;
		} while (isDuplicate == true);

		
		//INSERT THE NON-DUPLICATE PRISONER
		thePrison->id_Base->insertItem(newPrisoner, getID);
		thePrison->name_Base->insert(newPrisoner, getName);
		thePrison->sortedID_Base->insert(newPrisoner, getID);
		thePrison->prisoner_Base->add(newPrisoner);

		
		/*thePrison->id_Base->displaySortByKey(PrisonerDisplayer);
		cout << thePrison->prisoner_Base->getCount();*/
	}
	/*thePrison->sortedID_Base->inOrder(PrisonerDisplayer);
	cout << thePrison->id_Base->getCount();*/
}


/////////////////////////////////////////////////////////////////////
//UI_operation_search definition
/*
	- Search by prisoner's name, display information to screen.
	- Search by prisoner's ID, display information to screen.
*/
void UI_operation_search(Prison* &main_prison) {

	bool flag = true;

	do {
		manage_search_display();

		string user_option;
		Prisoner returnedC;
		Prisoner *tempC = new Prisoner;
		Prisoner *newPrisoner = new Prisoner;
		string tempStr;

		cout << "- Enter your option: ";
		//cin >> user_option;
		user_option.clear();
		getline(cin, user_option);

		int tempInt = stoi(user_option.c_str());

		switch (tempInt)
		{
		case 1:
			//search by name
		{
			Queue<Prisoner>* tempQ = new Queue<Prisoner>;
			string tempName;
			Prisoner* tempMan = new Prisoner;

			//cin.ignore();
			cout << "- Enter the name you want to search\n";
			getline(cin, tempName);

			tempName = manage_name_toupper(tempName);
			tempMan->setName(tempName);
			//tempQ = prisonBST->getEntries(*tempMan, getName);
			tempQ = main_prison->name_Base->getEntries(*tempMan, getName);

			if (tempQ->isEmpty())
				cout << "- No No No !!" << endl;
			else
			{
				while (!tempQ->isEmpty())
				{
					tempQ->dequeue(*tempMan);
					cout << "\n- Found!" << endl;
					PrisonerDisplayer(*tempMan, true);
					cout << endl;
				}
			
			}

			delete tempQ;
			delete tempMan;
		}
		break;
		case 2:
			//search by ID
		{
			cout << "- Enter the key you want to find: ";

			//cin.ignore();
			getline(cin, tempStr);

			tempC->setId(tempStr);

			if (main_prison->id_Base->searchByKey(getID, tempC, returnedC))
			{
				cout << "\n- Found" << endl;
				PrisonerDisplayer(returnedC,true);
			}
			else
				cout << "\n- No found " << endl;
		}
		break;
		case 3:
			flag = false;
			break;
		}//end switch
	} while (flag);
}


/////////////////////////////////////////////////////////////////////
//UI_operation_display definition
void UI_operation_display(Prison *main_prison) {

	bool flag = true;

	if (main_prison->prisoner_Base->getCount()) {
		do {
			display_display();

			string user_option;
			cout << "- Enter your option: ";

			//cin >> user_option;
			user_option.clear();
			getline(cin, user_option);

			int tempInt = stoi(user_option.c_str());

			switch (tempInt)
			{
			case 1:{
				//Sorted by ID
				//main_prison->id_Base->displaySortByKey(PrisonerDisplayer);
				cout << " " << setw(61) << right << setfill('=') << "=" << endl;
				cout << setw(46) << setfill(' ') << left << "| Prisoner name" << setw(15) << left << "| ID" << " |" << endl;
				
				main_prison->sortedID_Base->inOrder(PrisonerDisplayer);
				
				cout << " " << setw(61) << right << setfill('=') << "=" << endl;
				}
				break;
			case 2:{
				//Sorted by Name
				cout << " " << setw(61) << right << setfill('=') << "=" << endl;
				cout << setw(46) << setfill(' ') << left << "| Prisoner name" << setw(15) << left << "| ID" << " |" << endl;

				main_prison->name_Base->inOrder(PrisonerDisplayer);
				cout << " " << setw(61) << right << setfill('=') << "=" << endl;
			}
				break;
			case 3: {
				//Unsorted order
				cout << " " << setw(61) << right << setfill('=') << "=" << endl;
				cout << setw(46) << setfill(' ') << left << "| Prisoner name" << setw(15) << left << "| ID" << " |" << endl;

				Prisoner* temp;
				for (int i = 1; i <= main_prison->prisoner_Base->getCount(); i++) {
					main_prison->prisoner_Base->get(i, temp);

					if (temp != 0)
						PrisonerDisplayer(*temp);
				}

				cout << " " << setw(61) << right << setfill('=') << "=" << endl;
			}
					break;
			case 4:
				main_prison->name_Base->indented(PrisonerDisplayer_nameOnly);
				break;
			case 5:
				main_prison->id_Base->displayStatistic();
				break;
			case 6:
				flag = false;
				break;

			default:
				cout << "- Please enter the right number \n" << endl;
				break;
			}
		} while (flag);
	}
	else {
		cout << "- EMPTY LIST, CAN NOT DISPLAY\n";
	}
}


/////////////////////////////////////////////////////////////////////
//UI_operation_save definition
void UI_operation_save(Prison* &main_prison) {
	

	slot_display(SAVE_FILE, EMPTY, NUM_SLOT, false);
	
	//Read profile number
	cout << "- Enter the profile number that you want to save: ";
	string profile_Num;
	//cin >> profile_Num;
	getline(cin, profile_Num);
	
	string temp = SAVE_FILE;
	//temp += (profile_Num + 48);
	temp += profile_Num;
	temp += ".prison";

	//Save prison
	if (!IO_saveDATA(main_prison->prisoner_Base, temp)) {
		cout << "Fail to save data.\n";		//We also have a error message in IO_saveDATA funciton, if fail to save.
	}
	else {
		cout << "\n=== Data saved successfully. File name is " << temp << " ===" << endl << endl;
	}
}


//-------------------------------------------------------------------
//UI_operation_manage sub-function definition

/*
	- Display menu
	- Call function to add prisoner from wanted list ramdomly when input is 1.
	- Call funciton to add prisoner by typing when input is 2.
	- No return value/
*/
void manage_add_prisoner(Prison *main_prison, DLinklist<Wantedperson>* FBIWanted) {

	menage_add_prison_display();

	string user_option;
	//cin >> user_option;
	user_option.clear();
	getline(cin, user_option);

	int tempInt = stoi(user_option.c_str());

	switch (tempInt) {
	case 1: {
		//cout << "Call funciton to add prisoner from wanted list" << endl;
		cout << "- Enter the number of prisoner that you want to add: ";
		string population;
		//cin >> population;
		population.clear();
		getline(cin, population);

		int tempInt2 = stoi(population.c_str());

		UI_operation_GetPrisoners(main_prison, FBIWanted, tempInt2);	//95 total number of wanted person

		cout << "\n=== " << "Population of the prison is " << main_prison->prisoner_Base->getCount() << " now ===\n\n";

		}break;
	case 2:
		//cout << "Call function to add prisoner by tying" << endl;
	    userCreate(main_prison);

		cout << "\n=== " << "Population of the prison is " << main_prison->prisoner_Base->getCount() << " now ===\n\n";
		break;

	default:
		cout << "Please enter the right number \n" << endl;
		break;
	}
}


/*
	- Loop to ask user to enter the ID of the prisoner that user want to edit,
	  display the info of the ID that user enter. End loop when user find the 
	  confirm this is the correct prisoner.

	- Loop to edit the info of this prisoner. End loop when user finish editing.
*/
void manage_edit_prisoner() {

	bool flag = true;
	string _id;

	while (flag){
		string tempStr;

		cout << "- Enter thr ID of the prisoner that you want to edit: ";
		//cin.ignore();
		_id.clear();
		getline(cin, _id);

		cout << "Call displayPrisoner(_id);" << endl;
		cout << "- Are you sure you want to edit the information of this prisoner?" << endl;
		cout << "- (y for yes, n for no)" << endl;
		tempStr.clear();
		getline(cin, tempStr);

		if (tempStr == "y" || tempStr == "Y")
			flag = false;
	}

	while (!flag) {
		string tempStr;
		cout << "- What you want to edit?" << endl;
		cout << "Call funciton to do this" << endl;

		cout << "- Finish editing?" << endl;
		cout << "- (y for yes, n for no)" << endl;
		tempStr.clear();
		getline(cin, tempStr);

		if (tempStr == "y" || tempStr == "Y")
			flag = true;
	}
}


/*
	- Ask user for ID of the prisoner that user want to delete.
	- Call funciton to do it.
*/
void manage_delete_prisoner(Prison* &main_prison) {
	string _id;

	Prisoner *tempD = new Prisoner;
	Prisoner *tempC = new Prisoner;
	Prisoner *tempB = new Prisoner;
	Prisoner *tempA = new Prisoner;
	int index;
	bool deletestatus;
	cout << "- Enter the ID of the prisoner that you want to delete: ";
	//cin.ignore();
	getline(cin, _id);

	tempD->setId(_id);
	tempC->setId(_id);
	tempB->setId(_id);
	tempA->setId(_id);


	//deleting from 2 tree one table, list
	deletestatus = main_prison->id_Base->removeItem(getID, tempC);//table
	main_prison->name_Base->remove(*tempB, getID); // 2 tree
	main_prison->sortedID_Base->remove(*tempA, getID);

	

	main_prison->prisoner_Base->compRemove(tempD, getID);

	if (deletestatus)
		cout << "=== Population of prison is "<< main_prison->prisoner_Base->getCount() << " now ===\n" << endl;
	else
		cout << "\n- No found \n" << endl;

}


bool userCreate(Prison* p)
{
	//cin.ignore();
	Prisoner* newPrisoner = new Prisoner;
	string temp;
	Prisoner tempPrisoner;

	if (!newPrisoner)
		return false;

	bool flag = false;
	while (!flag)
	{

		cout << "- Enter ID of prisoner: ";
		temp.clear();
		getline(cin, temp);
		newPrisoner->setId(temp);
		if (p->id_Base->searchByKey(getID, newPrisoner, tempPrisoner))
		{
			cout << "- ID " << temp << " is already occupied." << endl;
			flag = false;
		}
		else flag = true;

	}

	newPrisoner->setId(temp);

	cout << "- Enter name of prisoner: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	temp = manage_name_toupper(temp);
	newPrisoner->setName(temp);

	cout << "- Enter DOB of prisoner: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	newPrisoner->setDob(temp);

	cout << "- Enter nationality of prisoner: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	newPrisoner->setNation(temp);

	cout << "- Enter gender of prisoner: ";
	temp.clear();
	getline(cin, temp);
	newPrisoner->setGender(temp);

	cout << "- Enter Crime of prisoner: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	newPrisoner->setCrimeCategories(temp);

	cout << "- Enter temper of prisoner: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	newPrisoner->setTemper(temp);

	cout << "- Enter bounty given: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	newPrisoner->setBounty(temp);

	cout << "- Enter mood of prisoner: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	newPrisoner->setMood(temp);

	cout << "- Enter bravery of prisoner: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	newPrisoner->setBravery(temp);

	cout << "- Enter danger level of prisoner: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	newPrisoner->setDangerLevel(temp);

	cout << "- Enter carried item of prisoner: ";
	//cin.ignore();
	temp.clear();
	getline(cin, temp);
	newPrisoner->setCarryItem(temp);

	//check

	p->id_Base->insertItem(newPrisoner, getID);
	p->name_Base->insert(newPrisoner, getName);
	p->sortedID_Base->insert(newPrisoner, getID);
	p->prisoner_Base->add(newPrisoner);

	return true;
}


string manage_name_toupper(string src) {
	string up;
	char ch;
	for (int i = 0;i < src.length();i++) {
		ch = src[i];
		if (ch >= 'a' && ch <= 'z') {
			up += (ch - 32);
		}
		else {
			up += ch;
		}
	}
	return up;
}