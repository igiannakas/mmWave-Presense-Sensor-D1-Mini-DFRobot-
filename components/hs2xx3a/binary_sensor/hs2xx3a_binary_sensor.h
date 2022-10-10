#pragma once

#include "../hs2xx3a.h"
#include "esphome/core/component.h"
#include "esphome/components/binary_sensor/binary_sensor.h"

namespace esphome {
namespace hs2xx3a {

class HS2XX3ABinarySensor : public binary_sensor::BinarySensor, public PollingComponent {
 public:
  void setup() override;
  void update() override;
  void dump_config() override;
};

} //namespace hs2xx3a
} //namespace esphome