// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <isiXhosa.h>

engatshintshiyo inani I_PIR = 7;
engatshintshiyo inani IBHAZA = 6;
engatshintshiyo inani ILED = 13;

ize qalisa() {
    misela_iphini(I_PIR, OKUNGENAYO);
    misela_iphini(IBHAZA, OKUPHUMAYO);
    misela_iphini(ILED, OKUPHUMAYO);
    Isiriyali.ukuqala(9600);
    Isiriyali.bonisa_umgca("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

ize phinda_phinda() {
    ukuba (funda_idijithali(I_PIR) == PHEZULU) {
        bhala_idijithali(ILED, PHEZULU);
        bhala_idijithali(IBHAZA, PHEZULU);
        Isiriyali.bonisa_umgca("Kukhona onyakazayo!");
    } kungenjalo {
        bhala_idijithali(ILED, EZANTSI);
        bhala_idijithali(IBHAZA, EZANTSI);
    }
    linda(200);
}
