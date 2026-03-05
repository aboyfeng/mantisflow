/**
 * MantisFlow - A CFD Solver
 * 
 * Created by 峰哥 & 小虾仔 🦐
 * "出拳快，算得准。"
 */

#include <iostream>
#include <string>

void printBanner() {
    std::cout << R"(
  __  __             _   _     _____ _               
 |  \/  | __ _ _ __ | |_(_)___|  ___| | _____      __
 | |\/| |/ _` | '_ \| __| / __| |_  | |/ _ \ \ /\ / /
 | |  | | (_| | | | | |_| \__ \  _| | | (_) \ V  V / 
 |_|  |_|\__,_|_| |_|\__|_|___/_|   |_|\___/ \_/\_/  
                                                      
    )" << '\n';
    std::cout << "  MantisFlow v0.1.0 - CFD Solver\n";
    std::cout << "  Created by 峰哥 & 小虾仔 🦐\n";
    std::cout << "  \"出拳快，算得准。\"\n\n";
}

void printUsage(const std::string& programName) {
    std::cout << "Usage: " << programName << " [options] <case_file>\n\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help     Show this help message\n";
    std::cout << "  -v, --version  Show version info\n";
    std::cout << "  -p, --parallel Run in parallel mode\n";
    std::cout << "\n";
}

int main(int argc, char* argv[]) {
    printBanner();

    if (argc < 2) {
        printUsage(argv[0]);
        std::cout << "No case file specified. Exiting.\n";
        return 0;
    }

    std::string arg = argv[1];
    
    if (arg == "-h" || arg == "--help") {
        printUsage(argv[0]);
        return 0;
    }
    
    if (arg == "-v" || arg == "--version") {
        std::cout << "MantisFlow version 0.1.0\n";
        return 0;
    }

    std::cout << "Loading case: " << arg << "\n";
    std::cout << "(Solver implementation coming soon...)\n";

    return 0;
}
