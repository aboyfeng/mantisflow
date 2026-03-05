#pragma once

#include "types.hpp"
#include <string>

namespace mantis {

/**
 * @brief Basic mesh class for CFD simulations
 */
class Mesh {
public:
    Mesh() = default;
    ~Mesh() = default;

    // Mesh generation
    void createBox(Real lx, Real ly, Real lz, Index nx, Index ny, Index nz);
    
    // I/O
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;

    // Accessors
    Index numCells() const { return numCells_; }
    Index numFaces() const { return numFaces_; }
    Index numNodes() const { return numNodes_; }

    const std::vector<Vec3>& cellCenters() const { return cellCenters_; }
    const std::vector<Real>& cellVolumes() const { return cellVolumes_; }

private:
    Index numCells_ = 0;
    Index numFaces_ = 0;
    Index numNodes_ = 0;

    std::vector<Vec3> nodes_;
    std::vector<Vec3> cellCenters_;
    std::vector<Real> cellVolumes_;
    std::vector<Vec3> faceNormals_;
    std::vector<Real> faceAreas_;
};

} // namespace mantis
