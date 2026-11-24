// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <Sesotho.h>

e_sa_fetoheng palo I_PIR = 7;
e_sa_fetoheng palo IBHAZA = 6;
e_sa_fetoheng palo ILED = 13;

lefeela qala() {
    beha_phini(I_PIR, TSE_KENANG);
    beha_phini(IBHAZA, TSE_TSWANG);
    beha_phini(ILED, TSE_TSWANG);
    Seriale.qalo(9600);
    Seriale.bontsha_mola("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

lefeela pheta_pheta() {
    haeba (bala_dijithale(I_PIR) == HODIMO) {
        ngola_dijithale(ILED, HODIMO);
        ngola_dijithale(IBHAZA, HODIMO);
        Seriale.bontsha_mola("Kukhona onyakazayo!");
    } ho_seng_jwalo {
        ngola_dijithale(ILED, TLASE);
        ngola_dijithale(IBHAZA, TLASE);
    }
    ema(200);
}
