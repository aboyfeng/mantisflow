#pragma once

#include "mesh.hpp"
#include "types.hpp"

namespace mantis {

/**
 * @brief Configuration for the solver
 */
struct SolverConfig {
    Real dt = 0.001;           // Time step
    Real endTime = 1.0;        // End time
    Real tolerance = 1e-6;     // Convergence tolerance
    Index maxIterations = 1000; // Max iterations per time step
    
    // Physical properties
    Real density = 1.0;        // Fluid density
    Real viscosity = 0.001;    // Dynamic viscosity
};

/**
 * @brief Base solver class for CFD simulations
 */
class Solver {
public:
    explicit Solver(const Mesh& mesh);
    virtual ~Solver() = default;

    // Configuration
    void setConfig(const SolverConfig& config) { config_ = config; }
    const SolverConfig& config() const { return config_; }

    // Initialization
    virtual void initialize();
    
    // Solution
    virtual void solve();
    virtual void step();

    // Output
    void writeOutput(const std::string& filename) const;

    // Field access
    const VectorField& velocity() const { return velocity_; }
    const ScalarField& pressure() const { return pressure_; }

protected:
    const Mesh& mesh_;
    SolverConfig config_;

    // Solution fields
    VectorField velocity_;
    ScalarField pressure_;
    
    // Time
    Real currentTime_ = 0.0;
    Index currentStep_ = 0;
};

} // namespace mantis
