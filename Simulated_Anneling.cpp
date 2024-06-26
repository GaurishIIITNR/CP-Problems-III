// #include <bits/stdc++.h>
// #include <random>
// using namespace std;

// double genRandom(double a, double b) {
//     random_device rd;
//     default_random_engine gen(rd());
//     uniform_real_distribution<double> v(a + 0.00001, b - 0.00001);

//     double randv = v(gen);
//     return randv;
// }

// class objFunc {
//     public:
//     double a, b, c, d, e, f;

//     objFunc() {
//         cout << "Enter the cofficient of x1^2: "; cin >> a;
//         cout << "Enter the cofficient of x2^2: "; cin >> b;
//         cout << "Enter the cofficient of x1x2: "; cin >> c;
//         cout << "Enter the cofficient of x1: "; cin >> d;
//         cout << "Enter the cofficient of x2: "; cin >> e;
//         cout << "Enter the cofficient of constant: "; cin >> f;
//     }

//     double value(double x1, double x2) {
//         return (a * x1 * x1) + (b * x2 * x2) + (c * x1 * x2) + (d * x1) + (e * x2) + f;
//     }
// };

// class cnstrn {
//     public:
//     double x1min, x1max, x2min, x2max;

//     cnstrn() {
//         cout << "Enter the min value of constraint x1: "; cin >> x1min;
//         cout << "Enter the max value of constraint x1: "; cin >> x1max;
//         cout << "Enter the min value of constraint x2: "; cin >> x2min;
//         cout << "Enter the max value of constraint x2: "; cin >> x2max;
//     }
// };

// bool accept(double deltaE, double T) {
//     if (deltaE < 0) {
//         return true;
//     }

//     double p = exp(-deltaE / T);
//     double r = genRandom(0, 1);
//     return (r < p);
// }

// int main() {
//     cout << endl;

//     // input objective function of two variable x1,x2
//     // f(x1, x2) = ax1^2 + bx2^2 + cx1x2 + dx1 + ex2 + f;

//     // Input ------------------------------------------------------
//     cout << "-------------Input of the Objective Function----------- " << endl;
//     objFunc obj;
//     cout << endl;

//     //  input of constraints range  a1 <= x1 <= b1,  a2 <= x2 <= b2
//     cout << "----------------Input of the Constraints-------------- " << endl;
//     cnstrn cnst;
//     cout << endl;

//     // Step -1 :   Initialization of parameters--------------------
//     // taking the of initial temperature 
//     cout << "----------------------Initialization------------- " << endl;
//     double Tmax, T;  Tmax = T = 100;
//     cout << "Intial random value of T_intial is: " << T0 << endl;

//     // taking random intial value of X = { x1, x2 }
//     double x1_t, x2_t;
//     x1_t = 4;
//     x2_t = 4;

//     cout << "Intial random value of x1_t is: " << x1_t << endl;
//     cout << "Intial random value of x2_t is: " << x2_t << endl;

//     // taking iteration number itr = 0;
//     int itr = 1;
//     double epsilon = 0.0001;

//     // Step - 2 : Generate a neighbour candidate solution-----------
//    // X = Xmin + random(0, 1) * (Xmax - Xmin)  
//     // double x1, x2, r1, r2;
//     // r1 = 0.84;
//     // r2 = 0.84;
//     // cout << "Intial random value of r1 is: " << r1 << endl;
//     // cout << "Intial random value of r2 is: " << r2 << endl;

//     // x1 = cnst.x1min + r1 * (cnst.x1max - cnst.x1min);
//     // x2 = cnst.x2min + r2 * (cnst.x2max - cnst.x2min);

//     // cout << "value of x1_t+1 : " << x1 << endl;
//     // cout << "value of x2_t+1: " << x2 << endl << endl;
//     double Ex1;
//     Ex1 = obj.value(x1_t, x2_t);

//     while (T > T0 && itr <100 && abs(deltaE) > epsilon) {

//         cout << "---------------------Iteration number: " << itr << " --------------" << endl;
//         // taking Ti = 0.5 T(i-1)
//         T0 = 0.5 * T0;
//         cout << "Value of Ti is: " << T0 << endl;

//         // Step - 3 : Calculate the objective function value of X and X'
//         Ex2 = obj.value(x1, x2);
//         Ex1 = obj.value(x1_t, x2_t);

//         cout << "Value of objective function of E(x_t) is: " << Ex1 << endl;
//         cout << "Value of objective function of E(x_t+1) is: " << Ex2 << endl;

//         // Step - 4 : Calculate the difference of objective function value
//         double deltaE = Ex2 - Ex1;
//         cout << "Value of deltaE is: " << deltaE << endl;

//         if (abs(deltaE) < epsilon) {
//             cout << "value of deltaE is less than epsilon " << endl << endl;

//             cout << "--------------------------Answer-------------------------------" << endl << endl;
//             cout << "The minimum value of the objective function is: " << Ex2 << endl;
//             cout << "The value of x1 is: " << x1 << endl;
//             cout << "The value of x2 is: " << x2 << endl;
//             cout << "Min value of T is: " << T0 << endl;
//             break;
//         }

//         if (deltaE < 0) {

//             cout << "deltaE is less than 0" << endl;

//             x1_t = x1;
//             x2_t = x2;
//             r1 = genRandom(0, 1);
//             r2 = genRandom(0, 1);
//             x1 = cnst.x1min + r1 * (cnst.x1max - cnst.x1min);
//             x2 = cnst.x2min + r2 * (cnst.x2max - cnst.x2min);

//             cout << "New value of x1_t is: " << x1_t << endl;
//             cout << "New value of x2_t is: " << x2_t << endl;
//             cout << "New value of x1_t+1 is: " << x1 << endl;
//             cout << "New value of x2_t+1 is: " << x2 << endl;

//         }
//         else {
//             cout << "deltaE is greater than 0" << endl;

//             double p = exp(-deltaE / T0);
//             cout << "Value of Boltman Const: " << p << endl;

//             r1 = genRandom(0, p);
//             r2 = genRandom(0, p);

//             cout << "r1 = " << r1 << " is less than p -- accepted" << endl;
//             cout << "r2 = " << r2 << " is less than p -- accepted" << endl;

//             x1_t = x1; x2_t = x2;
//             x1 = cnst.x1min + r1 * (cnst.x1max - cnst.x1min);
//             x2 = cnst.x2min + r2 * (cnst.x2max - cnst.x2min);

//             cout << "New value of x1_t is: " << x1_t << endl;
//             cout << "New value of x2_t is: " << x2_t << endl;
//             cout << "New value of x1_t+1 is: " << x1 << endl;
//             cout << "New value of x2_t+1 is: " << x2 << endl;

//         }
//         cout << "-----------------------------------------------------------" << endl << endl;
//         itr++;
//     }

//     cout << endl;
//     cout << "-----------------------------------------------------------" << endl << endl;
//     cout << "--------------------------Thank You for using !!----------------------" << endl;
//     cout << "---- ---------------Created by Gaurish Ojha (211020418)----------------" << endl;
//     cout << "---------------In Supervision of Dr. Chandra Shekhar Nishad---------------" << endl;
//     cout << "------Assistant Professor, Dept. of Science & Mathematics, IIIT Naya Raipur--" << endl;
//     cout << endl;
// }




#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

double genRandom(double a, double b) {
    random_device rd;
    default_random_engine gen(rd());
    uniform_real_distribution<double> v(a + 0.00001, b - 0.00001);

    double randv = v(gen);
    return randv;
}

class objFunc {
    public:
    double a, b, c, d, e, f;

    objFunc() {
        cout << "Enter the cofficient of x1^2: "; cin >> a;
        cout << "Enter the cofficient of x2^2: "; cin >> b;
        cout << "Enter the cofficient of x1x2: "; cin >> c;
        cout << "Enter the cofficient of x1: "; cin >> d;
        cout << "Enter the cofficient of x2: "; cin >> e;
        cout << "Enter the cofficient of constant: "; cin >> f;
    }

    double value(double x1, double x2) {
        return (a * x1 * x1) + (b * x2 * x2) + (c * x1 * x2) + (d * x1) + (e * x2) + f;
    }
};

class cnstrn {
    public:
    double x1min, x1max, x2min, x2max;

    cnstrn() {
        cout << "Enter the min value of constraint x1: "; cin >> x1min;
        cout << "Enter the max value of constraint x1: "; cin >> x1max;
        cout << "Enter the min value of constraint x2: "; cin >> x2min;
        cout << "Enter the max value of constraint x2: "; cin >> x2max;
    }
};

bool accept(double deltaE, double T) {
    if (deltaE < 0) {
        cout << "deltaE is less than 0" << endl;
        return true;
    }

    double p = exp((-1 * deltaE) / T);
    double r = genRandom(0, 1);

    cout << "Value of Boltman Const: " << p << endl;
    cout << "Value of random r: " << r << endl;

    return (r < p) ? true : false;
}

void simulatedAnnealing(double Tmax, double Tmin, double rate, double epsilon) {

    objFunc obj;
    cnstrn cnst;

    // Initialize
    cout << endl;
    cout << " -----------------Step 1 Initialization----------------- " << endl;
    double T = Tmax;
    cout << "Initial Temperature: " << Tmax << endl;

    vector<double> x = { 4, 4 };
    cout << "Initial Solution [x1_in, x2_in]: [" << x[0] << ", " << x[1] << "]" << endl;

    double E = obj.value(x[0], x[1]);
    cout << "Initial E(x) value using intial solution [x1_in, x2_in]: " << E << endl;

    int itr = 1;
    while (T > Tmin) {
        cout << "-----------------Iteration " << itr << "----------------- " << endl;

        // Generate a new candidate solution
        vector<double> xNew = {
            genRandom(cnst.x1min, cnst.x1max), genRandom(cnst.x2min, cnst.x2max)
        };
        cout << "New Solution [x1_new, x2_new]: [" << xNew[0] << ", " << xNew[1] << "]" << endl;

        // Compute the value of the new candidate
        double ENew = obj.value(xNew[0], xNew[1]);
        cout << "New E(x) value : " << ENew << endl;

        // Calculate the change in energy
        double deltaE = ENew - E;
        cout << "Change in E(x) value or deltaE: " << deltaE << endl;

        if (abs(deltaE) < epsilon) break;

        // Accept the new solution with a certain probability
        if (accept(deltaE, T)) {
            cout << "solution is accepted" << endl;
            x = xNew;
            E = ENew;
            cout << "New Solution [x1_new, x2_new]: [" << x[0] << ", " << x[1] << "]" << endl;
            cout << "New E(x) value : " << E << endl;
        }
        else {
            cout << "solution is rejected" << endl;
        }

        // Cool the temperature
        T *= 0.95;
        cout << "New Temperature: " << T << endl << endl;
        itr++;
    }

    cout << "---------------Final Result -----------" << endl;
    cout << "Final Solution [x1, x2]: [" << x[0] << ", " << x[1] << "]" << endl;
    cout << "Final E(x) value : " << E << endl;
    cout << "Final Temperature: " << T << endl << endl;
    cout << "-----------------------------------------------" << endl;

    return;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    double Tmax = 100.0;
    double Tmin = 1e-7;
    double rate = 0.84;
    double epsilon = 1e-5;

    simulatedAnnealing(Tmax, Tmin, rate, epsilon);
    return 0;
}
