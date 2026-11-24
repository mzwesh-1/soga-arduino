// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <Afrikaans.h>

konstant heelgetal INZWA = 2;
konstant heelgetal ILED = 13;
boolees ikhanyile = vals;
ongeteken lank isikhathi_sokugcina = 0;

leeg opstel() {
    penmodus(INZWA, INSET);
    penmodus(ILED, UITSET);
    Seriaal.begin(9600);
}

leeg lus() {
    as (leesdigitaal(INZWA) == HOOG && millisekondes() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        skryfdigitaal(ILED, ikhanyile ? HOOG : LAAG);
        isikhathi_sokugcina = millisekondes();
        Seriaal.druk("Ngizwe umsindo! Izinga: ");
        Seriaal.drukreel(leesanaloog(A0));
    }
}
