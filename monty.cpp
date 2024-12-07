#include <iostream>
#include <ctime>
#include <limits>
using namespace std;
  
bool simulateMonty() {
  bool doors[3] = {0, 0, 0}; 
  bool shadow_doors[3] = {1, 1, 1}; // Will use to pick the NOT door
  int pick;
  

  int cash_door = rand() % 3;
  doors[cash_door] = 1;

  pick = rand() % 3;

  shadow_doors[pick] = 0;

  //cout << "So far, it has chosen " << pick << "." << endl;

  // Reveal the false door and switch to the other possible one
  for (int i = 0; i < 3; ++i) {
    if (i != pick && !doors[i]) { 
      shadow_doors[i] = 0; 
      break;
    }
  }

  for (int j = 0; j < 3; ++j) {
    //cout << shadow_doors[j] << ", ";
    if (shadow_doors[j])
      pick = j;
  }
  //cout << "Shadow Doors" << endl;


  //cout << "The correct door is on " << cash_door << ", and it chose " << pick << "." << endl;

  return doors[pick];
}

int main (int argc, char *argv[]) {
  srand(time(0));
  const int MAX_SIZE = 8;
  int input;

  cout << "Enter # of simulations: ";

  while (!(cin >> input)) {
    cout << "Invalid input. Please enter an integer: ";
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int wins;
  float percentage;

  for (int i = 0; i < input; i++) {
    //cout << endl << "=-=-=-=-=-=-=-=-=" << endl << endl;
    if (simulateMonty()) {
      wins ++;
    } 
  }

  percentage = static_cast<float>(wins) / input;

  cout << endl << "=-=-=-=-=-=-=-=-=" << endl << endl;

  cout << wins << " wins out of "<< input << " trials." << endl;
  cout << "Percentage of wins: " << percentage << endl;

  return 0;
}
