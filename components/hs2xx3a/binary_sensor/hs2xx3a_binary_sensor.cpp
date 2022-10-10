#include "esphome/core/log.h"
#include "hs2xx3a_binary_sensor.h"

namespace esphome {
namespace hs2xx3a {

static const char *TAG = "hs2xx3a.binary_sensor";

void HS2XX3ABinarySensor::setup() {
    
}
  
void HS2XX3ABinarySensor::update() {

}

void HS2XX3ABinarySensor::dump_config() {
    ESP_LOGCONFIG(TAG, "HS2XX3A binary sensor");
}

} //namespace hs2xx3a
} //namespace esphome