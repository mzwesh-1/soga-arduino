// Ibhaza elingasebenzi ngokwalo (passive): lidlala iculo elifushane.
// Ukuxhuma: + -> 8, - -> GND
#include <Tshivenda.h>

zwi_sa_shanduki nomboro IBHAZA = 8;
// Amanothi: C D E F G A B C (Hz)
nomboro amanothi[] = {262, 294, 330, 349, 392, 440, 494, 523};
nomboro isikhathi_senothi[] = {250, 250, 250, 250, 250, 250, 250, 500};

a_huna thoma() {
    mona (nomboro i = 0; i < 8; i++) {
        mubvumo(IBHAZA, amanothi[i], isikhathi_senothi[i]);
        lindela(isikhathi_senothi[i] * 1.3);
    }
    imisa_mubvumo(IBHAZA);
}

a_huna dovholola() {
    // Iculo lidlala kanye kuphela. Cindezela u-RESET ukuze uphinde ulizwe.
}
