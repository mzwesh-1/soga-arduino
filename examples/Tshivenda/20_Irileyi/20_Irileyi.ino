// I-relay ye-5V: ivula futhi ivale umjikelezo wesibili njalo ngemizuzwana emi-2 (uzwa "klik").
// Ukuxhuma: IN -> 7, VCC -> 5V, GND -> GND.  QAPHELA: ungaxhumi ugesi wendlu (230V) uma ungenalo ulwazi!
#include <Tshivenda.h>

zwi_sa_shanduki nomboro IRILEYI = 7;

a_huna thoma() {
    vhea_phini(IRILEYI, ZWI_BVAHO);
}

a_huna dovholola() {
    nwala_didzhithala(IRILEYI, NTHA);   // vula
    lindela(2000);
    nwala_didzhithala(IRILEYI, FHASI);    // vala
    lindela(2000);
}
