// Isikrini se-LCD1602: sibonisa "Sawubona Mhlaba!" nemizuzwana edlulile.
// Ukuxhuma: RS -> 7, E -> 8, D4 -> 9, D5 -> 10, D6 -> 11, D7 -> 12, RW -> GND,
//           V0 -> phakathi kwe-potentiometer, VSS -> GND, VDD -> 5V, A -> 5V (220 ohm), K -> GND
#include <LiquidCrystal.h>
#include <isiZulu.h>

Isikrini_sombhalo isikrini(7, 8, 9, 10, 11, 12);

ize qala() {
    isikrini.ukuqala(16, 2);               // izinhlamvu eziyi-16, imigqa emi-2
    isikrini.bonisa("Sawubona Mhlaba!");
}

ize phindaphinda() {
    isikrini.setha_ikhesa(0, 1);           // ikholomu 0, umugqa 1
    isikrini.bonisa("Imizuzwana: ");
    isikrini.bonisa(amamilisekhondi() / 1000);
    linda(200);
}
