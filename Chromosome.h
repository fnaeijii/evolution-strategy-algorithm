#pragma once
#include "systemc.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>


using namespace std;



SC_MODULE(Chromosome) {

	struct chromosome {
		float fitness;
		float weight;
		float gen[9];
	};

	sc_in<int>inputweight[9];
	sc_in<int>inputPrice[9];

	/*int inputweight[9] = { 2,3,6,7,5,9,3,4,5 };
	int inputPrice[9] = { 6,5,8,9,6,7,3,6,8 };*/

	std::vector<chromosome> population;

	int maxWeight = 40;
	chromosome output;

	sc_out<int> outputpercent[9];

	sc_out<bool> EndAlgorithm;


	int noChange = 0;
	float p = 0.8;
	
	void sortPop();//hw
	void updateFittness();//sw
	void crossover();//sw
	void mutation();//hw
	void repair();//hw
	bool checkCondition();//sw
	void deleteAddition();//sw
	float findWeight(chromosome c);//sw
	float calculateSD(float data[]);//hw
	float calculateN01();//hw

	void StartAlgorithm() {
		cout << "max is: " << maxWeight << endl;
		EndAlgorithm = 0;
		
		for (int j = 0; j < 6; j++) {
		
			for (int i = 0; i < 9; i++) {
				srand(time(0));
				population[j].gen[i] = (rand() % 11) / 10;
				cout << "ch is: " << population[j].gen[i] << endl;
			};
		};
		while (true) {

			updateFittness();
			sortPop();

			if (((rand() % 10) / 10) < p) {
				crossover();
				mutation();
				repair();
				sortPop();
			}
			else {
				continue;
			}

			deleteAddition();
			checkCondition();
			if (EndAlgorithm == 1) {
				wait(5, SC_NS);
				sc_stop();
				break;
			}

		}

		output = population[0];
		

		for (int i = 0; i < 9; i++) {

			outputpercent[i] = output.gen[i] * 100;
			cout << "Result is: " << outputpercent[i] << endl;
		}

       sc_stop();
	}

	SC_CTOR(Chromosome) {
		SC_THREAD(StartAlgorithm);
		sensitive << outputpercent[8];
	}
};