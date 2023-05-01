#include <iostream>
#include <string>
#include <regex>
using namespace std;
 
int main(int argc,char** argv)
{
	if(argc < 2){
		cout << "RUN `EXTRACTSTR /help` FOR HELP.";
		return 0;
	}
	string text = argv[1];
	if(argc < 4){
		if((text == "-h")||(text == "--help")){
			cout << "# EXTRACTSTR by RyanLian" << endl;
			cout << "- This tool is usually used to extract a short string in a long string." << endl;
			cout << "- Usage:" << endl;
			cout << "	Run `EXTRACTSTR [LONG_STRING] [START_WITH] [END_WITH]` to extract string." << endl;
			cout << "	Run `EXTRACTSTR -h` or `EXTRACTSTR --help` for this help doc." << endl;
			cout << "- For example:" << endl << "	```" << endl;
			cout << "	EXTRACTSTR ABCDEFG B E" << endl;
			cout << "	CD" << endl  << "	```" << endl << "	```" << endl;
			cout << "	EXTRACTSTR ryanlian ry ian" << endl;
			cout << "	anl" << endl << "	```" ;
		}
		else
			cout << "RUN `EXTRACTSTR -h` OR `EXTRACTSTR --help` FOR HELP DOC.";
		return 0;
	}
	string startwt = argv[2];
	string endwt = argv[3];
	string rgx = ".*?"+startwt+"(.*?)"+endwt+".*?";
	regex pattern(rgx);
	smatch results;
	int sum=0;
	if (regex_match(text, results, pattern)) 
		for (auto it = results.begin(); it != results.end(); ++it){
			sum++;
			if(sum==2)
				cout << *it ;
		}
    return 0;
}
