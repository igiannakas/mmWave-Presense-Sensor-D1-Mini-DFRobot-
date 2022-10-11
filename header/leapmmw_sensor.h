#include "esphome.h"
#include <string>


class leapmmw : public Component, public UARTDevice {
 public:
  leapmmw(UARTComponent *parent) : UARTDevice(parent) {}
  
  void setup() override {
    //
  }

  void publishNumber (std::string sensor, float resp) {
    auto get_numbers = App.get_numbers();
    for(int i = 0; i < get_numbers.size(); i++) {
      auto name = get_numbers[i]->get_name();
      if(name.size() > 6 && name == sensor) {
        get_numbers[i]->publish_state(resp);
      }
    }
  };

  void publishSwitch(std::string sensor, int state) {
    auto sens = App.get_switches();
    for(int i = 0; i < sens.size(); i++) {
      auto name = sens[i]->get_name();
      if(name.size() > 2 && name == sensor) {
          sens[i]->publish_state(state);
      }
    }
  };

  void getmmwConf(std::string mmwparam) {
    mmwparam = mmwparam + "\r";
    write_array(std::vector<unsigned char>(mmwparam.begin(), mmwparam.end()));
  }

  int readline(int readch, char *buffer, int len)
  {
    static int pos = 0;
    int rpos;

    if (readch > 0) {
      switch (readch) {
        case '\n': // Ignore new-lines
          break;
        case '\r': // Return on CR
          rpos = pos;
          pos = 0;  // Reset position index ready for next time
          return rpos;
        default:
          if (pos < len-1) {
            buffer[pos++] = readch;
            buffer[pos] = 0;
          }
      }
    }
    // No end of line has been found, so return -1.
    return -1;
  }
  std::string getline;

  void loop() override {
    const int max_line_length = 40;
    static char buffer[max_line_length];

    while (available()) {

      if(readline(read(), buffer, max_line_length) >= 4) {
        std::string line = buffer;

        // compare last line
        if (line.substr(0, 8) == "Response") {
          
          // leapMMW:/>getSensitivity
          if (getline.substr(0, 24) == "leapMMW:/>getSensitivity" || getline.substr(0, 14) == "getSensitivity") {
            std::string getSensitivity = line.substr(9, 1);
            if (getSensitivity.empty()) {
              ESP_LOGD("custom", "Did not find a value for getSensitivity");
            } else {
              // ESP_LOGD("custom", "The value of getSensitivity is: %f", parse_number<float>(getSensitivity).value());
              publishNumber("sensitivity", parse_number<float>(getSensitivity).value());
            }
          }

          // leapMMW:/>getRange
          if (getline.substr(0, 18) == "leapMMW:/>getRange" || getline.substr(0, 8) == "getRange") {
            std::string getRange = line.substr(15, 4);
            if (getRange.empty()) {
              ESP_LOGD("custom", "Did not find a value for getRange");
            } else {
              ESP_LOGD("custom", "The value of getRange is: %f", parse_number<float>(getRange).value());
              publishNumber("distance", parse_number<float>(getRange).value());
            }
          }

          // leapMMW:/>getLatency
          if (getline.substr(0, 20) == "leapMMW:/>getLatency" || getline.substr(0, 10) == "getLatency") {
            std::string getLatency = line.substr(15, 2);
            if (getLatency.empty()) {
              ESP_LOGD("custom", "Did not find a value for getLatency");
            } else {
              // ESP_LOGD("custom", "The value of getLatency is: %f", parse_number<float>(getLatency).value());
              publishNumber("latency", parse_number<float>(getLatency).value());
            }
          }

          // leapMMW:/>getLedMode
          if (getline.substr(0, 20) == "leapMMW:/>getLedMode" || getline.substr(0, 10) == "getLedMode") {
            std::string getLedMode = line.substr(11, 1);
            if (getLedMode.empty()) {
              ESP_LOGD("custom", "Did not find a value for getLedMode");
            } else {
              int led_state = parse_number<int>(getLedMode).value();
              // ESP_LOGD("custom", "The value of getLedMode is: %i", led_state);
              int setled_state = -1;
              if (led_state == 1) {
                setled_state = 0;
              } else if (led_state == 0) {
                setled_state = 1;
              }
              publishSwitch("led", setled_state);
            }
          }
        }
        if (line.substr(0, 4) == "Done") {
          // leapMMW:/>sensorStop
          if (getline.substr(0, 20) == "leapMMW:/>sensorStop") {
            // ESP_LOGD("custom", "sensorStop completed successfully");
            publishSwitch("mmwave_sensor", 0);
          }

          // leapMMW:/>sensorStart
          if (getline.substr(0, 21) == "leapMMW:/>sensorStart") {
            // ESP_LOGD("custom", "sensorStart completed successfully");
            publishSwitch("mmwave_sensor", 1);
          }
        }
        getline = buffer; 
      }
    }
  }
};
