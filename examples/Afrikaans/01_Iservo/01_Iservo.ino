// SG90 Iservo: ijika kusuka ku-0 kuya ku-180 degrees bese ibuyela emuva.
// Ukuxhuma: intambo ensundu -> GND, ebomvu -> 5V, ewolintshi -> iphini 9
#include <Servo.h>
#include <Afrikaans.h>

Servomotor iservo_yami;

leeg opstel() {
    iservo_yami.koppel(9);
}

leeg lus() {
    vir (heelgetal i = 0; i <= 180; i++) {
        iservo_yami.skryfgreep(i);     // iya ku-engeli i
        wag(15);
    }
    vir (heelgetal i = 180; i >= 0; i--) {
        iservo_yami.skryfgreep(i);
        wag(15);
    }
}
