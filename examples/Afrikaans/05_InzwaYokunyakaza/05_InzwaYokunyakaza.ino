// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <Afrikaans.h>

konstant heelgetal I_PIR = 7;
konstant heelgetal IBHAZA = 6;
konstant heelgetal ILED = 13;

leeg opstel() {
    penmodus(I_PIR, INSET);
    penmodus(IBHAZA, UITSET);
    penmodus(ILED, UITSET);
    Seriaal.begin(9600);
    Seriaal.drukreel("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

leeg lus() {
    as (leesdigitaal(I_PIR) == HOOG) {
        skryfdigitaal(ILED, HOOG);
        skryfdigitaal(IBHAZA, HOOG);
        Seriaal.drukreel("Kukhona onyakazayo!");
    } anders {
        skryfdigitaal(ILED, LAAG);
        skryfdigitaal(IBHAZA, LAAG);
    }
    wag(200);
}
