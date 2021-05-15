#ifndef STEPPER_HPP
#define STEPPER_HPP

#include <sys/types.h>
#include <pigpio.h>
#include <unistd.h>
#include "pins.hpp"

namespace rpistepper
{
    class stepper
    {
        public:
            enum direction: bool {
                CCW = 0,
                CW = 1
            };
            stepper(GPIOPins enablePin, GPIOPins directionPin, GPIOPins stepPin, uint stepSleep);
            ~stepper();
            void setup();
            void move(uint steps, direction dir);

        private:
            GPIOPins enablePin;
            GPIOPins directionPin;
            GPIOPins stepPin;
            unsigned int stepSleep;
            bool isMotorEnabled = false;
            void enableMotor();
            void disableMotor();
            
    };
}

#endif
