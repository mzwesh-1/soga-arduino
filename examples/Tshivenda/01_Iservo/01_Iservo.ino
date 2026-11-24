// SG90 Iservo: ijika kusuka ku-0 kuya ku-180 degrees bese ibuyela emuva.
// Ukuxhuma: intambo ensundu -> GND, ebomvu -> 5V, ewolintshi -> iphini 9
#include <Servo.h>
#include <Tshivenda.h>

Tshiservo iservo_yami;

a_huna thoma() {
    iservo_yami.tumanya(9);
}

a_huna dovholola() {
    mona (nomboro i = 0; i <= 180; i++) {
        iservo_yami.nwala_baithi(i);     // iya ku-engeli i
        lindela(15);
    }
    mona (nomboro i = 180; i >= 0; i--) {
        iservo_yami.nwala_baithi(i);
        lindela(15);
    }
}
