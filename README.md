# Introduction
This is a step by step guide on how to build an mmWave presence detection using DFRobot SEN0395, D1 Mini ESP-8266 and ESPHome. 

The custom module in the code above is used to implement a room presense sensor and exposes the presense detection sensor and the radar's configuration variables to Home Assistant via the ESPHome integration.

This is based on the excellent work done by CRlogic in the HA forums and documented here: https://github.com/hjmcnew/esphome-hs2xx3a-custom-component/tree/release

In this fork the code is adapted to:
1. Deliver a very compact build as the DFRobot sensor is stacked on top of the D1 Mini
2. Trimmed down the code by CRLogic to improve stability for the low power D1 Mini
3. Prettify the exposed sensor names to Home Assistant to reflect the name of the room the sensor is in
4. Contain the full sensor yaml configuration to simplify the setup process


# Bill of Materials:
To make this DIY room presense sensor you'll need the below components:
1. D1 Mini (~£3)
2. DFRobot SEN0395 (from Digi Key, Mouser, Arrow.com, Farnell.com, AliExpress) (~£32)
3. Mini USB cable and a USB power supply (I use my old phone chargers) (~£5)
4. Soldering iron
5. 5 cm / 2 inch of wire
6. Optional: 3d printed case

Total Cost: £40

# Wiring instructions:
To get the smallest possible size we stack the sensor on top of the D1 Mini using the pins that come with the D1 mini. The wiring diagram below reflects a stacked configuration:
Sensor Pin -> D1 Mini Pin
1. TX -> D1
2. RX -> D2
3. IO1 -> not connected
4. IO2 -> D0 (using the wire)
5. G -> G
6. V -> 5V

For the D1, D2, G and 5V pins we will use header and pin connectors soldered on the D1 mini and the mmWave sensor. The D0 - IO2 connection happens via a wire which is soldered on the D0 pad of the D1 mini and the IO2 pad of the sensor.

# Assembly images

Solder the header connectors and the single wire to the D1 Mini as below:
![D1 Mini connections](project-images/1.jpeg "D1 Mini connections")

Solder the pins to the outer two sets of pads on the sensor (TX, RX, G, V) and then solder the single wire to IO2
![Sensor connections](project-images/2.jpeg "Sensor connections")

Plug in the sensor to the D1 mini,making sure the V sensor pin is aligned to the 5V header on the D1 mini
![Sensor placement](project-images/3.jpeg "Sensor placement")

![Sensor placement](project-images/5.jpeg "Sensor placement")

As you can see this is a super compact sensor, barely bigger than the D1 mini itself.
![Sensor assembled](project-images/6.jpeg "Sensor assembled")

# Installing ESPHome and the mmWave code

1. Setup your esphome environment. For instructions: https://esphome.io
2. Clone this repository to your build environment. Download the code zip and unpack it in your esphome build directory
3. Open the sensor.yaml file and modify the following variables to match your setup:

**device_name**: the sensor's device name. This must be in lower case and any words separated with hyphens (-). For example: living-room-occupancy-sensor
**device_name_pretty**: This is the name of the occupancy binary sensor that will be exposed to home assistant. It can be upper and lower case and can contain spaces. For example: Room Name Occupancy Sensor
**ssid**: type your 2.4ghz wifi SSID
**wifi_password**: type in your wifi password

4. Deploy the code. I have installed esphome on my mac so I use the following command to deploy the code: esphome run sensor.yaml
