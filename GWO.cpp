#include<bits/stdc++.h>
using namespace std;

// Define the objective function (modify according to your problem)

double a, b, c, d, e, f, l, r;

void input() {
    cout << "Enter the coefficients of the equation: in order x^2, y^2, xy, x, y, constant term " << endl;
    cin >> a >> b >> c >> d >> e >> f;
    cout << "enter the range of x and y in order l and r " << endl;
    cin >> l >> r;
}

double objF(vector<double>& x) {
    return a * x[0] * x[0] + b * x[1] * x[1] + c * x[0] * x[1] + d * x[0] + e * x[1] + f;
}

// Define a wolf structure
struct Wolf {
    vector<double> x;    // Current position of the wolf
    double fx;           // function value
};

// Grey Wolf Optimization class
class GreyWolfOptimization {
    public:
    int populationSize; // Number of wolves in the population
    int dim;            // dimension of the problem
    int mxIter;         // Maximum number of iterations
    double l;           // Lower bound of the search space
    double r;           // Upper bound of the search space
    double a, A, C;     // Parameters of the GWO algorithm

    vector<Wolf> wolves; // Population of wolves

    // Constructor
    GreyWolfOptimization(int popSize, int dim, int iterations, double lower, double upper)
        : populationSize(popSize), dim(dim), mxIter(iterations), l(lower), r(upper) {
        a = 2.0;      // Parameter a
        A = 2.0 * a;  // Parameter A
        C = 2.0;      // Parameter C
    }

    // Initialize the population
    void initialize() {
        wolves.resize(populationSize);
        for (int i = 0; i < populationSize; ++i) {
            wolves[i].x.resize(dim);
            for (int j = 0; j < dim; ++j) {
                wolves[i].x[j] = l + ((double)rand() / RAND_MAX) * (r - l);
            }
            wolves[i].fx = objF(wolves[i].x);
        }
    }

    // Update the x of a wolf based on another wolf
    vector<double> updatex(const vector<double>& current, const vector<double>& other, double C1, double C2) {
        vector<double> newx(dim);
        for (int i = 0; i < dim; ++i) {
            newx[i] = current[i] - C1 * (fabs(A * rand() / RAND_MAX * other[i] - current[i])) -
                C2 * (fabs(A * rand() / RAND_MAX * other[i] - current[i]));
            // Ensure the new x is within bounds
            newx[i] = max(l, min(newx[i], r));
        }
        return newx;
    }

    // Update the x of a wolf based on the xs of two other wolves
    void updateWolfx(Wolf& currentWolf, const Wolf& alpha, const Wolf& beta, const Wolf& delta) {
        double C1 = 2 * rand() / RAND_MAX; // Random value between 0 and 2
        double C2 = 2 * rand() / RAND_MAX; // Random value between 0 and 2

        vector<double> updatedx = updatex(alpha.x, currentWolf.x, C1, C2);
        updatedx = updatex(beta.x, updatedx, C1, C2);
        updatedx = updatex(delta.x, updatedx, C1, C2);

        currentWolf.x = updatedx;
        currentWolf.fx = objF(updatedx);
    }

    // Perform the optimization
    void optimize() {
        initialize();

        for (int iteration = 0; iteration < mxIter; ++iteration) {
            // Find the alpha, beta, and delta wolves
            int alphaIndex = 0;
            int betaIndex = 0;
            int deltaIndex = 0;

            for (int i = 1; i < populationSize; ++i) {
                if (wolves[i].fx < wolves[alphaIndex].fx) {
                    deltaIndex = betaIndex;
                    betaIndex = alphaIndex;
                    alphaIndex = i;
                }
                else if (wolves[i].fx < wolves[betaIndex].fx) {
                    deltaIndex = betaIndex;
                    betaIndex = i;
                }
                else if (wolves[i].fx < wolves[deltaIndex].fx) {
                    deltaIndex = i;
                }
            }

            // Update the xs of all wolves
            for (int i = 0; i < populationSize; ++i) {
                if (i != alphaIndex && i != betaIndex && i != deltaIndex) {
                    updateWolfx(wolves[i], wolves[alphaIndex], wolves[betaIndex], wolves[deltaIndex]);
                }
            }

            // Print the best fx value in this iteration
            cout << "Iteration " << iteration + 1 << ": Best fx = " << wolves[alphaIndex].fx << endl;
        }

        // Print the final result
        int bestIndex = 0;
        for (int i = 1; i < populationSize; ++i) {
            if (wolves[i].fx < wolves[bestIndex].fx) {
                bestIndex = i;
            }
        }

        cout << "Optimization finished. Best fx = " << wolves[bestIndex].fx << endl;
        cout << "Best Solution: ";
        for (int i = 0; i < dim; ++i) {
            cout << wolves[bestIndex].x[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Set the parameters
    int populationSize = 20;
    int dim = 5;
    int mxIter = 100;
    double l = -10.0;
    double r = 10.0;

    // Create and run the Grey Wolf Optimization algorithm
    GreyWolfOptimization gwo(populationSize, dim, mxIter, l, r);
    gwo.optimize();

    return 0;
}
