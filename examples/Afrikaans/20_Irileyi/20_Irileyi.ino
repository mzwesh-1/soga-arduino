// I-relay ye-5V: ivula futhi ivale umjikelezo wesibili njalo ngemizuzwana emi-2 (uzwa "klik").
// Ukuxhuma: IN -> 7, VCC -> 5V, GND -> GND.  QAPHELA: ungaxhumi ugesi wendlu (230V) uma ungenalo ulwazi!
#include <Afrikaans.h>

konstant heelgetal IRILEYI = 7;

leeg opstel() {
    penmodus(IRILEYI, UITSET);
}

leeg lus() {
    skryfdigitaal(IRILEYI, HOOG);   // vula
    wag(2000);
    skryfdigitaal(IRILEYI, LAAG);    // vala
    wag(2000);
}
