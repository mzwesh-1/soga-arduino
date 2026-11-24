# Soga for Arduino IDE

Write Arduino sketches in your home language. Install this library (Sketch -> Include Library ->
Add .ZIP Library...), then make your language header the first line of the sketch:

```cpp
#include <isiZulu.h>

ize qala() {
    setha_iphini(13, OKUPHUMAYO);
}

ize phindaphinda() {
    bhala_idijithali(13, PHEZULU);
    linda(1000);
    bhala_idijithali(13, PHANSI);
    linda(1000);
}
```

Headers: `isiZulu.h`, `isiXhosa.h`, `siSwati.h`, `isiNdebele.h`, `Sesotho.h`, `Setswana.h`, `Sepedi.h`, `Xitsonga.h`, `Tshivenda.h`, `Afrikaans.h`.

- Put other libraries (`#include <Servo.h>`, `<Wire.h>`...) before your language header.
- `#include` lines stay in C++: the preprocessor reads them before any header can help.
- On AVR boards (Uno, Nano, Mega), write accented words without the accents (`tsa` for `tša`); both are defined.
- Compiler errors are shown in English in Arduino IDE. For errors in your language, use Soga in VS Code.
- The words are a draft that native speakers are still reviewing.

This library is generated from the Soga language project: https://github.com/mzwesh-1/lula
