#include "HIHSensor.h"
#include <iostream>

void HIHSensor::configure() {
    std::cout << "5";
}

HIHData HIHSensor::getData() {
    return {20, 25};
}