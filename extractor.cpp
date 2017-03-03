/*Program to Parse mail id's of NITCians from hostel roll list 
 input file is given as CLI argument and output is written to output.txt as space separatd strings*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;

int main(int argc,char* argv[]){
int n;
string rollno,firstname,temp,mailid;
fstream inputFile,outputFile;

inputFile.open(argv[1]);
if(!inputFile){
	cout<<"Failed to open the file "<<argv[1]<<endl<<"Please check whether it is present in current directory"<<endl;
	return -1;
}

outputFile.open("output.txt");
if(!outputFile){
	cout<<"Failed to create output file please check permissions of user "<<endl;
	return -1;
}


while(inputFile){
	inputFile>>n>>rollno>>firstname;
	getline(inputFile,temp);                                                 //Flushing out unnecessary details
	mailid =  firstname +"_"+ rollno  + "@nitc.ac.in";		 //Concating in the foem firstname_rollno@nitc.ac.in	
	transform(mailid.begin(),mailid.end(),mailid.begin(),::tolower); //Convering the result to lowercase
	outputFile<<mailid<<" ";
}
inputFile.close();
outputFile.close();
cout<<"Mail ids saved successfully in output.txt"<<endl;
return 0;
}

