// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <Sepedi.h>

sa_fetogego palo IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Enjene_ya_kgato imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

lefeela thoma() {
    imotha.bea_lebelo(10);          // imijikelezo eyi-10 ngomzuzu
    Seriale.mathomo(9600);
}

lefeela boeletsa() {
    Seriale.bontsha_mothaladi("Ngokwewashi");
    imotha.tsea_dikgato(IZINYATHELO_ZOMJIKELEZO);
    leta(500);
    Seriale.bontsha_mothaladi("Ngokuphambene newashi");
    imotha.tsea_dikgato(-IZINYATHELO_ZOMJIKELEZO);
    leta(500);
}
