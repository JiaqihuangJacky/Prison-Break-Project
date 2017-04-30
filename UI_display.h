#ifndef DISPLAY_FUNC
#define DISPLAY_FUNC

//=========================================================
//UI_initialization Menu
/*
------------------------------------------------------------
						 PRESS                             |
														   |
			 1 - Create a new prison					   |
														   |
			 2 - Load a prison							   |
														   |
------------------------------------------------------------
*/
void start_display();


//===================================================================
//UI_operation Menu 
/*
------------------------------------------------------------
						PRESS							   |
	|
			1 - Manage prison (Add, Edit, delete)		   |
|
	        2 - Search the prison (By name. By ID)         |
|
			3 - Display the prison						   |
|
			4 - Save profile                               |
|
			5 - Quit manage system                         |
|
------------------------------------------------------------
*/
void operation_display();

//===================================================================
//UI_operation_manage Menu
/*
------------------------------------------------------------
PRESS                           |
|
1 - Add prisoner								|
|
2 - Edit prioner								|
|
3 - Delete prisoner								|
|
------------------------------------------------------------
*/
void manage_display();

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
void manage_search_display();

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
void display_display();

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
void menage_add_prison_display();
//===================================================================
//UI_operation_manage 

void slot_display(const string SAVE_FILE, const string EMPTY, const int NUM_SLOT, bool showDefault);

void developer_Info();

void displayLogo();
#endif 
