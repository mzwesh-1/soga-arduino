// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <Afrikaans.h>

konstant heelgetal I_CLK = 2;
konstant heelgetal I_DT = 3;
konstant heelgetal I_SW = 4;
vlugtig heelgetal isibali = 0;
heelgetal isibali_esidala = 0;

leeg uma_kujikiwe() {
    as (leesdigitaal(I_DT) != leesdigitaal(I_CLK)) isibali++;   // ngokwewashi
    anders isibali--;                                               // ngokuphambene
}

leeg opstel() {
    penmodus(I_CLK, INSET);
    penmodus(I_DT, INSET);
    penmodus(I_SW, INSET_OPTREK);
    Seriaal.begin(9600);
    hegonderbreking(pen_na_onderbreking(I_CLK), uma_kujikiwe, VERANDER);
}

leeg lus() {
    as (leesdigitaal(I_SW) == LAAG) {
        isibali = 0;
        wag(200);
    }
    as (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Seriaal.druk("Isibali: ");
        Seriaal.drukreel(isibali);
    }
}
