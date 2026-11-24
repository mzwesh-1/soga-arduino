// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <Setswana.h>

e_sa_fetogeng palo IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Enjene_ya_kgato imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

lefela simolola() {
    imotha.baya_lobelo(10);          // imijikelezo eyi-10 ngomzuzu
    Seriale.tshimologo(9600);
}

lefela boeletsa() {
    Seriale.bontsha_mola("Ngokwewashi");
    imotha.tsaya_dikgato(IZINYATHELO_ZOMJIKELEZO);
    ema(500);
    Seriale.bontsha_mola("Ngokuphambene newashi");
    imotha.tsaya_dikgato(-IZINYATHELO_ZOMJIKELEZO);
    ema(500);
}
