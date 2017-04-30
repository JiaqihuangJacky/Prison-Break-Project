#ifndef UI_H
#define UI_H
#include<string>
#include<iostream>
#include"Prison.h"
using namespace std;

void UI_initialization(const string WANTED_FILE, const string SAVE_FILE, const string EMPTY, int NUM_SLOT, Prison *main_prison, DLinklist<Wantedperson>* FBIWanted);
void UI_operation(const string SAVE_FILE, Prison* &main_prison, DLinklist<Wantedperson>* &FBIWanted);
void UI_quit(const string SAVE_FILE, Prison* &main_prison);

#endif