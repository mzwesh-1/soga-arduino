// I-relay ye-5V: ivula futhi ivale umjikelezo wesibili njalo ngemizuzwana emi-2 (uzwa "klik").
// Ukuxhuma: IN -> 7, VCC -> 5V, GND -> GND.  QAPHELA: ungaxhumi ugesi wendlu (230V) uma ungenalo ulwazi!
#include <isiZulu.h>

engaguquki inombolo IRILEYI = 7;

ize qala() {
    setha_iphini(IRILEYI, OKUPHUMAYO);
}

ize phindaphinda() {
    bhala_idijithali(IRILEYI, PHEZULU);   // vula
    linda(2000);
    bhala_idijithali(IRILEYI, PHANSI);    // vala
    linda(2000);
}
