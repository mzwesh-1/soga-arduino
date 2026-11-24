// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <Tshivenda.h>

zwi_sa_shanduki nomboro INKINOBHO_A = 9;
zwi_sa_shanduki nomboro INKINOBHO_B = 8;
zwi_sa_shanduki nomboro ILED = 5;

a_huna thoma() {
    vhea_phini(INKINOBHO_A, ZWI_DZHENAHO_NGA_U_KOKA);
    vhea_phini(INKINOBHO_B, ZWI_DZHENAHO_NGA_U_KOKA);
    vhea_phini(ILED, ZWI_BVAHO);
}

a_huna dovholola() {
    arali (vhala_didzhithala(INKINOBHO_A) == FHASI) nwala_didzhithala(ILED, NTHA);
    arali (vhala_didzhithala(INKINOBHO_B) == FHASI) nwala_didzhithala(ILED, FHASI);
}
