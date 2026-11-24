// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <Afrikaans.h>

konstant heelgetal ILED = 13;

leeg opstel() {
    Seriaal.begin(9600);
    penmodus(ILED, UITSET);
    IR_Ontvanger.begin(11, LED_TERUGVOER_AAN);
    Seriaal.drukreel("Cindezela inkinobho kurimothi...");
}

leeg lus() {
    as (IR_Ontvanger.dekodeer()) {
        greep umyalo_wenkinobho = IR_Ontvanger.gedekodeerde_data.opdrag;
        Seriaal.druk("Inkinobho: 0x");
        Seriaal.drukreel(umyalo_wenkinobho, HEKSADESIMAAL);
        kies (umyalo_wenkinobho) {
            geval 0x0C: skryfdigitaal(ILED, HOOG); breek;   // "1" kurimothi encane
            geval 0x18: skryfdigitaal(ILED, LAAG);  breek;   // "2"
            verstek: breek;
        }
        IR_Ontvanger.hervat();
    }
}
