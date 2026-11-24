// Imotha yesitebhu 28BYJ-48 nebhodi le-ULN2003: ijika umjikelezo owodwa, ibuye emuva.
// Ukuxhuma: IN1 -> 8, IN2 -> 9, IN3 -> 10, IN4 -> 11, + -> 5V, - -> GND
#include <Stepper.h>
#include <isiZulu.h>

engaguquki inombolo IZINYATHELO_ZOMJIKELEZO = 2048;   // izinyathelo zomjikelezo owodwa
Imotha_yesitebhu imotha(IZINYATHELO_ZOMJIKELEZO, 8, 10, 9, 11);

ize qala() {
    imotha.setha_ijubane(10);          // imijikelezo eyi-10 ngomzuzu
    Isiriyeli.ukuqala(9600);
}

ize phindaphinda() {
    Isiriyeli.bonisa_umugqa("Ngokwewashi");
    imotha.thatha_izinyathelo(IZINYATHELO_ZOMJIKELEZO);
    linda(500);
    Isiriyeli.bonisa_umugqa("Ngokuphambene newashi");
    imotha.thatha_izinyathelo(-IZINYATHELO_ZOMJIKELEZO);
    linda(500);
}
