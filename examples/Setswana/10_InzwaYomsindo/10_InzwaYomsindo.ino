// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <Setswana.h>

e_sa_fetogeng palo INZWA = 2;
e_sa_fetogeng palo ILED = 13;
bulini ikhanyile = maaka;
e_se_na_tshwao leele isikhathi_sokugcina = 0;

lefela simolola() {
    baya_phini(INZWA, TSE_DI_TSENANG);
    baya_phini(ILED, TSE_DI_TSWANG);
    Seriale.tshimologo(9600);
}

lefela boeletsa() {
    fa (bala_dijithale(INZWA) == GODIMO && dimilisekonte() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        kwala_dijithale(ILED, ikhanyile ? GODIMO : TLASE);
        isikhathi_sokugcina = dimilisekonte();
        Seriale.bontsha("Ngizwe umsindo! Izinga: ");
        Seriale.bontsha_mola(bala_analoko(A0));
    }
}
