// Number Guessing Game 

#include <iostream>
#include <random>
#include <limits>

using namespace std;

int main()
{
  // get new random number each run 
  random_device rd;
  // attempts counter 
  int attempts = 0;
  // user num
  int num; 

  // Computer gen number and assigns it to a variable (1 - 100)
  mt19937 gen(rd());  // Mersenne Twister PRNG
  uniform_int_distribution<int> dist(1, 100);  // Range 1-100
  short random = dist(gen);
  // while loop till number matched 
  do {
    // attempt counter 
    attempts++; 

    cout << "Guess a number between 1 and 100: "; 
    //cin >> num;  
    
    // check if int entered 
    while (!(cin >> num)) {
      cout << "Invalid input! Please enter an integer: ";
      cin.clear(); // Clears error flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // conditions to check if guess too big, small or correct 
    if (num < random) {
      cout << "Too small! Try again.\n"; 
    }
    else if (num > random) {
     cout << "Too big! Try again.\n"; 
    }
    else {
      cout << "You guessed it in " << attempts << " attempts." << endl;  
    } 
   }
  while (num != random);    

  return 0;
}




