#include <raspi/gpio.h>

#include <thread>

template<auto... Is, typename Callable>
constexpr void for_each_value(Callable &&f) noexcept {
    (f.template operator()<Is>(), ...);
}

int main() {
    using namespace std::chrono_literals;
    using namespace raspi;

    const auto pin = gpio<raspberry_b_plus>();

    for_each_value<7, 8, 9, 10, 17, 18, 24, 25, 27>([&pin]<auto N>() {
        // enable pin
        pin.high<N>();
        // sleep
        std::this_thread::sleep_for(2000ms);
        // disable pin
        pin.low<N>();
    });

    return 0;
}
