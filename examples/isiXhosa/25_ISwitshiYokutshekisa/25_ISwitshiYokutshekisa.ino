// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <isiXhosa.h>

engatshintshiyo inani ITILT = 2;
engatshintshiyo inani ILED = 13;

ize qalisa() {
    misela_iphini(ITILT, OKUNGENAYO_KUTSALWE);
    misela_iphini(ILED, OKUPHUMAYO);
    Isiriyali.ukuqala(9600);
}

ize phinda_phinda() {
    ukuba (funda_idijithali(ITILT) == EZANTSI) {
        bhala_idijithali(ILED, EZANTSI);
    } kungenjalo {
        bhala_idijithali(ILED, PHEZULU);
        Isiriyali.bonisa_umgca("Kutshekile!");
    }
    linda(100);
}
