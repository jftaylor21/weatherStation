#include "Weather.hpp"

Weather::Weather(double t, double h, double p)
  : temperature(t),
    humidity(h),
    pressure(p)
{
}

Weather::~Weather()
{
}
