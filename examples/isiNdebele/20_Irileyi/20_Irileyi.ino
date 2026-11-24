// I-relay ye-5V: ivula futhi ivale umjikelezo wesibili njalo ngemizuzwana emi-2 (uzwa "klik").
// Ukuxhuma: IN -> 7, VCC -> 5V, GND -> GND.  QAPHELA: ungaxhumi ugesi wendlu (230V) uma ungenalo ulwazi!
#include <isiNdebele.h>

okungatjhugulukiko inomboro IRILEYI = 7;

ilize thoma() {
    beka_iphini(IRILEYI, OKUPHUMAKO);
}

ilize phinda_phinda() {
    tlola_idijithali(IRILEYI, PHEZULU);   // vula
    lindela(2000);
    tlola_idijithali(IRILEYI, PHASI);    // vala
    lindela(2000);
}
