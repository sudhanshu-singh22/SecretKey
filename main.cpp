#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

// Type alias
using Share = pair<double, double>;

// Function to parse input string into shares
vector<Share> parseShares(const string& input) {
    vector<Share> shares;
    istringstream iss(input);
    string token;

    while (iss >> token) {
        size_t commaPos = token.find(',');
        if (commaPos == string::npos) {
            throw invalid_argument("invalid number in input: " + token);
        }
        double x = stod(token.substr(0, commaPos));
        double y = stod(token.substr(commaPos + 1));
        shares.emplace_back(x, y);
    }

    return shares;
}

// Function to calculate secret using Lagrange Interpolation
double lagrangeInterpolation(const vector<Share>& shares) {
    double secret = 0.0;
    int n = shares.size();

    cout << "\n--- Lagrange Interpolation Steps ---\n";

    for (int i = 0; i < n; ++i) {
        double xi = shares[i].first;
        double yi = shares[i].second;
        double term = yi;

        cout << "Term " << i + 1 << ": ";
        cout << "y = " << yi << " * ";

        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double xj = shares[j].first;
                term *= (0 - xj) / (xi - xj); // Evaluate at x = 0
                cout << "((0 - " << xj << ") / (" << xi << " - " << xj << ")) * ";
            }
        }

        cout << "\b\b \n"; // remove last '*'

        cout << "Term Value: " << term << "\n";
        secret += term;
    }

    cout << "Final Sum (Secret): " << secret << endl;
    return secret;
}

int main() {
    cout << "Enter shares (format: x1,y1 x2,y2 ...): ";
    string input;
    getline(cin, input);

    try {
        vector<Share> shares = parseShares(input);
        cout << "\nParsed Shares:\n";
        for (auto [x, y] : shares) {
            cout << "(" << x << ", " << y << ")\n";
        }

        double secret = lagrangeInterpolation(shares);
        cout << "\nRecovered Secret: " << round(secret) << "\n"; // round off to nearest int

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
