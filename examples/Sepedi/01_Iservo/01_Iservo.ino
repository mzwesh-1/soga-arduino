// SG90 Iservo: ijika kusuka ku-0 kuya ku-180 degrees bese ibuyela emuva.
// Ukuxhuma: intambo ensundu -> GND, ebomvu -> 5V, ewolintshi -> iphini 9
#include <Servo.h>
#include <Sepedi.h>

Seservo iservo_yami;

lefeela thoma() {
    iservo_yami.kgokaganya(9);
}

lefeela boeletsa() {
    dikologa (palo i = 0; i <= 180; i++) {
        iservo_yami.ngwala_paete(i);     // iya ku-engeli i
        leta(15);
    }
    dikologa (palo i = 180; i >= 0; i--) {
        iservo_yami.ngwala_paete(i);
        leta(15);
    }
}
