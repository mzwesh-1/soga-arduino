// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <Tshivenda.h>

zwi_sa_shanduki nomboro ILED = 9;

a_huna thoma() {
    vhea_phini(ILED, ZWI_BVAHO);
    Siriale.mathomo(9600);
}

a_huna dovholola() {
    nomboro ukukhanya = vhala_analogo(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    nomboro amandla_eled = linganya_hafhu(ukukhanya, 0, 1023, 255, 0);
    nwala_analogo(ILED, thivhela(amandla_eled, 0, 255));
    Siriale.sumbedza("Ukukhanya: ");
    Siriale.sumbedza_mutalo(ukukhanya);
    lindela(100);
}
