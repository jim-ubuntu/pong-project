#include <random>
#include <chrono>
#ifndef RANDOM_H
#define RANDOM_H


//seed sequence, MT and probability distribution all in 
//inline namespace 
  
namespace PRNG 
{
  inline std::mt19937 mtSeedObject()
  {
    std::random_device rd {};
    std::seed_seq  seed_s {static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()), rd(), rd(),rd(),rd(),rd(),rd(),rd()};
    return std::mt19937{seed_s}; 
  }

  inline std::mt19937 mt(std::mt19937 mtSeedObject)
  {
    std::mt19937 mt {mtSeedObject};
    return mt;
  }
  
  inline int getRandom(std::mt19937 mt, int min, int max)
  {
    std::uniform_int_distribution<int> distribution(min,max);
    return distribution(mt);
  }
}
#endif
