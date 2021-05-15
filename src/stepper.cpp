#include "stepper.hpp"

namespace rpistepper
{
    stepper::stepper(GPIOPins enablePin, GPIOPins directionPin, GPIOPins stepPin, uint stepSleep = 1000)
    {
        this->enablePin = enablePin;
        this->directionPin = directionPin;
        this->stepPin = stepPin;
        this->stepSleep = stepSleep;
        gpioInitialise();
    }

    stepper::~stepper()
    {
        gpioTerminate();
    }

    void stepper::setup()
    {
        gpioSetMode(this->enablePin, PI_OUTPUT);
        gpioSetMode(this->directionPin, PI_OUTPUT);
        gpioSetMode(this->stepPin, PI_OUTPUT);
    }

    void stepper::move(uint steps, direction dir)
    {
        uint realizedSteps = 0;
        this->enableMotor();

        gpioWrite(this->directionPin, dir == CW ? 1 : 0);

        while (realizedSteps < steps)
        {
            gpioWrite(this->stepPin, 1);
            usleep(this->stepSleep);
            gpioWrite(this->stepPin, 0);
            usleep(this->stepSleep);
            realizedSteps++;
        }

        this->disableMotor();
    }

    void stepper::enableMotor()
    {
        gpioWrite(this->enablePin, 1);
    }

    void stepper::disableMotor()
    {
        gpioWrite(this->enablePin, 0);
    }
}
