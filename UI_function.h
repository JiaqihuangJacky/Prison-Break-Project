#ifndef UI_FUNCTION_H
#define UI_FUNCTION_H

#include<iostream>
#include<string>
#include"Prison.h"
using namespace std;

void UI_operation_manage(Prison* &main_prison, DLinklist<Wantedperson>*&FBIWanted);
void UI_operation_GetPrisoners(Prison* thePrison, DLinklist<Wantedperson>* &FBIWanted, int count);
void UI_operation_search(Prison* &main_prison);
void UI_operation_display(Prison *main_prison);
void UI_operation_save(Prison* &main_prison);
void manage_add_prisoner(Prison *main_prison, DLinklist<Wantedperson>* FBIWanted);
void manage_edit_prisoner();
void manage_delete_prisoner(Prison* &main_prison);
bool userCreate(Prison* p);
string manage_name_toupper(string src);

#endif