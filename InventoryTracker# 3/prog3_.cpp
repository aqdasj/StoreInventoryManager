// Aqdas Juya , 05/09/2024 , ajuya@pdx.edu ,  Program # 3 , cs 162

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fstream>

#include "prog3_.h"

const int MAX_ITEMS{20};


// This is the main function where everything is being called in this function.
int main() {
	storeitem boxlunch[MAX_ITEMS];
	int menu {0};
	int numitem {0};

                cout <<"Welcome to this program!"<<endl;                
		cout <<"In this program you will be having a menu choices to add items of any storyitems that you want it to be listed." <<endl;
		cout <<"You can find the items that you enter by entering '2' to display a match of a particular item, by name, or you can enter '3' to display everything." <<endl;
		cout <<"The items that you enter is also save into another .txt file and if you want to quit you can enter '4'." << endl;
	do
	{
                cout <<"\nThese are your menu choices: "<<endl;
		cout <<"Enter '1' if you would like to add an item"<<endl;
		cout<< "Enter '2' to display a match of a particular item, by name" <<endl;
		cout<< "Enter '3' to Display all items"<<endl;
		cout<< "Enter '4' to Quit\n" <<endl;
                cout <<"Please enter your menu choice: ";
		cin >> menu;
		cin.ignore(100,'\n');

		if (menu == 1) {
			name_item(boxlunch, numitem);
		}
		else if (menu == 2) {
			match_names(boxlunch, numitem); 
		}
		else if (menu == 3) {
			display_all(boxlunch, numitem);
		}
		else if (menu == 4) {
			cout << "" <<endl;
		}
		else {
			cout <<"Please only enter the menu listed"<<endl;
		}
	} while (menu != 4);

	save_file(boxlunch, numitem);

	return 0; 
}

// this is the void function of entering the name,descreption price or anything else. This function will take a struct of StoreItem and the numItem as a reference.
void name_item(storeitem my_storeitem[], int& num_item) 
{
	if(num_item >= MAX_ITEMS) {
		cout << "\nArray is full, you can not add any more items.\n" <<endl;
	} else {
		cout <<"\nPlease enter the name of your item: ";
		cin.get(my_storeitem[num_item].name,NAME,'\n');
		cin.ignore(100,'\n');

		cout <<"Please enter if it is DC or Marvael (or others): ";
		cin.get(my_storeitem[num_item].category,CATEGORY,'\n');
        	cin.ignore(100,'\n');

		cout <<"Please enter a description of the item: ";
		cin.get(my_storeitem[num_item].description,NAME,'\n');
        	cin.ignore(100,'\n');

		cout <<"please enter your price: ";
		cin >>my_storeitem[num_item].price;
        	cin.ignore(100,'\n');

		cout<<"Please enter the color: ";
		cin.get(my_storeitem[num_item].colors,NAME,'\n');
        	cin.ignore(100,'\n');

		cout<<"Please enter the size of your items: "; 
		cin >> my_storeitem[num_item].item_size;
		cin.ignore(100,'\n');

		cout<<"Please enter the type of material: ";
		cin.get (my_storeitem[num_item].material,SIZE,'\n');
		cin.ignore(100,'\n');

		num_item++;
	}
}
//This is a void function where it will match iteams by names. This function will take a struct of StoreItem and the numItem as a reference.
void match_names(storeitem m_names[], int& num_item)
{
	char new_name[NAME];
	cout<<"Please enter the item's name you want to match with: ";
	cin.get(new_name,NAME,'\n');
	cin.ignore(100,'\n');

	bool found = false;
	for(int i {0}; i < num_item; ++i) {
		if(strcmp(new_name, m_names[i].name) == 0)
		{
			cout << "\nItem: " << i + 1 
			     << "\nName: " << m_names[i].name
			     << "\nCatogory: " << m_names[i].category
			     << "\nDescription: " << m_names[i].description
			     << "\nPrice: " << m_names[i].price 
			     << "\nColor: " << m_names[i].colors 
			     << "\nitem size: " << m_names[i].item_size
			     << "\nmaterial: " << m_names[i].material << "\n"<< endl;
			found = true;

		}
	}

	if(!found) {
		cout << "no items matched the provieded name." << endl;
	}
}
//this is the function that display everything if they want everything to display. "This function will take a struct of StoreItem and the numItem as a reference.
void display_all( storeitem display[], int& num_item) 
{
	if(num_item == 0) {
		cout << "There is no items to display." << endl;
	}
	else {

		for(int i {0}; i < num_item; ++i) {
        		cout << "\nItem: " << i + 1  
                	     << "\nName: " << display[i].name
 	                     << "\nCatogory: " << display[i].category
        	             << "\nDescription: " << display[i].description
           	             << "\nPrice: " << display[i].price 
                	     << "\nColor: " << display[i].colors 
                             << "\nitem size: "<<  display[i].item_size
                             << "\nmaterial: " << display[i].material<< "\n"<< endl;

		}
	}
}
//this function will save all the items enterd in a diffrent .txt file. 
void save_file(storeitem display[], int& num_item) {
	ofstream data_file;
	data_file.open("output.txt");

	for(int i {0}; i < num_item; ++i) {
		data_file << display[i].name << '|'
			  << display[i].category << '|'
			  << display[i].description << '|'
			  << display[i].price << '|'
			  << display[i].colors << '|'
			  << display[i].item_size << '|'
			  << display[i].material;
		if(i+1 <num_item)
			data_file << '\n';
	}
	data_file.close();
}
