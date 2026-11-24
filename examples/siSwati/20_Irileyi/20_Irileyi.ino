// I-relay ye-5V: ivula futhi ivale umjikelezo wesibili njalo ngemizuzwana emi-2 (uzwa "klik").
// Ukuxhuma: IN -> 7, VCC -> 5V, GND -> GND.  QAPHELA: ungaxhumi ugesi wendlu (230V) uma ungenalo ulwazi!
#include <siSwati.h>

lokungagucuki inombolo IRILEYI = 7;

lite cala() {
    setha_liphini(IRILEYI, LOKUPHUMAKO);
}

lite phindza_phindza() {
    bhala_idijithali(IRILEYI, PHETULU);   // vula
    lindza(2000);
    bhala_idijithali(IRILEYI, PHANSI);    // vala
    lindza(2000);
}
