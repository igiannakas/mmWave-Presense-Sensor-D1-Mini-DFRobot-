#include "esphome/core/log.h"
#include "hs2xx3a.h"

namespace esphome {
namespace hs2xx3a {

static const char *TAG = "hs2xx3a.component";

void HS2XX3A::setup() {

}

void HS2XX3A::loop() {

}

void HS2XX3A::dump_config(){
    ESP_LOGCONFIG(TAG, "HS2xx3A component");
}

}  // namespace hs2xx3a
}  // namespace esphome