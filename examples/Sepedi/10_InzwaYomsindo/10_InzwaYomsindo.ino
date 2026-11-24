// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <Sepedi.h>

sa_fetogego palo INZWA = 2;
sa_fetogego palo ILED = 13;
bulini ikhanyile = maaka;
ntle_le_leswao telele isikhathi_sokugcina = 0;

lefeela thoma() {
    bea_phini(INZWA, TSE_TSENAGO);
    bea_phini(ILED, TSE_TSWAGO);
    Seriale.mathomo(9600);
}

lefeela boeletsa() {
    ge (bala_dijithale(INZWA) == GODIMO && dimilisekhontse() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        ngwala_dijithale(ILED, ikhanyile ? GODIMO : FASE);
        isikhathi_sokugcina = dimilisekhontse();
        Seriale.bontsha("Ngizwe umsindo! Izinga: ");
        Seriale.bontsha_mothaladi(bala_analoko(A0));
    }
}
