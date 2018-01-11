//Minjin Enkhjargal
//CS162 Program #3
//'playlist.txt' is an external file that will keep track
//of a users songs. The file will have contain song information.
//The user can add additional songs to the file or search 
//for an existing artist and display songs.


#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


//constant integers for sizes
const int MAX1 = 20;
const int MAX2 = 60;
const int MAX3 = 100;
const int PLAYMAX = 100;

//struct to hold all my song information
struct my_playlist {
	char artist[MAX1];
	char song[MAX1];
	char album[MAX1];
	char lyrics[MAX3];
	char info[MAX3];
	char similar[MAX2];
};

//Declare all my functions
void in(my_playlist music[], int & i);
bool choose_action(int response);
void add_song(my_playlist music[], int & i);
void search(my_playlist music[], int & i);
void out(my_playlist music[], int & i);
void check_l(my_playlist music[], int & i);

//Main function will call all my functions
int main() {

	int response, resp;
	int i = 0;
	char cont_prog;			//ask user if the want to quit
	my_playlist music[PLAYMAX];

	in(music, i);
	//check if the playlist already has the maximum amount of songs in the struct
	do {
		resp = choose_action(response);
		if(resp == 1){
			add_song(music, i);
			resp = 3;
		}
		else if(resp == 0) {
			search(music, i);
			resp = 3;
		} 
	
		cout << "Would you like to continue using the program? 'Y' or 'N' ";
		cin.get(cont_prog);
		cin.ignore(100, '\n');

	}while(toupper(cont_prog) == 'Y');
	
	cout << "***********************************" << endl;
	cout << "Thank you for using Playlist Maker! " << endl;
	out(music, i);

	return 0;
}


//Function will read in the existing playlist from external file
//into my struct
void in(my_playlist music[], int & i) {

	ifstream in_file;
	in_file.open("playlist.txt");


	if(in_file) {
		in_file.ignore(100, '\n');
		in_file.ignore(100, '\n');
		in_file.get(music[i].artist, MAX1, ' '&'#');
		in_file.ignore(100, '#');
		while(in_file && !in_file.eof()) {
			in_file.ignore();
			in_file.get(music[i].song, MAX1, ' '&'#');
			in_file.ignore(100, '#');

			in_file.ignore();
			in_file.get(music[i].album, MAX1, ' '&'#');
			in_file.ignore(100, '#');

			in_file.ignore();
			in_file.get(music[i].lyrics, MAX3, ' '&'#');
			in_file.ignore(100, '#');

			in_file.ignore();
			in_file.get(music[i].info, MAX3, ' '&'#');
			in_file.ignore(100, '#');

			in_file.ignore();
			in_file.get(music[i].similar, MAX2, '\n');
			in_file.ignore(100, '\n');
			
			++i;

			in_file.get(music[i].artist, MAX1, ' '&'#');
			in_file.ignore(100, '#');
		}
	}

	for(int j = 0;j < i;++j) {
			cout << music[j].artist
				<< music[j].song
				<< music[j].album
				<< music[j].lyrics
				<< music[j].info
				<< music[j].similar;
				}
	
	
in_file.close();
in_file.clear();
}

/*
//Only allow the lyrics to contain 100 characters or less.
//Start checking from the end of the lyrics and delete each character until
//it reaches a space and is 100 characters or less
void check_l(my_playlist music[], int & i) {
	char long_lyrics[MAX3];
	int l_len;
	int count = 0;
	int SHORT_LYRICS;

	

	cout << "Lyrics: ";
	cin.get(long_lyrics, MAX3, '\n');
	cin.ignore(100, '\n');

	l_len = strlen(long_lyrics);
	int j = l_len;
	while((j > 100) && (music[i].lyrics[j] != ' ')) {
		music[i].lyrics[j] = ' ';
		--j;
		++count;
	}
	SHORT_LYRICS = l_len - count;
	char lyrics[SHORT_LYRICS];
	for(int j = 0; j < SHORT_LYRICS;++j) {
		music[i].lyrics[j] = long_lyrics[j];
	}
}
*/

//Prompt user for song info and add to struct
void add_song(my_playlist music[], int & i) {
		cout << "****************************************** \n"
			 << "Great! Please enter the song information! \n"
			 << "\n"
			 << "Artist: ";
		cin.get(music[i].artist, MAX1, '\n');
		cin.ignore(100, '\n');

		cout << "Song: ";
		cin.get(music[i].song, MAX1, '\n');
		cin.ignore(100, '\n');

		cout << "Album: ";
		cin.get(music[i].album, MAX1, '\n');
		cin.ignore(100, '\n');
		//check_l(music, i);

		cout << "Lyrics: ";
		cin.get(music[i].lyrics, MAX3, '\n');
		cin.ignore(100, '\n');

		cout << "Artist Information: ";
		cin.get(music[i].info, MAX3, '\n');
		cin.ignore(100, '\n');

		cout << "Similar Artists: ";
		cin.get(music[i].similar, MAX2, '\n');
		cin.ignore(100, '\n');

		cout << "Song has been added! \n"
			 << "\n";
			 
		++i;
}


//Allow user to search for an artist and display all songs by that artist
void search(my_playlist music[], int & i) {
	int count;
	char cont_prog = 'N';
	char search_artist[MAX1];

	do{
		cout << "Great! What artist would you like to search: ";
		cin.get(search_artist, MAX1, '\n');
		cin.ignore(100, '\n');	
	
		//disp_header will act as a flag. If an artist match is found, the header will
		//become true, and print the message 
		bool disp_header = false;
		for(int j = 0;j < i;++j) {
			if(strcmp(music[j].artist, search_artist) == 0) {
				if(!disp_header) {		
					cout << "These are the songs you have from that artist:\n";
					disp_header = true;
				}
				cout << music[j].song << "\n";
				cont_prog = 'N';
			}
		}
		//disp header acts as a flag to check if an artist match was found
		if(disp_header == false) {
			cout << "No matching artists were found! Would you like to search again? "
				 << "'Y' or 'N' ? " << endl;
			cin.get(cont_prog);
			cin.ignore(100, '\n');
		}
	}while(toupper(cont_prog) == 'Y');
	cout << endl;
}


//Ask the user for what they want to do
//Add song to playist or search an artist
bool choose_action(int response) {

	cout << "***************************************************************" << endl;
	cout << "Would you like to add a song to your playlist or search for an artist in your playlist? \n"
		 << "   1) Add song to playlist \n"
		 << "   2) Search artist \n" 
		 << "Choose 1 or 2:  ";
	cin >> response;
	cin.ignore(100, '\n');

	while(response != 1 && response != 2) {
			cout << "Please choose '1' to add a song or \n"
	   		     << "'2' to search an artist \n"
		         << "Your choice: ";
			cin >> response;
			cin.ignore(100, '\n');
	}

	if(response == 2) {
			response = 0;
	}

	return response;
}


//Write the struct out to the playlist file
void out(my_playlist music[], int & i) {

	const char outfile[] = "playlist.txt";
	ofstream out;
	out.open(outfile);

	if(out) {
		out << "Minjin's Playlist \n"
			<< "\n";
		for(int j = 0;j < i;++j) {
			out << music[j].artist << "# "
				<< music[j].song << "# "
				<< music[j].album << "# "
				<< music[j].lyrics << "# "
				<< music[j].info << "# "
				<< music[j].similar << '\n'; 
		} 
	}
	out.close();
	out.clear();
}
