# MantisFlow Architecture

## Project Structure

```
mantisflow/
├── CMakeLists.txt          # Build configuration
├── include/mantisflow/     # Public headers
│   ├── types.hpp           # Basic types and vector math
│   ├── mesh.hpp            # Mesh data structures
│   └── solver.hpp          # Solver base class
├── src/                    # Source files
│   ├── main.cpp            # Entry point
│   ├── mesh/               # Mesh implementation
│   └── solver/             # Solver implementation
├── tests/                  # Unit tests
├── examples/               # Example cases
│   └── cavity/             # Lid-driven cavity
└── docs/                   # Documentation
```

## Core Components

### 1. Mesh (`mesh.hpp`)
- Handles mesh storage and generation
- Supports structured box meshes
- TODO: Unstructured mesh support, file I/O

### 2. Solver (`solver.hpp`)
- Base class for CFD solvers
- Manages solution fields (velocity, pressure)
- Time stepping and convergence control

### 3. Types (`types.hpp`)
- Basic type definitions (Real, Index, Vec3)
- Vector math operations
- Field containers

## Planned Features

- [ ] SIMPLE algorithm for incompressible flow
- [ ] Finite Volume Method discretization
- [ ] VTK output for visualization
- [ ] OpenFOAM mesh import
- [ ] MPI parallelization
- [ ] Turbulence models (k-epsilon, k-omega)

## Build Instructions

```bash
mkdir build && cd build
cmake ..
make -j4
./mantis --help
```

---

*MantisFlow - 出拳快，算得准。* 🦐
