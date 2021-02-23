// February 26, 2015 -- RandGen4
// Program to generate random numbers for different pitch classes
// Chooses 3-4 notes for the flute for each note of the clarinet

#include <iostream>
#include <math.h>

using namespace std;


void main(){
	const int ROWTOTAL = 15;
	const int ROWLENGTH = 8;
	const int CLARBASE = 50;
	const int CLARRANGE = 13;
	const int FLUTEBASE = 74;
	const int FLUTERANGE = 18;
	
	int fluteArray[ROWTOTAL], clarArray[ROWTOTAL][ROWLENGTH];
	int testRand, seed, pitchClass, octave, pitchGap;
	bool intIsNew, goAgain;
	char userChoice;

	do{
		goAgain = false;

		cout << "Enter a seed number:";
		cin >> seed;

		for (int i = 0; i < seed; i++)
			testRand = rand(); 

		cout << endl << "Flute     Clarinet" << endl;

		for (int i = 0; i < ROWTOTAL; i++){
			for (int j = 0; j < ROWLENGTH; j++)
				clarArray[i][j] = 0; // clear clarinet array

			// set flute note
			fluteArray[i] = (rand() % FLUTERANGE) + FLUTEBASE;

			for (int j = 0; j < ROWLENGTH; j++){
				do{
					intIsNew = true;

					testRand = (rand() % CLARRANGE) + CLARBASE;

					// test if testRand is new or not
					for (int k = 0; k < j; k++)
						if (testRand == clarArray[i][k])
							intIsNew = false;

					if (intIsNew)
						clarArray[i][j] = testRand;
				}while(!intIsNew);

				// eliminate dissonant intervals
				pitchGap = abs(fluteArray[i] - clarArray[i][j])%12;
				if (pitchGap == 1 || pitchGap == 2 || pitchGap == 5 || 
					pitchGap == 6 || pitchGap == 10 || pitchGap == 11)
					clarArray[i][j] = 0;
			}

			// print numerical array, adjusted to range of instrument
			cout << fluteArray[i] << "        ";
			
			for (int j = 0; j < ROWLENGTH; j++){
				if(clarArray[i][j] == 0)
					cout << clarArray[i][j] << "   ";
				else
					cout << clarArray[i][j] << "  ";
			}
			
			cout << endl;

			// print musical array
			pitchClass = fluteArray[i]%12;
			octave = (fluteArray[i]/12) - 1;
			
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
			
			cout << "      ";

			for (int j = 0; j < ROWLENGTH; j++){
				if(clarArray[i][j] == 0)
					cout << "--  ";
				else{
					pitchClass = clarArray[i][j]%12;
					octave = (clarArray[i][j]/12)-1;

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
