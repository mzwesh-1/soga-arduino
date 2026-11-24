// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <siSwati.h>

lokungagucuki inombolo I_PIR = 7;
lokungagucuki inombolo IBHAZA = 6;
lokungagucuki inombolo ILED = 13;

lite cala() {
    setha_liphini(I_PIR, LOKUNGENAKO);
    setha_liphini(IBHAZA, LOKUPHUMAKO);
    setha_liphini(ILED, LOKUPHUMAKO);
    Siriyali.kucala(9600);
    Siriyali.khombisa_umugca("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

lite phindza_phindza() {
    nangabe (fundza_idijithali(I_PIR) == PHETULU) {
        bhala_idijithali(ILED, PHETULU);
        bhala_idijithali(IBHAZA, PHETULU);
        Siriyali.khombisa_umugca("Kukhona onyakazayo!");
    } ngalokunye {
        bhala_idijithali(ILED, PHANSI);
        bhala_idijithali(IBHAZA, PHANSI);
    }
    lindza(200);
}
