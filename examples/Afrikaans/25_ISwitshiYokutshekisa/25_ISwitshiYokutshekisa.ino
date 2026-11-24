// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <Afrikaans.h>

konstant heelgetal ITILT = 2;
konstant heelgetal ILED = 13;

leeg opstel() {
    penmodus(ITILT, INSET_OPTREK);
    penmodus(ILED, UITSET);
    Seriaal.begin(9600);
}

leeg lus() {
    as (leesdigitaal(ITILT) == LAAG) {
        skryfdigitaal(ILED, LAAG);
    } anders {
        skryfdigitaal(ILED, HOOG);
        Seriaal.drukreel("Kutshekile!");
    }
    wag(100);
}
