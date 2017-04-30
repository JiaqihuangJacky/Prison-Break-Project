/*
MADE BY UI DESIGNER RUNCHEN TAO
*/

//Basic Sturctures
#include"Queue.h"
#include"Stack.h"
#include"DLinklist.h"
//ADV Stuctures
#include"HashTable.h"
#include"BinarySearchTree.h"
//Basic Elemetns
#include"Criminals.h"
#include"Prison.h"
//Function Prototypes
#include "IO.h"
#include "UI.h"
#include "UI_function.h"
#include "UI_display.h"


using namespace std;

//Const

const string WANTED_FILE = "FBI.LIST";
const string SAVE_FILE = "SAVEDATA";
const string EMPTY = "<EMPTY>";
const int NUM_SLOT = 6;


int main() {
	
	//FBIWanted List
	DLinklist<Wantedperson>* FBIWanted = new DLinklist<Wantedperson>;

	//PRISON
	Prison *main_prison = new Prison;

	main_prison->id_Base = new HashTable<Prisoner>;
	main_prison->name_Base = new BinarySearchTree<Prisoner>;
	main_prison->sortedID_Base = new BinarySearchTree<Prisoner>;
	main_prison->prisoner_Base = new DLinklist<Prisoner*>;

	displayLogo();

	//LOAD FBILIST
	if (IO_loadFBI(FBIWanted, WANTED_FILE)) {

		//CALL
		UI_initialization(WANTED_FILE, SAVE_FILE, EMPTY, NUM_SLOT, main_prison, FBIWanted);

		UI_operation(SAVE_FILE, main_prison, FBIWanted);

		UI_quit(SAVE_FILE, main_prison);
	}else{
		cout << "MAIN:: LOAD FBI LIST FAILURE\n";
	}

	//system("pause");
	return 0;
}