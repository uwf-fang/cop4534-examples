#include <iostream>
#include <vector>

using namespace std;

void generatePartitions(int n) {
  vector<vector<vector<int>>> partitions(n + 1);
  partitions[0].push_back(vector<int>(1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      for (vector<int> partition : partitions[j - i]) {
        partition.push_back(i);
        partitions[j].push_back(partition);
      }
    }
  }

  for (auto &partition : partitions.at(n)) {
    for (int i = 1; i < partition.size(); ++i) {
      cout << partition.at(i);
      if (i < partition.size() - 1) cout << " + ";
    }
    cout << " = " << n << endl;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <positive_integer>" << endl;
    return EXIT_SUCCESS;
  }

  int n = atoi(argv[1]);

  if (n <= 0) {
    cout << "Please enter a positive integer." << endl;
    return EXIT_FAILURE;
  }

  cout << "Partitions of " << n << " are:" << endl;
  generatePartitions(n);

  return EXIT_SUCCESS;
}
