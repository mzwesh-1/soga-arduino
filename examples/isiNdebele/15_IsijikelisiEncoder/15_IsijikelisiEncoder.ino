// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <isiNdebele.h>

okungatjhugulukiko inomboro I_CLK = 2;
okungatjhugulukiko inomboro I_DT = 3;
okungatjhugulukiko inomboro I_SW = 4;
okutjhugulukako_kakhulu inomboro isibali = 0;
inomboro isibali_esidala = 0;

ilize uma_kujikiwe() {
    nangabe (funda_idijithali(I_DT) != funda_idijithali(I_CLK)) isibali++;   // ngokwewashi
    ngokunye isibali--;                                               // ngokuphambene
}

ilize thoma() {
    beka_iphini(I_CLK, OKUNGENAKO);
    beka_iphini(I_DT, OKUNGENAKO);
    beka_iphini(I_SW, OKUNGENAKO_KUDONSIWE);
    Isiriyali.ukuthoma(9600);
    namathelisa_ukuphazamiseka(iphini_uye_ekuphazamisekeni(I_CLK), uma_kujikiwe, NAKUTJHUGULUKA);
}

ilize phinda_phinda() {
    nangabe (funda_idijithali(I_SW) == PHASI) {
        isibali = 0;
        lindela(200);
    }
    nangabe (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Isiriyali.khombisa("Isibali: ");
        Isiriyali.khombisa_umugqa(isibali);
    }
}
