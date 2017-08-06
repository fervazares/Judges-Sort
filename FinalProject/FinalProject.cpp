/**
   Created By Fernando Vazquez Copyright 2016

   ACM North America Southern California Regionals 2014
   
   Your team has been retained by the director of a competition who supervises a panel of judges. The
   competition asks the judges to assign integer scores to competitors — the higher the score, the better.
   Although the event has standards for what score values mean, each judge is likely to interpret those
   standards differently. A score of 100, say, may mean different things to different judges.
   The director’s main objective is to determine which competitors should receive prizes for the top
   positions. Although absolute scores may differ from judge to judge, the director realizes that relative
   rankings provide the naeeded information — if two judges rank the same competitors first, second, third,
   . . . then they agree on who should receive the prizes.

   Your team is to write a program to assist the director by comparing the scores of pairs of judges.
   The program is to read two lists of integer scores in competitor order and determine the highest ranking
   place (first place being highest) at which the judges disagree.
   */

#include <iostream>

using namespace std;

/**
   Creates an object that holds two integers,
   the first being a score given by a judge and
   a second holding the position
*/
class Competitor
{
public:
	Competitor();
	int score;
	int competitor_number;
};

/**
   Default constructor that initializes variables
   score and competitor_number with 0
*/
Competitor::Competitor()
{
	score = 0;
	competitor_number = 0;
}

/**
   Swap function that swaps between two int 
   type integers given in an array
   @param arr an array holding elements
   @param i the first element
   @param j the element being swapped with
*/
void swap(Competitor arr[], int i, int j)
{
	Competitor temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
} 

/**
   Selection sort function that sorts from
   lowest to highest score
   @param arr array that needs to be sorted
   @param left is the beginning of the array
   @param right is the end of the array
*/
void csort(Competitor arr[], int left, int right)
{
	int i, last;


	if (left >= right)
		return;


	swap(arr, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (arr[i].score < arr[left].score)
			swap(arr, ++last, i);
	swap(arr, left, last);
	csort(arr, left, last - 1);
	csort(arr, last + 1, right);
}



int main()
{
	int number_of_competitors = 0;
	int cases = 1;

	cout << "Enter number of teams competing (-1 to quit): ";
	cin >> number_of_competitors;
	
	
	while (number_of_competitors != -1)   // Using while loop to stop the program from running if the user enters -1 during number_of_competitors
	{
		Competitor  *judge1 = new Competitor[number_of_competitors];   // Because we are creating an array of unkown size, we must use pointers
		Competitor  *judge2 = new Competitor[number_of_competitors];   

		int grade = 0;

		cout << "Enter scores from first judge: ";
		for (int i = 0; i < number_of_competitors; i++)   // Occupying elements into array judge1 with user input
		{
			cin >> grade;
			judge1[i].score = grade;
			judge1[i].competitor_number = i;
		}

		cout << "Enter scores from second judge: ";
		for (int i = 0; i < number_of_competitors; i++)   // Occupying elements into array judge2 with user input
		{
			cin >> grade;
			judge2[i].score = grade;
			judge2[i].competitor_number = i;
		}

		csort(judge1, 0, number_of_competitors - 1);   // Sorting elements in arrays from low to high scores
		csort(judge2, 0, number_of_competitors - 1);

		for (int index = 0; index < number_of_competitors; index++)		// Displays each judges scores sorted with a position number they were typed in
		{
			cout << "score: " << judge1[index].score << ' ' << "position: " << judge1[index].competitor_number << endl;
		}

		for (int index1 = 0; index1 < number_of_competitors; index1++)
		{
			cout << "score: " << judge2[index1].score << ' ' << "position: " << judge2[index1].competitor_number << endl;
		}

		int start = 0;
		bool more = true;
		//int cases = 1;
		while (more)   // Using while loop to determine if the comparison test continues or not
		{	
			if (judge1[start].competitor_number != judge2[start].competitor_number)   // Case 1, judges dont agree and testing is immidiately terminated
			{
				cout << "Case " << cases++ << ": Judges disagree at position " << start + 1 << endl;
				more = false;
			}

			else  if (start == number_of_competitors)   // Case 2, the test made it through all elements matching meaning judges agreed and testing is terminated
			{
				cout << "Case " << cases++ << ": agree" << endl;
				more = false;
			}

			else   // Looping through each element in each array until one of the two cases is met
			{
				start++;
			}
		}

		delete[] judge1;  // After we finish with the test we can delete our arrays to reallocate memory
		delete[] judge2;

		cout << "\nEnter number of teams competing (-1 to quit): ";
		cin >> number_of_competitors;   // And the process begins all over again unless the user enters -1
		
	}

	system("pause");
	return 0;
}