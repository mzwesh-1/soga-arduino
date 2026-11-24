// I-relay ye-5V: ivula futhi ivale umjikelezo wesibili njalo ngemizuzwana emi-2 (uzwa "klik").
// Ukuxhuma: IN -> 7, VCC -> 5V, GND -> GND.  QAPHELA: ungaxhumi ugesi wendlu (230V) uma ungenalo ulwazi!
#include <Setswana.h>

e_sa_fetogeng palo IRILEYI = 7;

lefela simolola() {
    baya_phini(IRILEYI, TSE_DI_TSWANG);
}

lefela boeletsa() {
    kwala_dijithale(IRILEYI, GODIMO);   // vula
    ema(2000);
    kwala_dijithale(IRILEYI, TLASE);    // vala
    ema(2000);
}
