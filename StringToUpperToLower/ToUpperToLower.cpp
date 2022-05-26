#include <iostream>
#include<string>
#include <cstring>
#include <ctype.h>

using namespace std;

/*
* The std::string function does not provide any function to convert the underlying string to upper case or lower case. 
Write two functions that provide this behavior. Both functions return a copy of the converted string. In case of error, return an empty string.

std::string ToUpper(const std::string &str) ;
std::string ToLower(const std::string &str) ;

Hint : Use toupper & tolower from C string library.
*/
std::string ToUpper(const std::string& str)
{
	string upper;
	char* cstr = new char(str.length() + 1);
	strcpy(cstr, str.c_str());

	for (int i = 0; i < str.length(); ++i)
	{
		upper += toupper(cstr[i]);
	}

	return upper;
}

std::string ToLower(const std::string& str)
{
	string lower;

	char* cstr = new char(str.length() + 1);
	//unique_ptr< char[]> cstr{new char};
	strcpy(cstr, str.c_str());

	for (int i = 0; i < str.length(); ++i)
	{
		lower += tolower(cstr[i]);
	}

	return lower;
}

/*
The find function in std::string uses a case-sensitive search. 
Write a function that also performs a case insensitive search. 
Use an enum to decide between case-sensitive and case-insensitive search.
The prototype of the function is:
*/
enum class Case { SENSITIVE, INSENSITIVE };

size_t Find(
	const std::string& source,         //Source string to be searched
	const std::string& search_string,  //The string to search for
	Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
	size_t offset = 0) {                //Start the search from this offset
		//Implementation
		/*
		return position of the first character
		of the substring, else std::string::npos
		*/
	char* csource = new char(source.length() + 1);
	char* csearch_string = new char(search_string.length() + 1);
	if (searchCase == Case::INSENSITIVE)
	{
		return ToLower(source).find(ToLower(search_string));
	}
	if (source.find(search_string) != source.npos)
		return source.find(search_string);
	else
		return 99;
}
/*
Note that, we don't have direct write access to the raw string inside std::string.
*/

int main()
{
	//string input;
	//cout << "Enter a string: "; 
	//getline(cin, input);
	//cout << "UpperCase Format: " << ToUpper(input) << endl;
	//cout << "LowerCase Format: " << ToLower(input) << endl;
	cout << "Position: " << Find("Hello World Hello World", "WO", Case::INSENSITIVE) << endl;
	cout << "Position: " << Find("Hello World", "LD", Case::INSENSITIVE) << endl;
	cout << "Position: " << Find("Hello World", "Wo", Case::SENSITIVE) << endl;
	cout << "Position: " << Find("Hello World", "WO", Case::SENSITIVE) << endl;

	return 0;
}