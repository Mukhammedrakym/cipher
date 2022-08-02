#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>

using namespace std;
using namespace CryptoPP;

int main(int argc, char *argv[]) {
	if(argc != 2){
		cout << "ERROR: Parametres should be (a.exe nameOfFile)";
	}
	else{
		Weak1::MD5 hash;
		int N = Weak1::MD5::DIGESTSIZE;
		byte md5[N];
		int l = 0;
		char * data;
		ifstream file;
		file.open(argv[1], ios_base::in | ios_base::binary);

		if(!file.is_open()) {
		cout << "file is not found!";
		}
		else {
			file.seekg(0, ios::end);
			l = file.tellg();
			file.seekg(0, ios::beg);
			data = new char[l];
			file.read(data, l);
			file.close();

			hash.CalculateDigest(md5, (unsigned char *)data, l);
			cout << "MD5 hash function of the file: ";

			for(int i=0; i < N; i++) {
				cout << hex << setfill('0') << setw(2) << (unsigned short)(md5[i]) << " ";
			}
			cout << endl;
			delete [] data;
		}
	}
			
	return 0;
}