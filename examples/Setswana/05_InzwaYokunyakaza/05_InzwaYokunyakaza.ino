// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <Setswana.h>

e_sa_fetogeng palo I_PIR = 7;
e_sa_fetogeng palo IBHAZA = 6;
e_sa_fetogeng palo ILED = 13;

lefela simolola() {
    baya_phini(I_PIR, TSE_DI_TSENANG);
    baya_phini(IBHAZA, TSE_DI_TSWANG);
    baya_phini(ILED, TSE_DI_TSWANG);
    Seriale.tshimologo(9600);
    Seriale.bontsha_mola("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

lefela boeletsa() {
    fa (bala_dijithale(I_PIR) == GODIMO) {
        kwala_dijithale(ILED, GODIMO);
        kwala_dijithale(IBHAZA, GODIMO);
        Seriale.bontsha_mola("Kukhona onyakazayo!");
    } go_seng_jalo {
        kwala_dijithale(ILED, TLASE);
        kwala_dijithale(IBHAZA, TLASE);
    }
    ema(200);
}
