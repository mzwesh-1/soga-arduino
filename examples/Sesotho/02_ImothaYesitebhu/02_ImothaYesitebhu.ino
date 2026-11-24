// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <Sesotho.h>

e_sa_fetoheng palo IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Enjene_ya_mohato imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

lefeela qala() {
    imotha.beha_lebelo(10);          // imijikelezo eyi-10 ngomzuzu
    Seriale.qalo(9600);
}

lefeela pheta_pheta() {
    Seriale.bontsha_mola("Ngokwewashi");
    imotha.nka_mehato(IZINYATHELO_ZOMJIKELEZO);
    ema(500);
    Seriale.bontsha_mola("Ngokuphambene newashi");
    imotha.nka_mehato(-IZINYATHELO_ZOMJIKELEZO);
    ema(500);
}
