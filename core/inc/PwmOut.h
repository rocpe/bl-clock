#pragma once

#include <libopencm3/stm32/timer.h>
#include <expected>
#include "common.h"
#include "ErrorKind.h"

namespace blclock {
    class PwmOut {
    public:
        PwmOut(const uint32_t tim, const uint32_t oc, const uint32_t arr);
        auto update(uint8_t duty) -> std::expected<Ok_t, ErrorKind>;
    
    private:
        volatile uint32_t tim;
        volatile uint8_t oc;
        volatile uint32_t arr;
        volatile uint8_t duty;
    };
}
