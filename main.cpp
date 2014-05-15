#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

std::string trim(const std::string& oldstr){
	std::string newstr;
	if(oldstr.length()){
		unsigned int i	= oldstr.find_first_not_of(' ');
		unsigned int j	= oldstr.find_last_not_of(' ');
		newstr	= oldstr.substr(i,j-i+1);
	}
	return newstr;
}

void processLine (const std::string& line) {
	
	if(line.empty())	return;
	if(line == " ")		return;

	std::istringstream ss(line);
	std::string a, b;

	std::getline(ss,a,',');
	if(ss.eof())	return;
	std::getline(ss,b);
	b = trim(b);
	
	const char* A = a.c_str();
	const char* B = b.c_str();
	unsigned int Ai = a.length();
	unsigned int Bi = b.length();
	
	if(Bi <= Ai){
		if(strcmp(A+(Ai-Bi),B) == 0){
			std::cout << "1\n";
			return;
		}
	}
	std::cout << "0\n";

	return;
}


int main(int argc, char **argv)
{
	std::ifstream file;
	std::string line;
	file.open (argv[1]);

	if(file.good()){
		while(std::getline(file,line)){
			processLine(line);
		}
	}else{
		std::cout << strerror(errno) << "\n";
		std::cout << "Could not open " << argv[1] << "\n";
	}

	return 0;
}
