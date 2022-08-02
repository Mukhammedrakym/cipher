#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string s, s1, s2;

int main(int argc, char *argv[]) {
	if(argc != 4) {
		cout << "Enter your\n";
		cout << "programm.exe file.ext key enc|dec: " << endl;
		exit(0);
	}
	ifstream filein;
	ofstream fileout; 
	filein.open(argv[1] , ios_base::in | ios_base::binary);

	if (!filein.is_open()) {
	cout << "This file is not found!!!";
	} 
		else {
			s = argv[3];
			s1 = argv[1];
			for(int i = 0; i < s1.length(); i++) {
				
				s2 += s1[i];
			}
				s2 += '.';
				s2 += s;
			fileout.open(s2 , ios_base::out | ios_base::binary);
			char bincode;
			int key = atoi(argv[2]);
			char newkey = (char) key;
			while(filein.get(bincode)) {
				fileout.put(bincode ^ newkey);
			}
			filein.close();
			fileout.close();
		     }
	return 0;
}
           