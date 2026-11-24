// SG90 Iservo: ijika kusuka ku-0 kuya ku-180 degrees bese ibuyela emuva.
// Ukuxhuma: intambo ensundu -> GND, ebomvu -> 5V, ewolintshi -> iphini 9
#include <Servo.h>
#include <siSwati.h>

Iservo iservo_yami;

lite cala() {
    iservo_yami.xhuma(9);
}

lite phindza_phindza() {
    jikeleta (inombolo i = 0; i <= 180; i++) {
        iservo_yami.bhala_ibhayithi(i);     // iya ku-engeli i
        lindza(15);
    }
    jikeleta (inombolo i = 180; i >= 0; i--) {
        iservo_yami.bhala_ibhayithi(i);
        lindza(15);
    }
}
