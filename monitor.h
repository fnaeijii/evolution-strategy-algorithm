#pragma once
#include "SystemC.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>

SC_MODULE(monitor) {
    sc_in<int> output[9];
    sc_in<bool> EndAlgorithm;

    void print_result() {
        while (EndAlgorithm == false) {
            wait();
        }
       

        cout << "Result is: " << output[0]->read() << endl;
    }
    SC_CTOR(monitor) {
        SC_THREAD(print_result);
        sensitive << EndAlgorithm << output[8];

    }
};


