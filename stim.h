#pragma once
#include "systemc.h"

SC_MODULE(stim) {
	sc_out<int>inputweight[9];
	sc_out<int>inputPrice[9];
	sc_in<bool> end;

	void knapsack() {
		if (end == 1) {
			inputweight[0] = 2;
			inputweight[1] = 3;
			inputweight[2] = 6;
			inputweight[3] = 7;
			inputweight[4] = 5;
			inputweight[5] = 9;
			inputweight[6] = 3;
			inputweight[7] = 4;
			inputweight[8] = 5;

			inputPrice[0] = 6;
			inputPrice[1] = 5;
			inputPrice[2] = 8;
			inputPrice[3] = 9;
			inputPrice[4] = 6;
			inputPrice[5] = 7;
			inputPrice[6] = 3;
			inputPrice[7] = 6;
			inputPrice[8] = 8;
          }

		sc_stop();
	}
	SC_CTOR(stim) {
		SC_METHOD(knapsack);
		sensitive << end;
	}
};