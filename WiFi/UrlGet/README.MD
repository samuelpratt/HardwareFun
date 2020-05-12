# Voltages

You will need to step down the voltage from the Arduino TX Pin (7 in this case from 5V->3.3V or you may blow up your ESP-01.

You can do this with either a LD1117v33 or 3x 220OHM resistors.

# Serial rate

We're using the software serial library here. This isn't reliable at 1152000 BPS so you need to step this down to 9600 on your ESP-01

The command to do this is something like

```
AT+UART_DEF=9600,8,1,0,0
```

# Circuit

<img src=".\Image.jpg">

<img src=".\Circuit.jpg">
