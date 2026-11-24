// SG90 Iservo: ijika kusuka ku-0 kuya ku-180 degrees bese ibuyela emuva.
// Ukuxhuma: intambo ensundu -> GND, ebomvu -> 5V, ewolintshi -> iphini 9
#include <Servo.h>
#include <Xitsonga.h>

Xiservo iservo_yami;

swi_hava sungula() {
    iservo_yami.khomanisa(9);
}

swi_hava phindha_phindha() {
    rhendzeleka (nomboro i = 0; i <= 180; i++) {
        iservo_yami.tsala_bayiti(i);     // iya ku-engeli i
        rindza(15);
    }
    rhendzeleka (nomboro i = 180; i >= 0; i--) {
        iservo_yami.tsala_bayiti(i);
        rindza(15);
    }
}
