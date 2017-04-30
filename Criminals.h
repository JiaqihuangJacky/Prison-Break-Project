// VERSION 2.5
/*
CREATED BY JAIQI HUANG
FUNC DEVELOPS BY CHENGLIN LU
*/
#ifndef dataFile_Criminals_h
#define dataFile_Criminals_h

#include <string>
using namespace std;

class Person // superclass
{
    // protected valuable: allow derived class to use it
protected:
    string name; //name of person
    string dob; // name of person
    string gender; // gender of person
    string nationality;// countries type
    
    
public:
    
    //Person(string _name, string _age, string _gender, string _nationality);//default wiht parameters
	Person()
	{
		name = "No Name";
		dob = "";
		gender = "No gender";
		nationality = "No nationality";

	}
    
			 //Mutator
    void setName(string _name) { name = _name; }
    
    void setDob(string _dob) { dob = _dob; }
    
    void setGender(string _gender) { gender = _gender; }
    
    void setNation(string _nationality) { nationality = _nationality; }
    
    //accessor
    string getName() const { return name; }
    string getDob() const { return dob; }
    string getGender() const { return gender; }
    string getNation() const { return nationality; }
    
};

//----------------------------------- end of Class person--------------------------------

//==================================================
// Derived class: Wantedperson
//==================================================
class Wantedperson : public Person
{
private:
    string id;			// id of wantedPerson
    string crimeCategories;// the even which the person commite crime
    string temper; // The wanted person's temper scale 1 - 10
    string bounty; // The bounty that the FBL provided
    
public:
	Wantedperson() {
		id = "";
		crimeCategories = "No crime";
		temper = "";
		bounty = "";
	}
    
    //Mutator
    void setId(string _id) { id = _id; }
    void setCrimeCategories(string _crimeCategories) { crimeCategories = _crimeCategories; }
    void setTemper(string _temper) { temper = _temper; }
    void setBounty(string _bounty) { bounty = _bounty; }
    
    //Accessor
    string getId() const { return id; }
    string getCrimeCategories() const { return crimeCategories; }
    string getTemper() const { return temper; }
    string getBounty() const { return bounty; }
    
};


//-------------------- end of class Wantedperson-------------------------------

//==================================================
// Derived class: Prisoner
//==================================================

class Prisoner : public Wantedperson
{
private:
    string mood; // mood of prisoner
    string bravery;// the bravery of prisoner
    string dangerLevel; // the dangerlevel of this prisoner
    string carryItem; // the items that the prisoner has
    
public:
    
    // default
    Prisoner() {
		mood = "";
		bravery = "";
		dangerLevel = "";
		carryItem = "NOTHING";
	}
    //Prisoner(int _mood, int _bravery, int _dangerLevel, string _carryItem);
    
    //Mutator
    void setMood(string _mood) { mood = _mood; }
    void setBravery(string _bravery) { bravery = _bravery; }
    void setDangerLevel(string _dangerLevel) { dangerLevel = _dangerLevel; }
    void setCarryItem(string _carryItem) { carryItem = _carryItem; }
    
    //Accessor
    string getMood() const { return mood; }
    string getBravery() const { return bravery; }
    string getDangerLevel() const { return dangerLevel; }
    string getCarryItem() const { return carryItem; }
    
};

string getID(Prisoner* p);
string getID(Wantedperson* p);
string getName(Prisoner* p);
string getName(Wantedperson* p);
void WantedpersonDisplayer(Wantedperson &a, bool FullProperties);
void PrisonerDisplayer(Prisoner &a);
void PrisonerDisplayer(Prisoner &a, bool FullProperties);
void PrisonerDisplayer_nameOnly(Prisoner &a);
int PrisonerNameCompare(Prisoner *a, Prisoner *b);
#endif