#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  string s, s1, s2, data, gam, g, gamma;
  char ch;
  int i, l;
  if (argc != 4) {
    cout << "Enter your\n";
    cout << "programm.exe nameOfFile gamma enc|dec: " << endl;  //for example gamma: 1.15.255
    exit(0);
  }
  ifstream filein;
  ofstream fileout;
  filein.open(argv[1], ios_base::in | ios_base::binary);        
  if (!filein.is_open()) {
    cout << "File is not found!";
  }
  else {
    // get length of file:
    filein.seekg (0, ios::end);
    l = filein.tellg();
    filein.seekg (0, ios::beg);

    s = argv[3];
    s1 = argv[1];
    for (i = 0; i < s1.length(); i++) {
      s2 += s1[i];
    }
    s2 += '.';
    s2 += s;

    g = argv[2];
    stringstream gam(g);
    while(getline(gam, gamma, '.')) {
     // cout << gamma << " ";
    }
   // cout << gamma.length();	

    fileout.open(s2, ios_base::out | ios_base::binary);
    while (filein.get(ch)) {
      data.append(1, ch);
    }
	
    for (i = 0; i < l; i++) {
      fileout.put(data[i] ^ gamma[i % gamma.length()]);
    }		
  }
  filein.close();
  fileout.close();

  return 0;
}