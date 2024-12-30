// Aqdas Juya , 05/09/2024 , ajuya@pdx.edu ,  Program # 3 , cs 162
// Prog3.h

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


const int NAME{100};
const int CATEGORY{20};
const int COLOR{50};
const int SIZE{121};

struct storeitem
{
	char name[NAME];
	char category[CATEGORY];
	char description[SIZE];
	float price; 
	char colors[COLOR];
	int item_size; 
	char material[SIZE];
};


void name_item(storeitem my_storeitem[], int & num_item);
void match_names(storeitem match_names[], int& num_item);
void display_all( storeitem display[], int& num_item);
void save_file(storeitem display[], int& num_item);
