#pragma once
#include "Chromosome.h"
#include <cmath>
#include <random>

void Chromosome::sortPop() {

    chromosome temp;

    for (int i = 0; i < population.size() - 1; i++) {

        for (int j = 0; j < population.size() - i - 1; j++) {

            if (population[j].fitness > population[j + 1].fitness) {
                temp = population[j];
                population[j] = population[j + 1];
                population[j + 1] = temp;
            }
        }
    }

}

void Chromosome::mutation() {
    float SDchromo;
    double RandN;

    for (int i = 7; i < 9; i++) {
        SDchromo = calculateSD(population[i].gen);
        RandN = calculateN01();

        for (int j = 0; j < 9; j++) {

            population[i + 2].gen[j] = population[i].gen[j] + ((SDchromo * exp(calculateN01() - RandN)) * calculateN01());
        }

    }
}


float calculateSD(float data[]) {
    float sum = 0.0, mean, standardDeviation = 0.0;
    int i;

    for (i = 0; i < 9; ++i) {
        sum += data[i];
    }

    mean = sum / 9;

    for (i = 0; i < 9; ++i) {
        standardDeviation += pow(data[i] - mean, 2);
    }

    return sqrt(standardDeviation / 9);
}


float calculateN01() {

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(/*mean=*/0.0, /*stddev=*/1.0);

    double randomNumber = distribution(generator);

}


void Chromosome::repair() {
    srand(time(0));
    for (int i = 0; i < population.size(); i++) {
        for (int j = 0; j < 9; j++) {
            if (population[i].gen[j] < 0 || population[i].gen[j] > 1) {
                population[i].gen[j] = (rand() % 11) / 10;
            }
        }

        while (findWeight(population[i]) > maxWeight) {
            for (int j = 0; j < 9; j++) {
                if (population[i].gen[j] > 0.1) {
                    population[i].gen[j] -= 0.1;
                }
            }
        }
    }
}


float Chromosome::findWeight(chromosome chromo) {
    float chrom_weight = 0;
    for (int j = 0; j < 9; j++) {
        chrom_weight += (chromo.gen[j] * inputweight[j]);
    }
    return chrom_weight;
}