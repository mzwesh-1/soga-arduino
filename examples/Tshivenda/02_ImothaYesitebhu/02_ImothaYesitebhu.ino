// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <Tshivenda.h>

zwi_sa_shanduki nomboro IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Mutshini_wa_khwatha imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

a_huna thoma() {
    imotha.vhea_tsimbilo(10);          // imijikelezo eyi-10 ngomzuzu
    Siriale.mathomo(9600);
}

a_huna dovholola() {
    Siriale.sumbedza_mutalo("Ngokwewashi");
    imotha.dzhia_khwatha(IZINYATHELO_ZOMJIKELEZO);
    lindela(500);
    Siriale.sumbedza_mutalo("Ngokuphambene newashi");
    imotha.dzhia_khwatha(-IZINYATHELO_ZOMJIKELEZO);
    lindela(500);
}
