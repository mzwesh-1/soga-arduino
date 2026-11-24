// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <isiXhosa.h>

engatshintshiyo inani INZWA = 2;
engatshintshiyo inani ILED = 13;
ibhuli ikhanyile = ubuxoki;
engenaphawu ende isikhathi_sokugcina = 0;

ize qalisa() {
    misela_iphini(INZWA, OKUNGENAYO);
    misela_iphini(ILED, OKUPHUMAYO);
    Isiriyali.ukuqala(9600);
}

ize phinda_phinda() {
    ukuba (funda_idijithali(INZWA) == PHEZULU && iimilisekondi() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        bhala_idijithali(ILED, ikhanyile ? PHEZULU : EZANTSI);
        isikhathi_sokugcina = iimilisekondi();
        Isiriyali.bonisa("Ngizwe umsindo! Izinga: ");
        Isiriyali.bonisa_umgca(funda_ianalogu(A0));
    }
}
