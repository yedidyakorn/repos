
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
using uint = unsigned int;
using cstring = char*;

void main()
{
	ofstream outFile("myfile.txt", ios::out | ios::binary);
		char str1[] = "this is a block of data\n"; // יצירת מערך
	outFile.write(str1, sizeof(str1));// כתיבת המערך לקובץ
	outFile.close();
	//ifstream inFile("myfile.txt", ios::in | ios::binary);
	//char str2[11]; // יצירת מערך שיקבל את הקריאה מהקובץ
	//inFile.read(str2, 10); // קריאת 10 בתים מהקובץ, אל תוך המערך
	//str2[10] = '\0'; //.. בכל זאת... בהדפסה בשורה הבאה נצטרך לדעת עד היכן להדפיס
	//cout << str2; inFile.close();
	cout << endl;

		char ch = 'a';

		fstream exFile("testfile.txt", ios::out | ios::in | ios::binary);
		exFile.put(ch);            //write the content of ch to the file
		exFile.seekg(0, ios::beg); //go to the beginning of the file
		exFile.get(ch); //read one character
		exFile.write(str1, sizeof(str1));
		cout << ch << endl;
		exFile.close();
	
		system("pause");
}