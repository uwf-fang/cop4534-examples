#include <chrono>
#include <iostream>

void algorithm(int parameter) {
  // time consuming algorithm
}

int main() {
  // Start the clock
  auto start = std::chrono::high_resolution_clock::now();
  // Call the function to be measured
  algorithm(10000);
  // Stop the clock
  auto end = std::chrono::high_resolution_clock::now();
  // Calculate the duration
  std::chrono::duration<double> duration = end - start;
  // Print the duration in seconds
  std::cout << "Function took " << duration.count() << " seconds." << std::endl;
  return EXIT_SUCCESS;
}
