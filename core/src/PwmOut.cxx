#include "PwmOut.h"

using namespace blclock;

PwmOut::PwmOut(const uint32_t tim, const uint32_t oc, const uint32_t arr)
    : tim(tim),
      oc(oc),
      arr(arr){ }

auto
PwmOut::update(uint8_t duty) -> std::expected<Ok_t, ErrorKind>
{
  if (duty < 0 || duty > 100)
      return std::unexpected(ErrorKind::DUTY_NOT_IN_RANGE);

  this->duty = duty;
  timer_set_oc_value(this->tim,
      static_cast<tim_oc_id>(this->oc),
      (this->duty * this->arr) / 100
      );

  Ok_t ok; return ok;
}
