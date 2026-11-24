// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <isiZulu.h>

engaguquki inombolo ITRIG = 12;
engaguquki inombolo IECHO = 11;

ize qala() {
    Isiriyeli.ukuqala(9600);
    setha_iphini(ITRIG, OKUPHUMAYO);
    setha_iphini(IECHO, OKUNGENAYO);
}

idesimali linganisa_ibanga() {
    bhala_idijithali(ITRIG, PHANSI);
    linda_amamayikhro(2);
    bhala_idijithali(ITRIG, PHEZULU);      // thumela umsindo isikhathi esingu-10 us
    linda_amamayikhro(10);
    bhala_idijithali(ITRIG, PHANSI);
    ongenaphawu ende isikhathi_sokubuya = linganisa_ipulse(IECHO, PHEZULU, 30000);
    buyisa isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

ize phindaphinda() {
    idesimali ibanga = linganisa_ibanga();
    uma (ibanga == 0) {
        Isiriyeli.bonisa_umugqa("Ayikho into ebangeni");
    } kungenjalo {
        Isiriyeli.bonisa("Ibanga: ");
        Isiriyeli.bonisa(ibanga);
        Isiriyeli.bonisa_umugqa(" cm");
    }
    linda(500);
}
