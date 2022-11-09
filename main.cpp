#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void showhelp(){
	cout << 
		"Echo And Write command\n"
		"USAGE: eaw <FILES>\n"
		" <FILES> might include special value:\n"
		" no1   No output into stdout\n"
		" 2     Output into stderr\n"
		<< endl;
	return;
}

int main(int argc, char *argv[]){
	if(argc<2){
		cout << "*** Filename Required ***\n\n" <<endl;
		showhelp();
		return -1;
	}
	vector<fstream> files;
	bool do1=true,do2=false;
	for(int i=1;i<argc;i++){
		if(string("no1")==argv[i])
			do1=false;
		else if(string("2")==argv[i])
			do2=true;
		else
			files.emplace_back(argv[i],ios::out);
	}
	string buf;
	while((bool)getline(cin,buf)){
		if(do1)cout<<buf<<endl;
		if(do2)cerr<<buf<<endl;
		for(unsigned int i=0;i<files.size();i++){
			files[i]<<buf<<endl;
		}
	}
	return(0);
}
