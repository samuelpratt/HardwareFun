# What is this?

Fun with electronics... featuring a Raspberry Pi, a (clone) Arduino and an ESP32 Dev Board.

Started to pass the time during the early 2020 COVID-19 Lockdown.

<img src="Boards.jpg">
<img src="esp32.jpg" style="width:200px;height:200px">

# Stuff I bought

## Arduino

Arduino's are educational development boards. See https://www.arduino.cc/

You can either get their official boards or buy clones (the desing and firmware are all open source). If you do get a clone board (because they're cheaper) consider donating some money to Arduino 

I bought a clone Uno R3 https://www.amazon.co.uk/dp/B01EWOE0UU made by Elegoo. 

## Electronics Starter kit

There are a few of these about. Look for Freenove and Elegoo. They're all basically the same thing. The PI kit can generally be used with the Arduino and vice-versa, although you may have do do some adapting / adjusting voltages.

The only thing to note Rasperry Pi kits tend to come with a breakout adaptor for the GPIO Pins. They also come with a ADC as the Pi doesn't have analog to digital onboard.

I bought this one: https://www.amazon.co.uk/Freenove-Raspberry-Beginner-Processing-Tutorials/dp/B06WP7169Y

Note the instructions tend to be pretty basic and usually don't explain why you're doing what you're doing. I would personally throw them away and do some googling.

## Raspberry Pi

Mine is an elderly 2B. If you buy one the lastest version is 4 and is seriously powerful!

## ESP32

This a dev board based on the ESP32 chipset. It's a bit harder to use than the Arduino but you get 512kb RAM, a Dual core ARM processor, integrated WiFi, an RTC and 4MB flash for ~£6.50, bargain!

Various boards are available. They're all pretty much the same as they're based on a reference design. I got one of these as it was the cheapest at the time: https://www.amazon.co.uk/gp/product/B071JR9WS9

## WiFi

Depends which board you're using.

### Arduino

This can get a bit complicated. Easiest option is to buy a Arduino with Wifi built in. For more fun you can use a module such as an ESP-01: https://www.amazon.co.uk/MakerHawk-ESP8266-ESP-01S-Transceiver-Arduino-As-Shown/dp/B0728CBGKT and speak to it via Serial.

Interestingly, the ESP8266 chip on the ESP-01 contains a 32bit RISC CPU and is actually a fair bit more powerfull than the 8bit controller on the Arduino UNO! You can actually re-flash the contoller using 3rd party firmware and run C++ directly on it. See https://en.wikipedia.org/wiki/NodeMCU for more details. You can also get some very cool all in one ESP8266 development boards that have GPIO pins on them.

### Raspbery PI

This is pretty easy.

Models >3 have WiFi chips built in.

For older PIs (mine is a 2B) you'll need a USB dongle. Try here: https://elinux.org/RPi_USB_Wi-Fi_Adapters

Set-up is via raspi-config or directly editing the config files in /etc.

### ESP32

This *is* a WiFi chipset!
