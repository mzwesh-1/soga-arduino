// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <isiNdebele.h>

okungatjhugulukiko inomboro ITRIG = 12;
okungatjhugulukiko inomboro IECHO = 11;

ilize thoma() {
    Isiriyali.ukuthoma(9600);
    beka_iphini(ITRIG, OKUPHUMAKO);
    beka_iphini(IECHO, OKUNGENAKO);
}

idesimali linganisa_ibanga() {
    tlola_idijithali(ITRIG, PHASI);
    lindela_amamayikhro(2);
    tlola_idijithali(ITRIG, PHEZULU);      // thumela umsindo isikhathi esingu-10 us
    lindela_amamayikhro(10);
    tlola_idijithali(ITRIG, PHASI);
    okungenatshwayo okude isikhathi_sokubuya = linganisa_iphalsi(IECHO, PHEZULU, 30000);
    buyisa isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

ilize phinda_phinda() {
    idesimali ibanga = linganisa_ibanga();
    nangabe (ibanga == 0) {
        Isiriyali.khombisa_umugqa("Ayikho into ebangeni");
    } ngokunye {
        Isiriyali.khombisa("Ibanga: ");
        Isiriyali.khombisa(ibanga);
        Isiriyali.khombisa_umugqa(" cm");
    }
    lindela(500);
}
