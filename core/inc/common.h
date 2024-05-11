/// @file common.h
/// @brief Common defines and functions used in various places of the project.
#pragma once

#define PS_TIM3_CH1 (12*20) // prescaler for timer 3 channel 1
#define ARR_TIM3_CH1 (4*1000) // auto reload reg value for timer 3 channel 1
                              
struct Ok_t { };  // structure to indicating that everything is ok
                              
namespace blclock {
/// @brief Panicking behaviour.
/// 
/// This has to be somehow implemented. For now it is just forever loop.
///
/// @param void
void
panic();
}

