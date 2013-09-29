/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * KUID: 2373732
 * File Name: html_cleaner.cpp
 * Date Created: 1/28/13
 * Last Modified: 2/3/13
 * Description: This program will accept a file of raw html and a file of keywords
 * and will fix unclosed paragraph tags and encase any instance of the keywords in
 * italics. Depending on argument, the output can be directed either to standard
 * cout or to a specified file. Though listed as not necessary, we preserve newlines
 * from the raw html file in order to provide structure to both file and cout output.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
 * Precondition: an input stream for a text file and a string vector have been declared
 * Postcondition: the string vector will be filled with the contents of the text
 * file delimited by all whitespace characters
 */
void get_keys(ifstream& file, vector<string>& str_vector) {
	string line;
	
	while(file >> line)
		str_vector.push_back(line);
} 

/*
 * Precondition: an input stream, string vector, and generic output stream have been declared
 * Postcondition: lines are recovered one by one from the input file and
 * First - the line is checked for paragraph tags. If a paragraph tag has been encountered, we
 * ensure that the next opening paragraph tag is preceded by a closeing tag. 
 * Second - scan the line for instances of any of the strings contained in the vector. Encase
 * them in italics.
 * Third - write correctly parsed lines to output stream
 */
void clean_tags(ifstream& file_in, vector<string>& str_vector, ostream* &file_out) {
	string line;
	bool is_tag_open = false;
	
	//Scan line by line
	while(file_in >> line) {
		//Ensure each open paragraph gets a matching close paragraph
		if(is_tag_open && (line.find("<p>") != string::npos || line.find("</body>") != string::npos)) 
			line = "</p>" + line;

		if(line.find("<p>") != string::npos) 
			is_tag_open = true;

		if(line.find("</p>") != string::npos) 
			is_tag_open = "false";

		//If the current symbol is a keyword, encase it in italics
		int key_pos;
		for(int i = 0; i < str_vector.size(); i++) {
			key_pos = line.find(str_vector[i]);
			if(key_pos != string::npos) {
				line = "<i>" + str_vector[i] + "</i>";
			}
		}
	
		//Pass correctly formatted code to out stream, preserve newlines for structure	
		if(file_in.peek() == '\n')
			*file_out << line << endl;
		else
			*file_out << line << ' ';
	}
}

int main(int argc, char* argv[]) {
	//Create input stream for html file
	ifstream html_in;
	html_in.open(argv[1]);	
	
	//Create string vector and fill from key file
	vector<string> key_vector;
	ifstream key_file;
	key_file.open(argv[2]);
	get_keys(key_file, key_vector);
	
	//Create pointer to generic ostream. Based on argument number, direct the ostream to file or cout
	ostream* html_out;
	//Output file specified - direct output to file
	if (argc == 4)
		html_out = new ofstream(argv[3]);
	//No output file specified - direct output to cout
	else if(argc == 3) {
		html_out = &cout;
	//Wrong number of arguments given - provide advice
	} else {
		cout << "The correct forms of the command are the following:\n";
		cout << "html_cleaner <html_file_name> <key_file_name>\n";
		cout << "html_cleaner <html_file_name> <key_file_name> <output_file_name>\n";
	}
	
	//Modify html stream for tags and keywords stored in our vector, direct output to ostream
	clean_tags(html_in, key_vector, html_out);

	//Release memory	
	key_file.close();
	html_in.close();
	if(argc == 4) {
		delete html_out;
		html_out = NULL;
	}
}
