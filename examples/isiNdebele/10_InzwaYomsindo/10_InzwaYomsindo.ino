// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <isiNdebele.h>

okungatjhugulukiko inomboro INZWA = 2;
okungatjhugulukiko inomboro ILED = 13;
ibhuli ikhanyile = amala;
okungenatshwayo okude isikhathi_sokugcina = 0;

ilize thoma() {
    beka_iphini(INZWA, OKUNGENAKO);
    beka_iphini(ILED, OKUPHUMAKO);
    Isiriyali.ukuthoma(9600);
}

ilize phinda_phinda() {
    nangabe (funda_idijithali(INZWA) == PHEZULU && amamilisekhondi() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        tlola_idijithali(ILED, ikhanyile ? PHEZULU : PHASI);
        isikhathi_sokugcina = amamilisekhondi();
        Isiriyali.khombisa("Ngizwe umsindo! Izinga: ");
        Isiriyali.khombisa_umugqa(funda_ianalogi(A0));
    }
}
