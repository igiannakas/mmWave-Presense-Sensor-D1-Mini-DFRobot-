# mmwave-d1mini
mmWave presence detection using DFRobot SEN0395, D1 Mini ESP-8266 and ESPHome

This custom module is used to implement a room presense sensor based on a D1 Mini (ESP-8266), DFRobot SEN0395 mmWave radar and exposed to Home Assistant via the ESPHome integration.

This is based on the excellent work done by CRlogic in the HA forums and documented here: https://github.com/hjmcnew/esphome-hs2xx3a-custom-component/tree/release

In this fork the code is adapted to:
1. Deliver a very compact build as the DFRobot sensor is stacked on top of the D1 Mini
2. Trimmed down the code by CRLogic to improve stability for the low power D1 Mini
3. Prettify the exposed sensor names to Home Assistant to reflect the name of the room the sensor is in
4. Contain the full sensor YML configuration to simplify the setup process


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


