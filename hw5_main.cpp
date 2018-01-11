//Minjin Enkhjargal
//CS 162 Program #5 due 11/30/2017
//Program will use linear linked lists and pointers to organize a to-do/events list according to each item's importance.

#include "hw5.h"

int main()
{
	
	cout << "Thank you for using 'My Events'. This program will help you keep track of all you important events for the month of December! \n" << '\n' << endl;
	cout << "Use the menu to add or delete any entries. \n"
		 << "***************************************" << endl;

	my_events holidays;
	my_events();
	
	char answer;
	char cont_prog;
	//char dlt_entry[20];
	
	//display menu and run program
	do{
	cout << "****Main Menu*****" << endl;
	cout << "a   add an event \n"
		 << "d   delete an event \n"
		 << "s   show all events \n"
		 << "******************* \n"
		 << "Choice: ";
	cin >> answer;
	cin.ignore(100,'\n');

	/*if(answer == 'd') {
		cout << "Which entry would you like to delete? Title of entry you would like to delete: " << endl;
		cin.get(dlt_enry, 20, '\n');
		cin.ignore(100, '\n');
	}*/

	if(answer == 'a') {
		holidays.get_entry();
	}
	if(answer == 's') {
		holidays.display();
	}
	
	cout << "Would you like to continue using the program? 'y' or 'n' " << endl;
	cin >> cont_prog;
	cin.ignore(100, '\n');

	}while(toupper(cont_prog) == 'Y');
	
	//read_in(i);

return 0;

}
