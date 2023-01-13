#include <iostream>
#include <string>
#include <regex>
using namespace std;
 
int main(int argc,char** argv)
{
	string text = argv[1];
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
