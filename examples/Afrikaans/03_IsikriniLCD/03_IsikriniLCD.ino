// Isikrini se-LCD1602: sibonisa "Sawubona Mhlaba!" nemizuzwana edlulile.
// Ukuxhuma: RS -> 7, E -> 8, D4 -> 9, D5 -> 10, D6 -> 11, D7 -> 12, RW -> GND,
//           V0 -> phakathi kwe-potentiometer, VSS -> GND, VDD -> 5V, A -> 5V (220 ohm), K -> GND
#include <LiquidCrystal.h>
#include <Afrikaans.h>

Teksskerm isikrini(7, 8, 9, 10, 11, 12);

leeg opstel() {
    isikrini.begin(16, 2);               // izinhlamvu eziyi-16, imigqa emi-2
    isikrini.druk("Sawubona Mhlaba!");
}

leeg lus() {
    isikrini.stel_wyser(0, 1);           // ikholomu 0, umugqa 1
    isikrini.druk("Imizuzwana: ");
    isikrini.druk(millisekondes() / 1000);
    wag(200);
}
