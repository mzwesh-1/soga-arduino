// SG90 Iservo: ijika kusuka ku-0 kuya ku-180 degrees bese ibuyela emuva.
// Ukuxhuma: intambo ensundu -> GND, ebomvu -> 5V, ewolintshi -> iphini 9
#include <Servo.h>
#include <Setswana.h>

Seservo iservo_yami;

lefela simolola() {
    iservo_yami.golaganya(9);
}

lefela boeletsa() {
    dikologa (palo i = 0; i <= 180; i++) {
        iservo_yami.kwala_baete(i);     // iya ku-engeli i
        ema(15);
    }
    dikologa (palo i = 180; i >= 0; i--) {
        iservo_yami.kwala_baete(i);
        ema(15);
    }
}
