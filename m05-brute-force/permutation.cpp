#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void allPermutations(vector<int> &arr);
void allPermutationsHelper(vector<int> &arr, int start, int n);
void allPermutations1(vector<int> &arr);
void swap(vector<int> &arr, int i, int j);

// Function to swap two integers in a vector
void swap(vector<int> &arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void printVector(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void allPermutations(vector<int> &arr) {
  allPermutationsHelper(arr, 0, arr.size() -  1);
}

// Recursive function to generate permutations
void allPermutationsHelper(vector<int> &arr, int start, int n) {
  if (start == n - 1) {
    // Base case: we have a permutation, print it
    printVector(arr);
    return;
  }
  // Generate permutations by swapping elements
  for (int i = start; i < n; i++) {
    swap(arr, start, i);
    allPermutationsHelper(arr, start + 1, n);
    swap(arr, start, i);  // Undo the swap
  }
}

// Function to generate permutations using STL next_permutation function
void allPermutations1(std::vector<int>& vec) {
    // Sort the vector to ensure we start from the first permutation
    std::sort(vec.begin(), vec.end());

    // Print and generate permutations
    do {
        printVector(vec);
    } while (std::next_permutation(vec.begin(), vec.end()));
}

int main() {
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }

  cout << "Permutations of 1 to " << n << " integers:" << endl;
  cout << "Method 1:" << endl;
  allPermutations(arr);

  cout << "Method 2:" << endl;
  allPermutations1(arr);

  return 0;
}
