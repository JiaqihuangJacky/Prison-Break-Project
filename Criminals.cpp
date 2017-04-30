/*
FUNCS DEVELOPED BY CHENGLIN LU
*/
#include"Criminals.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

string getID(Prisoner* p) {
	return p->getId();
}
string getID(Wantedperson* p) {
	return p->getId();
}
string getID(Prisoner p) {
	return p.getId();
}
string getID(Wantedperson p) {
	return p.getId();
}
string getName(Prisoner* p) {
	return p->getName();
}
string getName(Wantedperson* p) {
	return p->getName();
}
string getName(Prisoner p) {
	return p.getName();
}
string getName(Wantedperson p) {
	return p.getName();
}
void WantedpersonDisplayer(Wantedperson &a, bool FullProperties) {

	cout << "NAME : " << a.getName() << ", ";
	cout << "ID : " << a.getId() << ", ";
	cout << "DOB : " << a.getDob() << ", ";
	cout << "GENDER : " << a.getGender() << ", " << endl;

	if (FullProperties) {
		cout << "NATION : " << a.getNation() << ", ";
		cout << "CC : " << a.getCrimeCategories() << ", ";
		cout << "TEMPER : " << a.getTemper() << ", ";
		cout << "BOUNTY : " << a.getBounty() << ", " << endl;
	}

	cout << endl;
}

void PrisonerDisplayer(Prisoner &a) {
	
	cout << "|" << setw(46) << right << setfill('-') << "|";
	cout << setw(16) << right << setfill('-') << "|";

	cout << "\n| " << setw(44) << setfill(' ') << left << a.getName() << "|";
	cout << " " << setw(14) << left << a.getId() << right << "|" << endl;
}

void PrisonerDisplayer_nameOnly(Prisoner &a) {
	cout << a.getName() << endl;
}


void PrisonerDisplayer(Prisoner &a, bool FullProperties) {

	//cout << "|Prisoner : \n";
	cout << "| NAME: " << a.getName() << "\n";
	cout << "| ID: " << a.getId() << "\n";
	cout << "| DOB: " << a.getDob() << "\n";
	cout << "| GENDER: " << a.getGender() << "\n";

	if (FullProperties) {
		cout << "| NATION : " << a.getNation() << "\n";
		cout << "| CC : " << a.getCrimeCategories() << "\n";
		cout << "| TEMPER : " << a.getTemper() << "\n";
		cout << "| BOUNTY : " << a.getBounty() << "\n";
		cout << "| MOOD : " << a.getMood() << "\n";
		cout << "| BRAVERY : " << a.getBravery() << "\n";
		cout << "| DANGERLEVEL : " << a.getDangerLevel() << "\n";
		cout << "| CARRAYITEM : " << a.getCarryItem() << "\n";
	}
	cout << endl;
}

int PrisonerNameCompare(Prisoner *a, Prisoner *b) {
	string temp = "";
	if (a && b) {
		for (int i = 0;i < a->getName().length();i++) {
			temp += b->getName()[i];
		}
		if (a->getName() == temp) return 0;
		else if (a->getName() > temp) return 1;
		else if (a->getName() < temp) return -1;
	}
	return 10;
}