// February 23, 2015 -- RandGen2
// Program to generate random numbers for different pitch classes
// Chooses 3-4 notes for the flute for each note of the clarinet

#include <iostream>
#include <math.h>

using namespace std;


void main(){
	const int ROWTOTAL = 15;
	const int ROWLENGTH = 8;
	const int CLARBASE = 63;
	const int CLARRANGE = 6;
	const int FLUTEBASE = 60;
	const int FLUTERANGE = 14;
	
	int clarArray[ROWTOTAL], fluteArray[ROWTOTAL][ROWLENGTH];
	int testRand, seed, pitchClass, octave, pitchGap;
	bool intIsNew, goAgain;
	char userChoice;

	do{
		goAgain = false;

		cout << "Enter a seed number:";
		cin >> seed;

		for (int i = 0; i < seed; i++)
			testRand = rand(); 

		cout << endl << "Clarinet  Flute" << endl;
		
		for (int i = 0; i < ROWTOTAL; i++){
			for (int j = 0; j < ROWLENGTH; j++)
				fluteArray[i][j] = 0; // clear flute array

			clarArray[i] = (rand() % CLARRANGE) + CLARBASE; // set clarinet note

			for (int j = 0; j < ROWLENGTH; j++){
				do{
					intIsNew = true;

					testRand = (rand() % FLUTERANGE) + FLUTEBASE;

					// test if testRand is new or not
					for (int k = 0; k < j; k++)
						if (testRand == fluteArray[i][k])
							intIsNew = false;

					if (intIsNew)
						fluteArray[i][j] = testRand;
				}while(!intIsNew);

				// eliminate dissonant intervals
				pitchGap = abs(clarArray[i] - fluteArray[i][j])%12;
				if (pitchGap == 1 || pitchGap == 2 || pitchGap == 5 ||                            
					pitchGap == 6 || pitchGap == 10 || pitchGap == 11)
					fluteArray[i][j] = 0;
			}

			// print numerical array, adjusted to range of instrument
			cout << clarArray[i] << "        ";
			
			for (int j = 0; j < ROWLENGTH; j++){
				if(fluteArray[i][j] == 0)
					cout << fluteArray[i][j] << "   ";
				else
					cout << fluteArray[i][j] << "  ";
			}
			
			cout << endl;

			// print musical array
			pitchClass = clarArray[i]%12;
			octave = (clarArray[i]/12) - 1;
			
			switch(pitchClass){
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
			}

			cout << "      ";

			for (int j = 0; j < ROWLENGTH; j++){
				if(fluteArray[i][j] == 0)
					cout << "--  ";
				else{
					pitchClass = fluteArray[i][j]%12;
					octave = (fluteArray[i][j]/12)-1;

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
			}

			cout << endl << endl;
		}

		cout << "Go again? (Y to continue)";
		cin >> userChoice;
		
		if(userChoice == 'Y' || userChoice == 'y')
			goAgain = true;

	}while(goAgain);	
}
