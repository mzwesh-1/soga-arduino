// SG90 Iservo: ijika kusuka ku-0 kuya ku-180 degrees bese ibuyela emuva.
// Ukuxhuma: intambo ensundu -> GND, ebomvu -> 5V, ewolintshi -> iphini 9
#include <Servo.h>
#include <isiXhosa.h>

Iservo iservo_yami;

ize qalisa() {
    iservo_yami.qhagamshela(9);
}

ize phinda_phinda() {
    jikeleza (inani i = 0; i <= 180; i++) {
        iservo_yami.bhala_ibhayithi(i);     // iya ku-engeli i
        linda(15);
    }
    jikeleza (inani i = 180; i >= 0; i--) {
        iservo_yami.bhala_ibhayithi(i);
        linda(15);
    }
}
