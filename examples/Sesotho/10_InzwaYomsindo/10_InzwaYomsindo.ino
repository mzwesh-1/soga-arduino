// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <Sesotho.h>

e_sa_fetoheng palo INZWA = 2;
e_sa_fetoheng palo ILED = 13;
bulini ikhanyile = leshano;
e_se_nang_tshwayo telele isikhathi_sokugcina = 0;

lefeela qala() {
    beha_phini(INZWA, TSE_KENANG);
    beha_phini(ILED, TSE_TSWANG);
    Seriale.qalo(9600);
}

lefeela pheta_pheta() {
    haeba (bala_dijithale(INZWA) == HODIMO && dimilisekonde() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        ngola_dijithale(ILED, ikhanyile ? HODIMO : TLASE);
        isikhathi_sokugcina = dimilisekonde();
        Seriale.bontsha("Ngizwe umsindo! Izinga: ");
        Seriale.bontsha_mola(bala_analoko(A0));
    }
}
