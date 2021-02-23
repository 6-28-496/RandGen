// February 24, 2015 -- RandGen3
// Program to generate random numbers for different pitch classes
// Creates motifs based on randomised note values

#include <iostream>
#include <math.h>

using namespace std;


void main(){
	const int ROWTOTAL = 8;
	const int ROWLENGTH = 12;
	const int CLARBASE = 83;
	const int CLARRANGE = 9;
	const int FLUTEBASE = 92;
	const int FLUTERANGE = 5;
	
	int noteArray[ROWTOTAL][ROWLENGTH];
	int testRand, seed, noteLength, notePitch, notePosition, pitchClass, octave;
	bool intIsNew, goAgain;
	char userChoice;

	do{
		goAgain = false;

		cout << "Enter a seed number:";
		cin >> seed;

		for (int i = 0; i < seed; i++)
			testRand = rand(); 

		cout << endl << "Clarinet                                 Flute" << endl;

		for (int i = 0; i < ROWTOTAL; i++){
			notePosition = 0;
			
			// set the row to 0
			for (int j = 0; j < ROWLENGTH; j++)
				noteArray[i][j] = 0;

			// set the first note
			noteLength = (rand() % 3) + 1;
			notePitch = (rand() % 5) + CLARBASE;

			for (int j = 0; j < noteLength; j++)
				noteArray[i][j] = notePitch;

			notePosition += noteLength;

			// set the second note
			noteLength = (rand() % 3) + 1;
			notePitch = (rand() % 4) + CLARBASE + 5;
			
			for (int j = notePosition; j < noteLength+notePosition; j++)
				noteArray[i][j] = notePitch;

			notePosition += noteLength;

			// set the third note
			noteLength = (rand() % 3) + 1;
			notePitch = FLUTEBASE + FLUTERANGE - (1 + (rand() % 2));

			for (int j = notePosition; j < noteLength+notePosition; j++)
				noteArray[i][j] = notePitch;

			notePosition += noteLength;

			// set the fourth note
			noteLength = (rand() % 3) + 1;
			notePitch = FLUTEBASE + FLUTERANGE - (3 + (rand() % 3));

			for (int j = notePosition; j < noteLength+notePosition; j++)
				noteArray[i][j] = notePitch;

			for (int j = 0; j < ROWLENGTH; j++){
				if(noteArray[i][j] == 0)
					cout << noteArray[i][j] << "   ";
				else
					cout << noteArray[i][j] << "  ";
			}
			
			cout << endl;

			// print musical array
			
			for (int j = 0; j < ROWLENGTH; j++){
				if(noteArray[i][j] == 0)
					cout << "--  ";
				else{
					pitchClass = noteArray[i][j]%12;
					octave = (noteArray[i][j]/12)-1;

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
