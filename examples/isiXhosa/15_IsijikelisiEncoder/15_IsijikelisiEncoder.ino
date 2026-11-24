// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <isiXhosa.h>

engatshintshiyo inani I_CLK = 2;
engatshintshiyo inani I_DT = 3;
engatshintshiyo inani I_SW = 4;
eguquguqukayo inani isibali = 0;
inani isibali_esidala = 0;

ize uma_kujikiwe() {
    ukuba (funda_idijithali(I_DT) != funda_idijithali(I_CLK)) isibali++;   // ngokwewashi
    kungenjalo isibali--;                                               // ngokuphambene
}

ize qalisa() {
    misela_iphini(I_CLK, OKUNGENAYO);
    misela_iphini(I_DT, OKUNGENAYO);
    misela_iphini(I_SW, OKUNGENAYO_KUTSALWE);
    Isiriyali.ukuqala(9600);
    ncamathisela_uphazamiso(iphini_ukuya_kuphazamiso(I_CLK), uma_kujikiwe, XA_KUTSHINTSHA);
}

ize phinda_phinda() {
    ukuba (funda_idijithali(I_SW) == EZANTSI) {
        isibali = 0;
        linda(200);
    }
    ukuba (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Isiriyali.bonisa("Isibali: ");
        Isiriyali.bonisa_umgca(isibali);
    }
}
