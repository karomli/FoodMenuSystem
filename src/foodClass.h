#include <stdlib.h>
#include <iostream>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif

struct type_name {
	unsigned int type;
	const char *name;
};

static const char *util_lookup_type_name(unsigned int type,
					 const struct type_name *table,
					 unsigned int count)
{
	unsigned int i;

	for (i = 0; i < count; i++)
		if (table[i].type == type) {
			return table[i].name;
		}

	return NULL;
}

static const struct type_name MAINMENU[] = {
	{ 1, "Beef" },
	{ 2, "Lamb" }
};

const char *util_lookup_mainmenu(unsigned int type) {
	return util_lookup_type_name(type, MAINMENU,
								ARRAY_SIZE(MAINMENU));
}

static const struct type_name BEEFMENU[] = {
	{ 1, "Rib Eye Steak" },
	{ 2, "Sirloin Steak" },
	{ 3, "T-Bone Steak" },
	{ 4, "Tenderloin Steak" }
};

const char *util_lookup_beefmenu(unsigned int type) {
	return util_lookup_type_name(type, BEEFMENU,
								ARRAY_SIZE(BEEFMENU));
}

static const struct type_name LAMBMENU[] = {
	{ 1, "Lamb Grill"},
	{ 2, "Lamb Loin" },
	{ 3, "Lamb Shank"}
};

const char *util_lookup_lambmenu(unsigned int type) {
	return util_lookup_type_name(type, LAMBMENU,
								ARRAY_SIZE(LAMBMENU));
}

int get_mainmenu_table_size() {
	return (ARRAY_SIZE(MAINMENU));
}

int get_beefmenu_table_size() {
	return (ARRAY_SIZE(BEEFMENU));
}

int get_lambmenu_table_size() {
	return (ARRAY_SIZE(LAMBMENU));
}

struct foodMenu {
	int mainMenu;
	char *mainDish;
};

class FoodClass {
	public:
	FoodClass();			//Contructor
	~FoodClass();			//Destructor

	void setUserSelectedMainMenu(int blmenu);
	int getUserSelectedMainMenu(void);
	void setUserSelectedMainDish(int md);
	char* getUserSelectedMainDish(void);

	void DisplayMainMenu(void);
	void DisplayBeefLambMenu(int blm);

	foodMenu fm;
};
