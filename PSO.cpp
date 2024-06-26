#include<bits/stdc++.h>
using namespace std;

const int populationSize = 3;  // Number of particles
const int dimN = 2;            // Number of dimensions
const int mxItr = 5;           // Maximum number of itrs
const double w = 0.9;          // Inertia weight
const double c1 = 1.5;         // correction coefficients
const double c2 = 1.5;         // correction coefficient

struct Particle {
    vector<double> x;          // Position vector
    vector<double> v;          // Velocity vector
    double fitness;            // Fitness value
    vector<double> bestx;      // Personal best position vector
};

double a, b, c, d, e, f, l, r;
double gbest;
vector<double> gbestX(dimN);

void input() {
    cout << "Enter the coefficients of the equation: in order x^2, y^2, xy, x, y, constant term " << endl;
    cin >> a >> b >> c >> d >> e >> f;
    cout << "enter the range of x and y in order l and r " << endl;
    cin >> l >> r;
}

double ObjF(const vector<double>& x) {
    // return (10 * (x[0] - 1) * (x[0] - 1)) + (20 * (x[1] - 2) * (x[1] - 2)) + 30 * (x[2] - 3) * (x[2] - 3);
    return a * x[0] * x[0] + b * x[1] * x[1] + c * x[0] * x[1] + d * x[0] + e * x[1] + f;
}

void init(vector<Particle>& particles) {
    for (int i = 0; i < populationSize; ++i) {
        Particle p;
        p.x.resize(dimN);
        p.v.resize(dimN);

        for (int j = 0; j < dimN; ++j) {
            // Initialize x and v randomly
            p.x[j] = ((double)rand() / RAND_MAX) * (r - l) + l;
            p.v[j] = ((double)rand() / RAND_MAX) * (r - l) + l;
        }

        // Initialize fitness
        p.fitness = ObjF(p.x);

        // Initialize personal best
        p.bestx = p.x;

        if (gbest < p.fitness) {
            gbestX = p.x;
            gbest = p.fitness;
        }
        particles.push_back(p);
    }
}

void upd(vector<Particle>& particles, vector<double>& gbestX, double& gbest) {
    for (int i = 0; i < populationSize; ++i) {
        for (int j = 0; j < dimN; ++j) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;

            // cout << "r1 = " << r1 << " " << "r2 = " << r2 << endl;

            particles[i].v[j] = w * particles[i].v[j] +
                c1 * r1 * (particles[i].bestx[j] - particles[i].x[j]) +
                c2 * r2 * (gbestX[j] - particles[i].x[j]);

            particles[i].x[j] += particles[i].v[j];

            if (particles[i].x[j] < l)
                particles[i].x[j] = l;
            
            else if (particles[i].x[j] > r)
                particles[i].x[j] = r;

        }

        double prevFitness = particles[i].fitness;
        particles[i].fitness = ObjF(particles[i].x);

        if (prevFitness < particles[i].fitness) {
            particles[i].bestx = particles[i].x;
        }

        if (particles[i].fitness > gbest) {
            gbestX = particles[i].bestx;
            gbest = particles[i].fitness;
        }
    }
}

void print(vector<Particle>& particles, int itr, vector<double>& gbestX) {
    cout << "---------------Iteration = " << itr << "--------------------------" << endl;
    cout << "Position Matrix of Particles(x)" << endl;
    for (int i = 0; i < populationSize; i++) {
        for (int j = 0; j < dimN; j++) {
            cout << particles[i].x[j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "Velocity Matrix of Particles(v)" << endl;

    for (int i = 0; i < populationSize; i++) {
        for (int j = 0; j < dimN; j++) {
            cout << particles[i].v[j] << " ";
        }
        cout << endl;
    }

    cout << "--------------------------------------------------" << endl;
    cout << "Fitness of Particles(f(x))" << endl;

    for (int i = 0; i < populationSize; i++) {
        cout << particles[i].fitness << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "Personal Best Position Matrix of Particles(pb_t)" << endl;

    for (int i = 0; i < populationSize; i++) {
        for (int j = 0; j < dimN; j++) {
            cout << particles[i].bestx[j] << " ";
        }
        cout << endl;
    }

    cout << "-------------------------------------------------" << endl;
    cout << "Global best position(gbestX)" << endl;

    for (int i = 0; i < dimN; i++)
        cout << gbestX[i] << " ";
    cout << endl;


    cout << "--------------------------------------------------" << endl;
    cout << "Global best fitness(gbest)" << endl;
    cout << gbest << endl;
    cout << "--------------------------------------------------" << endl;
    return;

}
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    input();


    vector<Particle> particles;
    gbest = -1e18;
    init(particles);

    double prev = -1e18;

    print(particles, 0, gbestX);

    for (int itr = 1; itr < mxItr; ++itr) {
        upd(particles, gbestX, gbest);
        print(particles, itr, gbestX);

        if (prev == gbest) {
            cout << "Converged" << endl;
            break;
        }

        prev = gbest;
    }

    cout << "--------------------Hence Our Solution is--------------" << endl;
    cout << "Optimal Solution:" << endl;
    cout << "Fitness: " << gbest << endl;
    cout << "x: ";

    for (int i = 0; i < dimN; ++i) {
        cout << gbestX[i] << " ";
    }

    cout << endl;
    return 0;
}


