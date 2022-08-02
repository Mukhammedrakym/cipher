#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int func (int left, int key) {
   return left ^ key;
}

int main(int argc, char *argv[]) {
  string fname, data;
  bool  f = true;;
  char ch;
  int i, j, n, l, key, newkey, round = 3, temp;
  if (argc != 4) {
    cout << "Enter your\n";
    cout << "programm.exe nameOfFile key enc|dec: " << endl;  
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
     filein.seekg(0, ios::end);
     l = filein.tellg();
     filein.seekg(0, ios::beg);                                                            
   
     fname = argv[1];
     fname += '.';
     fname += argv[3];
     
     key = atoi(argv[2]);
     fileout.open(fname, ios_base::out | ios_base::binary);
     while (filein.get(ch)) {
       data.append(1, ch);
     }
     if (data.length() % 8 != 0) {
        f = false;
        n = l + (8 - (l % 8));
     }
     else {
        n = l;
     }      
     int a[n]; 
     int w = n - l;
     for (i = 0; i < n; i++) {
       a[i]  = (int) (data.c_str()[i]);
     }
     int keys[round];
     for (i = 0; i < round; i++) {
       keys[i] = rand() % 100 + 1;
     }
     
     for (j = 0; j < round; j++) {
       newkey = key + keys[j];
       cout << "Keys: " << newkey << endl;

       for (size_t i = 0; i < n;) {
         temp = func(a[i + 4], func(a[i], newkey));
         a[i + 4] = a[i];
         a[i] = temp;

         if (++i % 4 == 0) {
           i += 4;
         }
       }
     }
     for (i = 0; i < n; i++) {
       fileout.put((char) a[i]); 
     } 
  }
  filein.close();
  fileout.close();
return 0;
}                                                          