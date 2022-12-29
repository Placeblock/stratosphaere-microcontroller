#include "../sensor.h"

class LM75Data : public SensorData {
    public:
        int16_t temperature;
        LM75Data(int16_t);
        uint8_t convertLORA();
};

class LM75Sensor : public Sensor<LM75Data> {
    public:
        void configure();
        LM75Data getData();
};