#ifndef GPIO_H
#define GPIO_H

#include <string_view>
#include <array>
#include <fstream>

namespace raspi
{
    // Raspberry Pi Models A, B and Pico (26-pin)
    struct raspberry_b
    {
        static constexpr auto valid_pins = std::array{ 2, 3, 4, 7, 8, 9, 10, 11, 14, 15, 17, 18, 22, 23, 24, 25, 27 };
    };

    // Raspberry Pi Models A+, B+, > Pi2 (40-pin)
    struct raspberry_b_plus
    {
        static constexpr auto valid_pins = std::array{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };
    };


    template<typename Model>
    class gpio
    {
        class registry
        {
            std::size_t registered_pin{0};

            registry() = default;
            ~registry() { remove(registered_pin); }

            void add(std::size_t pin)
            {
                std::ofstream ofs{"/sys/class/gpio/export"};
                ofs << pin;
                registered_pin = pin;
            }
            void remove(std::size_t pin)
            {
                std::ofstream ofs{"/sys/class/gpio/unexport"};
                ofs << pin;
                registered_pin = 0;
            }
        public:
            template<typename T>
            void write(std::size_t pin, T const& t)
            {
                if (pin != registered_pin)
                {
                    remove(registered_pin);
                    add(pin);
                }
                std::ofstream ofs{"/sys/class/gpio/gpio" + std::to_string(pin) + "/value"};
                ofs << t;
            };

            [[nodiscard]] static auto& instance()
            {
                static registry result;
                return result;
            }
        };

    public:
        template<auto Pin>
        void high() const
        {
            constexpr auto it = std::find(begin(Model::valid_pins), end(Model::valid_pins), Pin);
            static_assert(it != end(Model::valid_pins), "pin is not valid for this model");

            registry::instance().write(Pin, 1);
        }

        template<auto Pin>
        void low() const
        {
            constexpr auto it = std::find(begin(Model::valid_pins), end(Model::valid_pins), Pin);
            static_assert(it != end(Model::valid_pins), "pin is not valid for this model");

            registry::instance().write(Pin, 0);
        }
    };
}

#endif