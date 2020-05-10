# Set-up

## Tutorial

See https://www.instructables.com/id/Getting-Started-With-the-ESP8266-ESP-01/

## Settings

* Speed: 115200 baud (Depends on your board, varies from factory)
* Line endings: Both NL+CR

##Pins

* 0 -> RX
* 1 -> TX# Reference
* 3V3 -> VCC
* 3VC -> EN (Marked as EN on some boards and CH_DN on others)
* GND -> GND

# Commands

# Reference

See http://www.pridopia.co.uk/pi-doc/ESP8266ATCommandsSet.pdf

## Reset

AT+RST

## Set Mode

* Station = 1
* AP = 2
* Both = 3

AT+CWMODE=1
AT+CWMODE?

## Read IP

```
AT+CIFSR

+CIFSR:STAIP,"0.0.0.0"
+CIFSR:STAMAC,"a4:cf:12:ef:de:d5"

OK
```

