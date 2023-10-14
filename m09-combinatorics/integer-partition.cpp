#include <iostream>
using namespace std;

int partition(int n, int k) {
  // Base cases
  if (n == 0) return 1;  // One way to partition 0 using no numbers
  if (n < 0 || k <= 0)
    return 1;  // No way to partition with negative number or no numbers left

  // Recursive cases
  // Include k in the partition and recursively partition n-k with k
  int include_k = partition(n - k, k);

  // Exclude k from the partition and recursively partition n with k-1
  int exclude_k = partition(n, k - 1);

  return include_k + exclude_k;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <positive_integer>" << endl;
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return EXIT_FAILURE;
    }

    cout << "Number of partitions of " << n << " is: " << partition(n, n) << endl;

    return EXIT_SUCCESS;
}
