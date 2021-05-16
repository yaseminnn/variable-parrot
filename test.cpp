#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {
	/*
	string name = "turkey";
	string a[4][2] = {{"a", ""}, {"b", ""}, {"c", ""}, {"d", ""}};
	// [["x", "y"], ["y", "ya"], ["a", "yas"],...]
	
	for(int i = 0; i < 4; i++) {
		a[i][1] = name.substr(0, i+1);
		cout<<a[i][0]<<" : "<<a[i][1]<<endl;
	}
	*/
	string my_str = "This is C++ Programming Language";
   cout << "String with Spaces :" << my_str << endl;
   remove(my_str.begin(), my_str.end(), ' ');
   cout << "String without Spaces :" << my_str<<"!!";
	return 0;
}
