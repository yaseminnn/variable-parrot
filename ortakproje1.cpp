#include<iostream>
#include<fstream> 
#include<string>
#include <cstring>
#include <cctype>	//ozel karakter kontrolu

using namespace std;

//bu fonk satiri diziye atiyor  karakter karakter
void arrayConv(string input, char* output) {	//okunan satir ve dizinin 0. indeksinin adresi 
	char a[input.length() + 2];	//okunan satirin 2 fazlasi olacak sekilde dizi tanimladik.bos
	strcpy(a, input.c_str());	//diziye satiri kopyaladik . a dizisinde artik 1. satir var
	for(int i = 1; i < input.length() + 1; i++) {	//satir uzunluguna kadar tek tek 
		output[i] = a[i-1]; //?
	}
	output[0] = '\0';	//her satirin basina \0 koyduk.yani \0 artik 0. indeks oldu
	output[input.length() + 1] = ' ';
}

int varCounter(string line, int startPos) { // line = "char a,b" =>  "a,b"
	int counter = 0;
	
	string str;
	str = line.substr(startPos + 1); // str = "a,b;" 
	
	char charArray[str.length() + 2]; // Declare char array
	arrayConv(str, charArray); // line string => char array // "a,b" => ["a", " ", ",", "b"]
	
	for(int j = 0; j <= str.length() + 2; j++) {
		if(charArray[j] == ',') {
			cout<<"Comma Found"<<endl;
			counter++;
		} else if (charArray[j] == ';') {
			cout<<"Semi Column Found"<<endl;
			counter++;
			break;
		}
	}
	cout<<endl;
	return counter;
}

int main(){
	
	int varCount = 0;
	int lineCount = 0;
	ifstream dosya;
	dosya.open("C:\\Users\\Casper\\OneDrive\\Belgeler\\c++\\ortakproje.txt");
	string metin;	//okunacak satirlar icin
	
	if(dosya.is_open() == NULL)
	{
		cout << "dosya yok";
	}
	else
	{
		while(getline(dosya,metin))	//satir satir okuyor
		{
			lineCount++;
			cout<<lineCount<<'\t';
			char input[metin.length() + 2];	//okunan satirin 1 fazlasi kadar dizi olusturduk.bos
			int specialCharCount = 0;
			arrayConv(metin, input);	//okunan satir ve dizi 
			
			// Special char check
			for(int j = 0; j < metin.length() + 1; j++) {	//ozel karakter bakkiyor
				if(ispunct(input[j])) {
					specialCharCount++;
					cout<<input[j];
					
				}
			}
			cout<<'\t'<<'\t'<<specialCharCount<<'\t';
			
			for(int i = 0; i < metin.length() + 1; i++)
			{
				if(input[i] == '\t' || input[i] == ' ' ||  input[i] == '\0') 
				{
					switch(input[i+1]) 
					{
						case 'i':
							if(input[i + 2] == 'n' && input[i + 3] == 't')
							{
								if(input[i + 4] == '\t' || input[i + 4] == ' ') {
									cout<<"Int FOUND \t"<<input[i+3]<<endl;
									varCount += varCounter(metin, i+3);
									break;
								}

							}
							break;
						case 'c':
							if(input[i + 2] == 'h' && input[i + 3] == 'a' && input[i + 4] == 'r')
							{
										cout<<"Char FOUND \t"<<endl;
										break;
							}
							
						case 'd':
							if(input[i + 2] == 'o' && input[i + 3] == 'u' && input[i + 2] == 'b' && input[i + 4] == 'l' && input[i + 5] == 'e')
							{
												cout << "double FOUND\t" << endl;
												break;
							}
							
						case 'f':
							if(input[i + 2] == 'l' && input[i + 3] == 'o' && input[i + 4] == 'a' && input[i + 5] == 't')
							{
											cout << "float FOUND\t" << endl;
											break; 
							}
						
					}
				} else {
					
				}		
			}
			cout<<endl<<endl;
		}
	}
	
	dosya.close();
	cout<<"Var Count = "<<varCount;
	
	return 0;
}

