// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <isiXhosa.h>

engatshintshiyo inani ITRIG = 12;
engatshintshiyo inani IECHO = 11;

ize qalisa() {
    Isiriyali.ukuqala(9600);
    misela_iphini(ITRIG, OKUPHUMAYO);
    misela_iphini(IECHO, OKUNGENAYO);
}

idesimali linganisa_ibanga() {
    bhala_idijithali(ITRIG, EZANTSI);
    linda_iimayikhro(2);
    bhala_idijithali(ITRIG, PHEZULU);      // thumela umsindo isikhathi esingu-10 us
    linda_iimayikhro(10);
    bhala_idijithali(ITRIG, EZANTSI);
    engenaphawu ende isikhathi_sokubuya = linganisa_ipalsi(IECHO, PHEZULU, 30000);
    buyisa isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

ize phinda_phinda() {
    idesimali ibanga = linganisa_ibanga();
    ukuba (ibanga == 0) {
        Isiriyali.bonisa_umgca("Ayikho into ebangeni");
    } kungenjalo {
        Isiriyali.bonisa("Ibanga: ");
        Isiriyali.bonisa(ibanga);
        Isiriyali.bonisa_umgca(" cm");
    }
    linda(500);
}
