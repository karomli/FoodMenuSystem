#include "foodClass.h"
#include <iostream>

FoodClass::FoodClass()	{
	return;
}

FoodClass::~FoodClass() {
	return;
}

void FoodClass::setUserSelectedMainMenu(int blmenu) {
	this->fm.mainMenu = blmenu;
}

int FoodClass::getUserSelectedMainMenu(void) {
	return this->fm.mainMenu;
}
	
void FoodClass::setUserSelectedMainDish(int userMainDish) {
	switch(this->getUserSelectedMainMenu()) {
		case 1:	
			this->fm.mainDish = (char*)util_lookup_beefmenu(userMainDish);
			break;
		case 2:	
			this->fm.mainDish = (char*)util_lookup_lambmenu(userMainDish);
			break;
		default:
			break;
	}
}
	
char* FoodClass::getUserSelectedMainDish() {
	return this->fm.mainDish;
}

void FoodClass::DisplayMainMenu() {
	for (int i = 0 ; i < get_mainmenu_table_size(); i++) {
        std::cout << i+1 << "." << util_lookup_mainmenu(i+1)<< std::endl;
    }
}

void FoodClass::DisplayBeefLambMenu(int blmenu) {
	int size;
	int i;
	this->setUserSelectedMainMenu(blmenu);
	switch(blmenu) {
		case 1:	
			size = get_beefmenu_table_size();
			for( i = 0; i < size; i++)
				std::cout << i+1 << "." << util_lookup_beefmenu(i+1)<< std::endl;
			break;
		case 2:	
			size = get_lambmenu_table_size();
			for( i = 0; i < size; i++)
				std::cout << i+1 << "." << util_lookup_lambmenu(i+1)<< std::endl;
			break;
		default:
			size = 0;
			break;
	}
}
int main() {
	
	int mainMenu, mainDish, compDish;
	
	FoodClass fc;

	std::cout << "Please select your main course:"
	<< std::endl;
	fc.DisplayMainMenu();
	std::cin >> mainMenu;
	fc.setUserSelectedMainMenu(mainMenu);

	std::cout << "Please select your " << util_lookup_mainmenu(mainMenu) << " course:"
	<< std::endl;
	fc.DisplayBeefLambMenu(mainMenu);
	std::cin >> mainDish;
	fc.setUserSelectedMainDish(mainDish);

	std::cout << "Primary Menu: " <<  util_lookup_mainmenu(fc.getUserSelectedMainMenu()) << std::endl;
	std::cout << "Your selected main course is: " << fc.getUserSelectedMainDish() << std::endl;
	return 0;
}
