// SG90 Iservo: ijika kusuka ku-0 kuya ku-180 degrees bese ibuyela emuva.
// Ukuxhuma: intambo ensundu -> GND, ebomvu -> 5V, ewolintshi -> iphini 9
#include <Servo.h>
#include <isiNdebele.h>

Iservo iservo_yami;

ilize thoma() {
    iservo_yami.bopha_ephinini(9);
}

ilize phinda_phinda() {
    jikeleza (inomboro i = 0; i <= 180; i++) {
        iservo_yami.tlola_ibhayithi(i);     // iya ku-engeli i
        lindela(15);
    }
    jikeleza (inomboro i = 180; i >= 0; i--) {
        iservo_yami.tlola_ibhayithi(i);
        lindela(15);
    }
}
