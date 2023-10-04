#include <iostream>
#include <vector>

using namespace std;

// Structure to represent items
struct Item {
    int weight;
    int value;
};

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(vector<Item>& items, int capacity) {
    int numItems = items.size();
    vector<vector<int>> dp(numItems + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= numItems; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            }
        }
    }

    return dp[numItems][capacity];
}

int main() {
    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);

    for (int i = 0; i < numItems; ++i) {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    int maxValue = knapsack(items, capacity);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
