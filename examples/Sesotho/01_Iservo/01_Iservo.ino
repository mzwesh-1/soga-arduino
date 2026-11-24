// SG90 Iservo: ijika kusuka ku-0 kuya ku-180 degrees bese ibuyela emuva.
// Ukuxhuma: intambo ensundu -> GND, ebomvu -> 5V, ewolintshi -> iphini 9
#include <Servo.h>
#include <Sesotho.h>

Seservo iservo_yami;

lefeela qala() {
    iservo_yami.hokela(9);
}

lefeela pheta_pheta() {
    bakeng_sa (palo i = 0; i <= 180; i++) {
        iservo_yami.ngola_baete(i);     // iya ku-engeli i
        ema(15);
    }
    bakeng_sa (palo i = 180; i >= 0; i--) {
        iservo_yami.ngola_baete(i);
        ema(15);
    }
}
