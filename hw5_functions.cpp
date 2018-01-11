//Minjin Enkhjargal
//CS162 Program #5 due 11/30/2017
//Function file contains functions to add to the event list from the beginning or middle. Another function also delete events, if user decides.



#include "hw5.h"


//constructer to initialize all my information
my_events::my_events()
{
	i = 0;
	head = NULL;
}


/*
void my_events::read_in()
{
	ifstream in_file;
	in_file.open("events.txt");

	if(in_file) {
		in_file.ignore(2);
		in_file.get(entry[i], 100, '\n');
		in_file.ignore(100, '\n');
		cout << "entry 1 is: " << entry << endl;
		++i;
		while(in_file && !in_file.eof()) {
			in_file.ignore(2);
			in_file.get(entry[i], 100, '\n');
			in_file.ignore(100, '\n');
			++i;

			in_file.ignore(2);
			in_file.get
		}
	}

}
*/


//get all the user information for title, desc, and priority
void my_events::get_entry() {
	char title[SIZE];
	char desc[SIZE];
	int priority;
	int pr_answer;
	
	cout << "What is the title of your event? ";
	cin.get(title, SIZE, '\n');
	cin.ignore(100, '\n');
	
	cout << "Add a description: ";
	cin.get(desc, SIZE, '\n');
	cin.ignore(100, '\n');

	cout << "Set a priority (1-10): ";
	cin >> pr_answer;
	cin.ignore(100, '\n');

	add_entry(title, desc, priority, pr_answer);


}


//add all the entries and connect all information
void my_events::add_entry(char * title, char * desc, int priority, int pr_answer) 
{

	//if list is empty
	if(!head) {
		head = new node;
		head -> title = new char[strlen(title + 1)];
		strcpy(head ->title, title);
		head -> desc = new char[strlen(desc + 1)];
		strcpy(head -> desc, desc);
		head -> priority = pr_answer;
		head -> next = NULL;
	}

	//add to beginning of list, middle or end
	else {
		
		bool set = false;

		node * current = head;
		
		node * temp = new node;
		temp -> title = new char[strlen(title + 1)];
		strcpy(temp ->title, title);

		temp -> desc = new char[strlen(desc + 1)];
		strcpy(temp -> desc, desc);

		temp -> priority = pr_answer;


		while(current != NULL && set == false) {
			if(current -> priority > pr_answer) {
				if(current == head) {
					temp -> next = head;
					head = temp;
					set = true;
				}

				else{
				
					temp -> next = current;
					current = temp;
					set = true;
				}

			}
			else{
				current = current -> next;
			}
		}

		current = temp; 
	}
}

/*
void my_events::delete_entry(char dlt_entry[])
{

	node * current = head;
	
	while(current != NULL) {
		if(current -> next == dlt_entry) {
			delete current;
		}
		current = current -> next;
	}
}
*/

//Display all my entries
void my_events::display()
{
	int count = 0;
	node * current = head;

	while(current) {
		cout << current -> priority << ". " << current -> title << current -> desc << endl;
		current = current -> next;
		++count;
	}

	cout << "You have " << count << " entries in your list. \n" << endl;
}


/*
void my_events::write_out()
{


}
*/
