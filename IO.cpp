#include<iostream>
#include<string>
#include<time.h>  
#include<fstream>
#include <cstdlib>
#include"Criminals.h"
#include"DLinklist.h"
using namespace std;


//=========================================== I\O FUNCTIONs ================================================
//                                                v3.1
//   PUT THIS CPP UNDER YOUR MAIN DIRECTORY, INCLUDE THE HEADER AND USE THESE FUNC DIRECTLY
//   All I\O INTERFACES ARE INCLUDED HERE

bool IO_loadFBI(DLinklist<Wantedperson>* &FBIWanted, string FBIFILENAME);
//   This functions build the FBIWanted list.
//   Argument 1 : the pointer to a DLinklist holds every wantedperson (RETURN USES)
//   Argument 2 : the file name of the FBIWanted list

bool IO_loadDATA(DLinklist<Prisoner*>* &thePrison, string LOADFILENAME);
//   This functions build a prisoner list from the savedfile.
//   Argument 1 : the PTR to a DLinklist holds the PTR of all prisoners (RETURN USES)
//   Argument 2 : the file name of the file to load

bool IO_saveDATA(DLinklist<Prisoner*>* &thePrison, string SAVEFILENAME);
//   This function saves a file of the prisoner list
//   Argument 1 : the PTR to a DLinklist holds the PTR of all prisoners in the jail
//   Argument 2 : the file name needs to be written

bool IO_checkDATA(string SAVEFILENAME);
//   This function checks is a file is occupied save file
//   Argument 1 : The filename needs to be check

bool IO_getPrisoner(Prisoner* &returnPrisoner, DLinklist<Wantedperson>* wantedList);
//   This function get a random wanted man from the wanted list, and create it as a prisoner
//   Argument 1 : the address of a prisoner just created
//   Argument 2 : the ptr to the wantedlist holds every wanted man
//   WARNING : Random pick from the wantedlist could DUPLICATE, caller needs to check if duplicates.

bool IO_criminalTokenize(string lineInput, string* &wordsOutput, int &size);
//   This function separates a criminal line to string array
//   This is a sub function, you don't need to use it
//   Argument 1 : the source line like this "jack, 01022014, true,"
//   Argument 2 : the string array : [0] = "jack", [1] = "01022014", [2] = "true"
//   Argument 3 : the size of the string array, which is 3 in this case.

//==========================================================================================================






//======================================== CORE I\O FUNCTIONS ==============================================

//-------------------------------------------------------------------------------
bool IO_loadFBI(DLinklist<Wantedperson>* &FBIWanted, string FBIFILENAME) {
	//CLEAN
	if (FBIWanted) delete FBIWanted;

	//MAIN VARS
	FBIWanted = new DLinklist<Wantedperson>;
	Wantedperson newWanted;
	ifstream reader(FBIFILENAME.c_str());
	string temp;

	//INIT RAND
	srand((int)time(NULL));

	//IF FILE OPENED
	if (reader) {

		//READ LINES UNTILL END
		while (reader) {

			int wordsCount;
			string* wordsArray = NULL;
			string sourceString;

			getline(reader, sourceString);

			IO_criminalTokenize(sourceString, wordsArray, wordsCount);
			if (wordsCount == 8) {

				//1-4
				//READ NAME
				newWanted.setName(wordsArray[0]);

				//READ DOB
				newWanted.setDob(wordsArray[1]);

				//READ GENDER
				newWanted.setGender(wordsArray[2]);

				//READ NATION
				newWanted.setNation(wordsArray[3]);

				//6-8
				//READ ID
				newWanted.setId(wordsArray[4]);

				//READ CrimeCategories
				newWanted.setCrimeCategories(wordsArray[5]);

				//READ TEMPER
				newWanted.setTemper(wordsArray[6]);

				//READ BOUNTY
				newWanted.setBounty(wordsArray[7]);

				//INSERTION
				FBIWanted->add(newWanted);
			}
		}
		reader.close();
		return true;
	}

	//IF OPEN FAILURE
	else {
		cout << "IO_loadFBI :: REQUIRED FILE : " << FBIFILENAME << " NOT FOUND!\n";
		return false;
	}
}


//-------------------------------------------------------------------------------
bool IO_loadDATA(DLinklist<Prisoner*>* &thePrison, string LOADFILENAME) {
	//CLEAN
	if (thePrison) delete thePrison;

	//MAIN VARS
	thePrison = new DLinklist<Prisoner*>;
	ifstream reader(LOADFILENAME.c_str());
	string temp;


	//IF FILE OPENED
	if (reader) {

		//READ LINES UNTILL END
		while (reader) {

			Prisoner* newPrisoner = NULL;
			int wordsCount;
			string* wordsArray = NULL;
			string sourceString;


			getline(reader, sourceString);
			IO_criminalTokenize(sourceString, wordsArray, wordsCount);
			if (wordsCount == 12) {

				newPrisoner = new Prisoner;

				//1-4
				//READ NAME
				newPrisoner->setName(wordsArray[0]);

				//READ DOB
				newPrisoner->setDob(wordsArray[1]);

				//READ GENDER
				newPrisoner->setGender(wordsArray[2]);

				//READ NATION
				newPrisoner->setNation(wordsArray[3]);

				//6-8
				//READ ID
				newPrisoner->setId(wordsArray[4]);

				//READ CrimeCategories
				newPrisoner->setCrimeCategories(wordsArray[5]);

				//READ TEMPER
				newPrisoner->setTemper(wordsArray[6]);

				//READ BOUNTY
				newPrisoner->setBounty(wordsArray[7]);

				//8-12
				//READ MOOD
				newPrisoner->setMood(wordsArray[8]);

				//READ BRAVERY
				newPrisoner->setBravery(wordsArray[9]);

				//READ DANGER LEVEL
				newPrisoner->setDangerLevel(wordsArray[10]);

				//READ CARRY ITEM
				newPrisoner->setCarryItem(wordsArray[11]);

				//INSERTION
				thePrison->add(newPrisoner);
			}
		}
		reader.close();
		return true;
	}
	//IF OPEN FAILURE
	else {
		//cout << "IO_loadDATA : REQUIRED FILE : " << LOADFILENAME << " NOT FOUND!\n";
		return false;
	}
}

//-------------------------------------------------------------------------------

bool IO_saveDATA(DLinklist<Prisoner*>* &thePrison, string SAVEFILENAME) {

	//MAIN VARS
	string prisonerInfo;
	remove("SAVEFILENAME");
	ofstream writer(SAVEFILENAME.c_str());
	Prisoner* thePrisoner;
	if (writer) {

		for (int i = 1;i <= thePrison->getCount();i++) {
			thePrison->get(i, thePrisoner);

			//NEW LINE
			if (i != 1) writer << endl;

			//SET LINE 1-4
			prisonerInfo += thePrisoner->getName();
			prisonerInfo += ", ";
			prisonerInfo += thePrisoner->getDob();
			prisonerInfo += ", ";
			prisonerInfo += thePrisoner->getGender();
			prisonerInfo += ", ";
			prisonerInfo += thePrisoner->getNation();
			prisonerInfo += ", ";

			//SET LINE 5-8
			prisonerInfo += thePrisoner->getId();
			prisonerInfo += ", ";
			prisonerInfo += thePrisoner->getCrimeCategories();
			prisonerInfo += ", ";
			prisonerInfo += thePrisoner->getTemper();
			prisonerInfo += ", ";
			prisonerInfo += thePrisoner->getBounty();
			prisonerInfo += ", ";

			//SET LINE 9-12
			prisonerInfo += thePrisoner->getMood();
			prisonerInfo += ", ";
			prisonerInfo += thePrisoner->getBravery();
			prisonerInfo += ", ";
			prisonerInfo += thePrisoner->getDangerLevel();
			prisonerInfo += ", ";
			prisonerInfo += thePrisoner->getCarryItem();
			prisonerInfo += ",";

			writer << prisonerInfo;
			prisonerInfo = "";
		}
	}
	else {
		cout << "IO_saveDATA :: FILE " << SAVEFILENAME << " is occupied!\n";
		return false;
	}
}

//-------------------------------------------------------------------------------

bool IO_checkDATA(string SAVEFILENAME) {

	//MAIN VARS
	string sample;
	string* wordsArray;
	int wordsCount;
	ifstream reader(SAVEFILENAME.c_str());
	//CHECK
	if (reader) {
		getline(reader, sample);
		IO_criminalTokenize(sample, wordsArray, wordsCount);
		if (wordsCount == 12) return true;
		else return false;
	}
	else return false;
}

//-------------------------------------------------------------------------------
bool IO_getPrisoner(Prisoner* &returnPrisoner, DLinklist<Wantedperson>* wantedList) {

	//MAIN VARS
	Prisoner* newPrisoner = NULL;
	Wantedperson tempWanted;
	int index, errorMessage;

	//INIT
	index = 1 + rand() % (wantedList->getCount());
	errorMessage = wantedList->get(index, tempWanted);

	//EXAM
	if (errorMessage == 1) {

		newPrisoner = new Prisoner;

		//PERSON PART
		newPrisoner->setName(tempWanted.getName());
		newPrisoner->setDob(tempWanted.getDob());
		newPrisoner->setGender(tempWanted.getGender());
		newPrisoner->setNation(tempWanted.getNation());

		//WANTED PART
		newPrisoner->setId(tempWanted.getId());
		newPrisoner->setCrimeCategories(tempWanted.getCrimeCategories());
		newPrisoner->setTemper(tempWanted.getTemper());
		newPrisoner->setBounty(tempWanted.getBounty());

		//PRISONER PART
		newPrisoner->setMood(to_string(rand() % 10));
		newPrisoner->setBravery(to_string(rand() % 10));
		newPrisoner->setDangerLevel(to_string(rand() % 10));
		newPrisoner->setCarryItem("NOTHING");

		returnPrisoner = newPrisoner;
		return true;
	}
	else if (errorMessage == -1) {
		cout << "IO_getPrisoner :: Empty Wanted List\n";
		return false;
	}
	else if (errorMessage == 0) {
		cout << "IO_getPrisoner :: random function goes out of boundary!\n";
		return false;
	}
}
//========================================== SUB FUNCTIONS ================================================

//LINE TOKENIZER
//Trim spaces at head&tail
//Seperate By ,
//Return string array
bool IO_criminalTokenize(string lineInput, string* &wordsOutput, int &size) {

	//VARS
	size = 0;
	bool LastCharIsWord = false;

	//GET HOW MANY WORDS IN THE LINE
	for (int i = 0;i < lineInput.length(); i++) {

		if (lineInput[i] == ',') {
			LastCharIsWord = false;
		}
		else {
			if (LastCharIsWord == false) {
				size++;
				LastCharIsWord = true;
			}
		}
	}

	//CREATE wordsOutput ARRAY
	if (size) {
		wordsOutput = new string[size];
		//Put things in the array
		char ch;
		string eachWord;
		int wordCount = 0;

		for (int i = 0; i < lineInput.length(); i++) {
			ch = lineInput[i];

			//If meet comma, push in array if word exist
			if (ch == ',') {
				if (eachWord != "") {

					//Trim Spaces of the word
					while (eachWord[0] == ' ') {
						eachWord.erase(0, 1);
					}
					while (eachWord[eachWord.length() - 1] == ' ') {
						eachWord.erase(eachWord.length() - 1, 1);
					}
					if (eachWord != "") {
						//Push in array
						wordsOutput[wordCount] = eachWord;
						wordCount++;
						eachWord = "";
					}
				}
			}
			//Otherthing just add on word
			else {
				eachWord += ch;
			}
		}
		return true;
	}
	else return false;
}