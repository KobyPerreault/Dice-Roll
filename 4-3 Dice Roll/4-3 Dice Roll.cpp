/*
	Koby Perreault
	IT 312
	4-3 Final Project Building Block One: Programming (Rolling Dice)

	This program rolls two dice and asks the user to input a number between 2 and 12. 
	It then rolls the dice by using a random function to generate a random number representing one of the sides for each die. 
	The result of each die and the combined total of the two sides is outputted. 
	It continues rolling the dice until the total equals what the user entered. 
	Finally it outputs the number of tries it took.
*/

#include<iostream>
#include<time.h>
#include<ctime>

using namespace std;

int dieRoll(int die);

int main() 
{
	//Initilize Variables
	int userNum=0;
	int dieOne=0;
	int dieTwo=0;
	int sum;
	int tries = 1;

	//Makes sure that the number the user entered is between 2 and 12
	while (userNum < 2 || userNum > 12)
	{
		cout << "Plese Enter a number between 2 and 12 : ";
		cin >> userNum;
	}

	srand(time(NULL));

	//Call the dieRoll function for both dice
	dieOne = dieRoll(dieOne);
	dieTwo = dieRoll(dieTwo);

	sum = dieOne + dieTwo;

	//Output the results
	cout << endl << "Die 1: " << dieOne << endl;
	cout << "Die 2: " << dieTwo << endl;
	cout << "Sum: " << sum << endl << endl;

	//If the sum is not equal to the users number, the loop will reroll the dice until they are equal
	while (sum != userNum)
	{
		dieOne = dieRoll(dieOne);
		dieTwo = dieRoll(dieTwo);

		sum = dieOne + dieTwo;

		cout << "Die 1: " << dieOne << endl;
		cout << "Die 2: " << dieTwo << endl;
		cout << "Sum: " << sum << endl << endl;
		tries++; //Incriments the value of tries by one everytime the loop is itirated
	}
	
	cout << "Number of tries: " << tries <<endl;

	return 0;
}


//This function is used to give the dice a random number
int dieRoll(int die)
{
	die = rand() % 6 + 1;
	return die;
}