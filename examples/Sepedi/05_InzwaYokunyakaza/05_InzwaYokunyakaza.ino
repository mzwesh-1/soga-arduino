// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <Sepedi.h>

sa_fetogego palo I_PIR = 7;
sa_fetogego palo IBHAZA = 6;
sa_fetogego palo ILED = 13;

lefeela thoma() {
    bea_phini(I_PIR, TSE_TSENAGO);
    bea_phini(IBHAZA, TSE_TSWAGO);
    bea_phini(ILED, TSE_TSWAGO);
    Seriale.mathomo(9600);
    Seriale.bontsha_mothaladi("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

lefeela boeletsa() {
    ge (bala_dijithale(I_PIR) == GODIMO) {
        ngwala_dijithale(ILED, GODIMO);
        ngwala_dijithale(IBHAZA, GODIMO);
        Seriale.bontsha_mothaladi("Kukhona onyakazayo!");
    } go_sego_bjalo {
        ngwala_dijithale(ILED, FASE);
        ngwala_dijithale(IBHAZA, FASE);
    }
    leta(200);
}
