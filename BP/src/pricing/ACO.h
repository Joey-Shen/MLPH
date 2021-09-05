#ifndef ACO_H
#define ACO_H

#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>      // iota
#include <vector>
#include <cstring>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <iomanip>
#include <set>
#include "pricer.h"

namespace GCP{
    using namespace std;

    class ACO: public Pricer{

        double T = 1.;
        double alpha = 1;
        double beta = 0.05;
        double rho = 1.;
        double delta_rho=0.0002;
        double gamma = 0.5;
        double best_obj=0.;
        double bound_sum;
        int niterations;
        vector<double> bound;
        
        vector<vector<int>> mis_set;
        const vector<vector<bool>> adj_matrix;
        const vector<double> degree_norm;
        vector<double> tau;
        public:
            int sample_size;
            double start_time;
            double max_dual;
            set<string> identites;
            double random_sampling_time;
            vector<double> objs;

        void compute_bound();
            // Builds a solver for graph g.
        ACO(double _cutoff, MWISP_INST& inst);
            void run_iteration(int ith_iteration);
            void run() override;
    };
}

#endif
