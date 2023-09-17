/**
 * @file ga-framework.cpp
 * @author your name (you@domain.com)
 * @brief A general framework for genetic algorithm
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

/**
 * @brief Genetic algorithm class
 * Assumptions:
 *
 *  - The population size is even
 *  - The fitness function is maximization and is double-typed
 *  - The fitness function is implemented in the evaluate() method
 *  - The individual is represented by a vector of integers
 */
class GeneticAlgorithm {
 public:
  GeneticAlgorithm(int populationSize, double mutationRate,
                   double crossoverRate);

  // Main loop to run the genetic algorithm
  // The stopping condition is the number of generations
  // You can also return best individual or fitness in this function
  void run(int generations);

  // Get the best individual from the population
  vector<int> getBestIndividual() const;

 private:
  // Population
  vector<vector<int>> population;
  vector<double> fitnesses;

  // Parameters
  int populationSize;
  double mutationRate;
  double crossoverRate;

  // Generate the initial population
  // Save the population in the population vector
  void initializePopulation();
  // Evaluate the fitness of an individual
  double evaluate(const vector<int>& individual);
  // Evaluate the fitness of each individual in the population
  void evaluatePopulation();
  // Select two parents from the population every time
  // Save the parents in parent1 and parent2
  void selectParents(vector<int>& parent1, vector<int>& parent2);
  // Crossover two parents to generate two offsprings
  // There are alternative ways to implement crossover like generating one
  //   every time
  vector<int> crossover(const vector<int>& parent1, const vector<int>& parent2,
                        vector<int>& offspring1, vector<int>& offspring2);
  // Mutate an individual
  void mutate(vector<int>& individual);

  // Random number generation
  mt19937 rng;  // Mersenne Twister random number generator
};

GeneticAlgorithm::GeneticAlgorithm(int populationSize, double mutationRate,
                                   double crossoverRate)
    : populationSize(populationSize),
      mutationRate(mutationRate),
      crossoverRate(crossoverRate),
      rng(random_device{}()) {}

void GeneticAlgorithm::initializePopulation() {
  population.clear();
  for (int i = 0; i < populationSize; ++i) {
    vector<int> individual;
    // Initialize individual here
    population.push_back(individual);
  }
}

void GeneticAlgorithm::run(int generations) {
  for (int gen = 0; gen < generations; ++gen) {
    evaluatePopulation();

    vector<vector<int>> newPopulation;

    for (int i = 0; i < populationSize / 2; ++i) {
      vector<int> parent1, parent2;
      selectParents(parent1, parent2);

      if (uniform_real_distribution<>(0.0, 1.0)(rng) < crossoverRate) {
        vector<int> offspring1, offspring2;
        crossover(parent1, parent2, offspring1, offspring2);

        mutate(offspring1);  // Apply mutation to the offspring
        mutate(offspring2);  // Apply mutation to the offspring

        newPopulation.push_back(offspring1);
        newPopulation.push_back(offspring2);
      } else {
        // No crossover
        newPopulation.push_back(parent1);
        newPopulation.push_back(parent2);
      }
    }

    // Replace the old population with the new population entirely
    // Alternative ways include replacing the worst individuals or replacing
    //   randomly
    population = newPopulation;
  }
}

double GeneticAlgorithm::evaluate(const vector<int>& individual) {
  // Implement the fitness evaluation logic here
  // For example:
  // double fitness = ...;
  // return fitness;
  return 0.0;  // Placeholder
}

void GeneticAlgorithm::evaluatePopulation() {
  fitnesses.clear();
  for (const auto& individual : population) {
    fitnesses.push_back(evaluate(individual));
  }
}

void GeneticAlgorithm::selectParents(vector<int>& parent1,
                                     vector<int>& parent2) {
  // Implement a selection method here, e.g., tournament selection, roulette
  // wheel selection, etc.
}

vector<int> GeneticAlgorithm::crossover(const vector<int>& parent1,
                                        const vector<int>& parent2,
                                        vector<int>& offspring1,
                                        vector<int>& offspring2) {
  // Implement crossover logic here
}

void GeneticAlgorithm::mutate(vector<int>& individual) {
  for (int& gene : individual) {
    if (uniform_real_distribution<>(0.0, 1.0)(rng) < mutationRate) {
      // Apply mutation to the gene
    }
  }
}

vector<int> GeneticAlgorithm::getBestIndividual() const {
  double maxFitness = fitnesses[0];
  int bestIndex = 0;

  for (int i = 1; i < fitnesses.size(); ++i) {
    if (fitnesses[i] > maxFitness) {
      maxFitness = fitnesses[i];
      bestIndex = i;
    }
  }

  return population[bestIndex];
}
