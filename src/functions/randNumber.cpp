#include "functions/functions.hpp"

unsigned int randNumber(unsigned int num)
{
unsigned int res{ 0 };
using u32 = uint_least32_t;
using engine = std::mt19937;

std::random_device os_seed;
const u32 seed = os_seed();

engine generator(seed);
std::uniform_int_distribution < u32 > distribute(0, num);

for (unsigned int repetition{ 0 }; repetition < 10; ++repetition)
{
    res = distribute(generator);
}

return res;
}