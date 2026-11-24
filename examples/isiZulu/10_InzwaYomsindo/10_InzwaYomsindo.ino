// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <isiZulu.h>

engaguquki inombolo INZWA = 2;
engaguquki inombolo ILED = 13;
ibhuli ikhanyile = amanga;
ongenaphawu ende isikhathi_sokugcina = 0;

ize qala() {
    setha_iphini(INZWA, OKUNGENAYO);
    setha_iphini(ILED, OKUPHUMAYO);
    Isiriyeli.ukuqala(9600);
}

ize phindaphinda() {
    uma (funda_idijithali(INZWA) == PHEZULU && amamilisekhondi() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        bhala_idijithali(ILED, ikhanyile ? PHEZULU : PHANSI);
        isikhathi_sokugcina = amamilisekhondi();
        Isiriyeli.bonisa("Ngizwe umsindo! Izinga: ");
        Isiriyeli.bonisa_umugqa(funda_ianalogi(A0));
    }
}
