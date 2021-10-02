#include <iostream>
#include "tic_tac_toe.h"

using namespace std;

int main() {
   cout << "Enter a char :: ";
   char ch;
   cin >> ch;
   Game play(ch);
   play.choose();
}