//
// Created by אלה on 16/01/2019.
//

#include <iostream>

class InputDevice
{
public:
    InputDevice() : _inChnNum(0) {}
    InputDevice(int num) : _inChnNum(num) {}
protected:
    int _inChnNum;
};

class OutputDevice
{
public:
    OutputDevice() : _resolution(0) {}
    OutputDevice(int num) : _resolution(num) {}
protected:
    int _resolution;
};

class Mouse : virtual public InputDevice {
public:
    Mouse(int num) : InputDevice(num + 2) {}
    int getInputs() const {
        return _inChnNum;
    }
};

class Screen : virtual public OutputDevice {
public:
    Screen(int in) : OutputDevice(in) {}
    int getResolution() const {
        return _resolution;
    }
};

class htcVIVE : public Mouse, public Screen {
public:
    htcVIVE(int m, int s) : InputDevice(m+6), OutputDevice(s*2) , Mouse(m+6), Screen(s*2) {
    }
};

