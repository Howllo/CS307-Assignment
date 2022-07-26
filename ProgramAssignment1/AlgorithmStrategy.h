#pragma once
#include <string>

class AlgorithmStrategy
{
public:
    AlgorithmStrategy();
    virtual ~AlgorithmStrategy();
    std::string algorithmType = "none";
    virtual double AlgorithmUse();
};