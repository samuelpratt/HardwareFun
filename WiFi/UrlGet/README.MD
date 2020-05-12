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

# Example output

```
Starting Loop
Reseting WiFi
Module Reset OK
Waiting for WiFi to start-up....................
Setting Station Mode
Station Mode Set to 1
Joining WiFi
Joined OK
Mux Set to 0
Connecting to host www.google.com
Connected to www.google.com
OK to send
Sent request OK
Got '1430' bytes
HTTP/1.1 200 OK
Date: Tue, 12 May 2020 22:19:38 GMT
Expires: -1
Cache-Control: private, max-age=0
Content-Type: text/html; charset=ISO-8859-1
P3P: CP="This is not a P3P policy! See g.co/p3phelp for more info."
Server: gws
X-XSS-Protection: 0
X-Frame-Options: SAMEORIGIN
Set-Cookie: 1P_JAR=2020-05-12-22; expires=Thu, 11-Jun-2020 22:19:38 GMT; path=/; domain=.google.com; Secure
Set-Cookie: NID=204=yJ2tTlAyYZTBXpfTtA_Fsvio-gl5Qyx0jVXifl40EgRU-QPpMMvEcrSOvoGUqNoH6Mxu7QyjlWjwFxnP7_Qh40isy03dHRa2Bw9Y7bdOcVLs3wquoVPPj3G7hlIM4dXRlfeoly5k_1lgOUu6DuedMRkZ8ycS6xIiLZ2sRPhv3DE; expires=Wed, 11-Nov-2020 22:19:38 GMT; path=/; domain=.google.com; HttpOnly
Accept-Ranges: none
Vary: Accept-Encoding
Transfer-Encoding: chunked


Closing connection
Sleeping zzzzzzzzzzzzzzzzzzzz
```
