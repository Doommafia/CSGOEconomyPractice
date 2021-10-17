#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

int genBars() {
	return rand() % 4 + 1;
}

int genMoney() {
	return rand() % 2000 + 50;
}

string genSide() {
	int r = rand() % 2;

	if (r == 0) return "T";
	else return "CT";
}

int rightAnswer(int lossBonus, int currentMoney, string side) {
	int lossBonusActual = lossBonus * 500 + 1000;
	if (side != "CT") {
		if (lossBonusActual + currentMoney < 3750) {
			return 2;
		}return 1;
	}
	else {
		if (lossBonusActual + currentMoney < 3700) {
			return 2;
		}return 1;
	}
}

int main() {
	int difficulty;
	cout << "Input the desired difficulty 1) Easy 2) Standard\n";
	cin >> difficulty;
	srand (time(0));
	while (true) {
		int money = genMoney(), bars = genBars(), playerAnswer;
		string side = genSide();
		cout << "Loss Reward: ";
		for (int i = 0; i < bars; i++) {
			cout << "[]";
		}
		if (difficulty == 1) cout << " - $" << bars * 500 + 1000;
		cout <<  " Current Money : $" << money<< " Side: "<< side << "\n";
		cout << "Should you buy? 1 / 2\n";
		cin >> playerAnswer;
		if (playerAnswer != rightAnswer(bars, money, side)) cout << "Wrong!\n";
		else  cout << "Pog!\n";
	}
}