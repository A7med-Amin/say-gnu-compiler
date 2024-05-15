#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "assemblyGenerator.hpp"

using namespace std;


AssemblyGenerator::AssemblyGenerator()
{
    quadruples = new vector<Quadruple*>();
}
