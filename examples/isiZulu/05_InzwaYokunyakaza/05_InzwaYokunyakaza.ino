// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <isiZulu.h>

engaguquki inombolo I_PIR = 7;
engaguquki inombolo IBHAZA = 6;
engaguquki inombolo ILED = 13;

ize qala() {
    setha_iphini(I_PIR, OKUNGENAYO);
    setha_iphini(IBHAZA, OKUPHUMAYO);
    setha_iphini(ILED, OKUPHUMAYO);
    Isiriyeli.ukuqala(9600);
    Isiriyeli.bonisa_umugqa("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

ize phindaphinda() {
    uma (funda_idijithali(I_PIR) == PHEZULU) {
        bhala_idijithali(ILED, PHEZULU);
        bhala_idijithali(IBHAZA, PHEZULU);
        Isiriyeli.bonisa_umugqa("Kukhona onyakazayo!");
    } kungenjalo {
        bhala_idijithali(ILED, PHANSI);
        bhala_idijithali(IBHAZA, PHANSI);
    }
    linda(200);
}
