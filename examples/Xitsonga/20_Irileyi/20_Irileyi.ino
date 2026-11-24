// I-relay ye-5V: ivula futhi ivale umjikelezo wesibili njalo ngemizuzwana emi-2 (uzwa "klik").
// Ukuxhuma: IN -> 7, VCC -> 5V, GND -> GND.  QAPHELA: ungaxhumi ugesi wendlu (230V) uma ungenalo ulwazi!
#include <Xitsonga.h>

lexi_nga_cinciki nomboro IRILEYI = 7;

swi_hava sungula() {
    veka_phini(IRILEYI, LESWI_HUMAKA);
}

swi_hava phindha_phindha() {
    tsala_dijitali(IRILEYI, HENHLA);   // vula
    rindza(2000);
    tsala_dijitali(IRILEYI, HANSI);    // vala
    rindza(2000);
}
