# raspi
[![GCC 10.3](https://github.com/MichaelMiller-/raspi/actions/workflows/gcc10.yml/badge.svg)](https://github.com/MichaelMiller-/raspi/actions/workflows/gcc10.yml) [![GCC 11.0](https://github.com/MichaelMiller-/raspi/actions/workflows/gcc11.yml/badge.svg)](https://github.com/MichaelMiller-/raspi/actions/workflows/gcc11.yml) [![Clang 10.0](https://github.com/MichaelMiller-/raspi/actions/workflows/clang10.yml/badge.svg)](https://github.com/MichaelMiller-/raspi/actions/workflows/clang10.yml)

raspi is an easy to use header-only library to control the [GPIO pins](https://www.raspberrypi.com/documentation/computers/os.html#gpio-and-the-40-pin-header) of the RaspberryPi.
Each [RaspberryPI](https://www.raspberrypi.org/) model can easily be specified via template parameters and, if necessary, adapted with its own classes.
To avoid incorrect use, compile-time assertions have also been implemented.
In contrast to other libraries, there is no complicated mapping of the pins. Each pin in the library also corresponds 1:1 to the hardware pin. 

## Requirements
- Minimum C++20

## Example
```c++
int main() {
    using namespace raspi;
    
    // initialize gpio with Raspberry Pi B settings (26pin)
    const auto pin = gpio<raspberry_b>{};
    // enable GPIO pin 18
    pin.high<18>();
    // disable
    pin.low<18>();
    // ...
}
```


## Todo
- read from GPIO pin

