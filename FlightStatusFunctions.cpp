#include "FlightStatus.h"
#include <fstream>
using namespace std;
void ArrivalTimes(){
	cout <<"****************************************************"<<endl;
	cout <<"AA Airlines Arrival Information Into LAX Los Angeles"<<endl;
	cout <<"****************************************************"<<endl<<endl;
	cout <<"Flight# Gate#  Airport Scheduled Expected Delay"<<endl<<endl;
	ifstream inFile;
	int i;
	string line;
	inFile.open("Arrivals.txt");
 while (!inFile.eof())
  {
    while ( getline (inFile,line) )
    {
      cout << line << '\n';
    }
inFile.close();
}
}
void DepartureTimes(){
	cout <<"****************************************************"<<endl;
	cout <<"AA Airlines Departure Information Into LAX Los Angeles"<<endl;
	cout <<"****************************************************"<<endl<<endl;
	cout <<"Flight# Gate#  Airport Scheduled Expected Delay"<<endl<<endl;
	ifstream inFile;
	//beginning of modified code
	int i = 0;
	string line[i];
	inFile.open("Departures.txt");
    while (getline(inFile,line[i],' ') )
    {	
      cout << line[i] << '\n';
    i++;
		}
		i = 0;
		//end of modified code
inFile.close();
}

