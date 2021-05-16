#include <iostream>
#include <string>

using namespace std;

int main () {
	string name = "turkey";
	string a[4][2] = {{"a", ""}, {"b", ""}, {"c", ""}, {"d", ""}};
	// [["x", "y"], ["y", "ya"], ["a", "yas"],...]
	
	for(int i = 0; i < 4; i++) {
		a[i][1] = name.substr(0, i+1);
		cout<<a[i][0]<<" : "<<a[i][1]<<endl;
	}
	return 0;
}
