#include <stdlib.h>
#include <string>

#include <iostream>

using namespace std;

void check(string str) {
	str += " in the function\n";
	printf("%s\n", str.c_str());

}

int main(int argc, char const *argv[])
{
	string str = "noth";
	str += '0';
	check(str);
	std::cout << str;
	return 0;
}
