//Minjin Enkhjargal
//CS162 Program 5 - due 11/30/2017
//This file contains the struct that contains all events, along with all headers and other constants.


#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


const int SIZE = 100;

struct node
{
	char * title;
	char * desc;
	int priority;
	node * next;

};


class my_events
{
	public:
		my_events();
		//void read_in();  //read in events from external file
		//void write_out();  //write current events list out to external file
		void get_entry();
		void add_entry(char * title, char * desc, int priority, int pr_answer);  //add an entry to events list
		//void delete_entry();  //delete any existing events
		void display();  //display current event list

	private:
		node * head;
		int i;
};
