// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <siSwati.h>

lokungagucuki inombolo INZWA = 2;
lokungagucuki inombolo ILED = 13;
ibhuli ikhanyile = emanga;
lokungenasibonakaliso lokudze isikhathi_sokugcina = 0;

lite cala() {
    setha_liphini(INZWA, LOKUNGENAKO);
    setha_liphini(ILED, LOKUPHUMAKO);
    Siriyali.kucala(9600);
}

lite phindza_phindza() {
    nangabe (fundza_idijithali(INZWA) == PHETULU && emamilisekhondi() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        bhala_idijithali(ILED, ikhanyile ? PHETULU : PHANSI);
        isikhathi_sokugcina = emamilisekhondi();
        Siriyali.khombisa("Ngizwe umsindo! Izinga: ");
        Siriyali.khombisa_umugca(fundza_ianalogi(A0));
    }
}
