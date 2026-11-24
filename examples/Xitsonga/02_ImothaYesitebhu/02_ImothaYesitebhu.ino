// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <Xitsonga.h>

lexi_nga_cinciki nomboro IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Njhini_ya_goza imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

swi_hava sungula() {
    imotha.veka_rivilo(10);          // imijikelezo eyi-10 ngomzuzu
    Siriyali.ku_sungula(9600);
}

swi_hava phindha_phindha() {
    Siriyali.kombisa_layini("Ngokwewashi");
    imotha.teka_mikondzo(IZINYATHELO_ZOMJIKELEZO);
    rindza(500);
    Siriyali.kombisa_layini("Ngokuphambene newashi");
    imotha.teka_mikondzo(-IZINYATHELO_ZOMJIKELEZO);
    rindza(500);
}
