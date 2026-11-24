// I-relay ye-5V: ivula futhi ivale umjikelezo wesibili njalo ngemizuzwana emi-2 (uzwa "klik").
// Ukuxhuma: IN -> 7, VCC -> 5V, GND -> GND.  QAPHELA: ungaxhumi ugesi wendlu (230V) uma ungenalo ulwazi!
#include <Sepedi.h>

sa_fetogego palo IRILEYI = 7;

lefeela thoma() {
    bea_phini(IRILEYI, TSE_TSWAGO);
}

lefeela boeletsa() {
    ngwala_dijithale(IRILEYI, GODIMO);   // vula
    leta(2000);
    ngwala_dijithale(IRILEYI, FASE);    // vala
    leta(2000);
}
