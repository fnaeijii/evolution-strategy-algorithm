#pragma once
#include "Chromosome.h"

void Chromosome::updateFittness() {
    for (int j = 0; j < population.size(); j++) {
        float fitt = 0;
        for (int i = 0; i < 9; i++) {
            fitt += (inputweight[i] / inputPrice[i]) * population[j].gen[i];
        }
        population[j].fitness = fitt;
    }
}



void Chromosome::crossover() {

    int position = (rand() % 8) + 1;

    if ((rand() % 10) / 10) {

        for (int i = 0; i < position; i++) {
            population[7].gen[i] = population[0].gen[i];
            population[8].gen[i] = population[1].gen[i];
        }
        for (int i = position; i < 9; i++) {
            population[7].gen[i] = population[0].gen[i];
            population[8].gen[i] = population[1].gen[i];
        }

    }

}



bool Chromosome::checkCondition() {

    float value = population[0].fitness;
    if (value > output.fitness) {
        output.fitness = value;
        noChange = 1;
    }
    else if (value == output.fitness) {
        noChange += 1;
    }
    if (noChange == 5) {
        return true;
    }
    else {
        return false;
    }
}


void Chromosome::choiceBestOutput() {
    output = population[0];
}


void Chromosome::deleteAddition() {

    while (population.size() != 6) {

        population.pop_back();
    }

}
