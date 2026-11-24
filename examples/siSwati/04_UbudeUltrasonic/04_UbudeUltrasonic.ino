// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <siSwati.h>

lokungagucuki inombolo ITRIG = 12;
lokungagucuki inombolo IECHO = 11;

lite cala() {
    Siriyali.kucala(9600);
    setha_liphini(ITRIG, LOKUPHUMAKO);
    setha_liphini(IECHO, LOKUNGENAKO);
}

ideshimali linganisa_ibanga() {
    bhala_idijithali(ITRIG, PHANSI);
    lindza_emamayikhro(2);
    bhala_idijithali(ITRIG, PHETULU);      // thumela umsindo isikhathi esingu-10 us
    lindza_emamayikhro(10);
    bhala_idijithali(ITRIG, PHANSI);
    lokungenasibonakaliso lokudze isikhathi_sokubuya = linganisa_liphalsi(IECHO, PHETULU, 30000);
    buyisa isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

lite phindza_phindza() {
    ideshimali ibanga = linganisa_ibanga();
    nangabe (ibanga == 0) {
        Siriyali.khombisa_umugca("Ayikho into ebangeni");
    } ngalokunye {
        Siriyali.khombisa("Ibanga: ");
        Siriyali.khombisa(ibanga);
        Siriyali.khombisa_umugca(" cm");
    }
    lindza(500);
}
