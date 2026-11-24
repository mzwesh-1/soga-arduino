// Inzwa yomsindo: shaya izandla, i-LED iyakhanya / iyacima.
// Ukuxhuma: DO -> 2, AO -> A0, + -> 5V, G -> GND; i-LED -> 13. Jika i-potentiometer eluhlaza ukulungisa ukuzwela.
#include <Tshivenda.h>

zwi_sa_shanduki nomboro INZWA = 2;
zwi_sa_shanduki nomboro ILED = 13;
buliani ikhanyile = mazwifhi;
hu_si_na_tshiga lapfu isikhathi_sokugcina = 0;

a_huna thoma() {
    vhea_phini(INZWA, ZWI_DZHENAHO);
    vhea_phini(ILED, ZWI_BVAHO);
    Siriale.mathomo(9600);
}

a_huna dovholola() {
    arali (vhala_didzhithala(INZWA) == NTHA && milisekhondo() - isikhathi_sokugcina > 300) {
        ikhanyile = !ikhanyile;
        nwala_didzhithala(ILED, ikhanyile ? NTHA : FHASI);
        isikhathi_sokugcina = milisekhondo();
        Siriale.sumbedza("Ngizwe umsindo! Izinga: ");
        Siriale.sumbedza_mutalo(vhala_analogo(A0));
    }
}
