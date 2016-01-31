# Petmoj<sup>1</sup>

Arduino project to interface with a rotary dial from an old [Ericsson Dialog][4] phone<sup>2</sup>. Dial FaceTime calls grampa style or make your computer do other cool stuff by listening to the dial over serial communication.

[See it in action over at Vimeo][6].

![][dialanduno]
*Rotary Dial hooked up to Arduino UNO.*

## What's needed for this project?

* Rotary dial from old phone (I scored mine on [Tradera][5]).
* Some Arduino-compatible device (I used UNO).

## How (my) rotary dial works

TODO

## Wiring the circuit

When you know what's what with your dial it's time to wire it to the Arduino board you are using. My dial has three wires:

1. White (ground) goes to GND on the Arduino.
2. Red (home switch) goes to pin 2 on the Arduino.
3. Blue (pulse switch) goes to pin 4 on the Arduino.

![][hookup]

## Get the code on your Arduino

TODO

## Monitor the serial communication

TODO

## License

Petmoj is released under the MIT License.

## Similar projects by others

* [Rotary dial][1] by Mark Fickett
* [Software for AS Elektrisk Bureau][2] by Harald Nesland
* [Interface a rotary phone dial to an Arduino][3] by guidomax

---

<small>1. Petmoj is Swedish slang for rotary dial. It roughly translates to pokeygadget.</small>  
<small>2. Or a dial from any old phone really. You may have to juggle things around a bit to get it work though.</small>

[1]: https://github.com/markfickett/Rotary-Dial
[2]: https://github.com/hnesland/aselektriskbureau
[3]: http://www.instructables.com/id/Interface-a-rotary-phone-dial-to-an-Arduino/
[4]: https://en.wikipedia.org/wiki/Ericsson_Dialog
[5]: http://www.tradera.com/fingerskiva-c3_302017
[6]: https://vimeo.com/152847479
[dialanduno]: docs/images/rotary-dial-and-arduino-uno.jpg
[hookup]: docs/images/hookup.png
