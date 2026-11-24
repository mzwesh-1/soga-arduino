// I-relay ye-5V: ivula futhi ivale umjikelezo wesibili njalo ngemizuzwana emi-2 (uzwa "klik").
// Ukuxhuma: IN -> 7, VCC -> 5V, GND -> GND.  QAPHELA: ungaxhumi ugesi wendlu (230V) uma ungenalo ulwazi!
#include <Sesotho.h>

e_sa_fetoheng palo IRILEYI = 7;

lefeela qala() {
    beha_phini(IRILEYI, TSE_TSWANG);
}

lefeela pheta_pheta() {
    ngola_dijithale(IRILEYI, HODIMO);   // vula
    ema(2000);
    ngola_dijithale(IRILEYI, TLASE);    // vala
    ema(2000);
}
