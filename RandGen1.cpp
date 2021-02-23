// February 8, 2015 -- RandGen1
// Program to generate random numbers for different pitch classes

#include <iostream>
#include <math.h>

using namespace std;


void main(){
	int randArray[18];
	int testRand, seed, pitchClass, octave;
	bool intIsNew, goAgain;
	char userChoice;

	const int ROWTOTAL = 19;
	const int ROWLENGTH = 14;
	const int ROWBASE = 68;

	do{
		goAgain = false;

		cout << "Enter a seed number:";
		cin >> seed;

		for (int i = 0; i < seed; i++)
			testRand = rand(); 

		for (int i = 0; i < ROWTOTAL; i++){
			for (int j = 0; j < ROWLENGTH; j++)
				randArray[j] = 0; // clear array

			for (int j = 0; j < ROWLENGTH; j++){
				do{
					intIsNew = true;

					testRand = rand() % ROWLENGTH + 1;

					// test if testRand is new or not
					for (int k = 0; k < j; k++)
						if (testRand == randArray[k])
							intIsNew = false;

					if (intIsNew)
						randArray[j] = testRand;
				}while(!intIsNew);
			}

			// print numerical array, adjusted to range of instrument
			for (int j = 0; j < ROWLENGTH; j++)
				cout << randArray[j]+ROWBASE << "  ";
			
			cout << endl;

			// print musical array
			for (int j = 0; j < ROWLENGTH; j++){
				pitchClass = (randArray[j]+ROWBASE)%12;
				octave = ((randArray[j]+ROWBASE)/12)-1;

				switch(pitchClass){
					case 0:
						cout << "C" << octave << "  ";
						break;
					case 1:
						cout << "C#" << octave << " ";
						break;
					case 2:
						cout << "D" << octave << "  ";
						break;
					case 3:
						cout << "D#" << octave << " ";
						break;
					case 4:
						cout << "E" << octave << "  ";
						break;
					case 5:
						cout << "F" << octave << "  ";
						break;
					case 6:
						cout << "F#" << octave << " ";
						break;
					case 7:
						cout << "G" << octave << "  ";
						break;
					case 8:
						cout << "G#" << octave << " ";
						break;
					case 9:
						cout << "A" << octave << "  ";
						break;
					case 10:
						cout << "A#" << octave << " ";
						break;
					case 11:
						cout << "B" << octave << "  ";
						break;
				}
			}

			cout << endl << endl;
		}

		cout << "Go again? (Y to continue)";
		cin >> userChoice;
		
		if(userChoice == 'Y' || userChoice == 'y')
			goAgain = true;

	}while(goAgain);	
}
