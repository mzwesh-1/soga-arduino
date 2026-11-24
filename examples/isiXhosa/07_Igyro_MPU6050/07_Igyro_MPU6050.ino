// GY-521 MPU-6050: ifunda ukusheshisa (accelerometer) nokujika (gyroscope) ezinhlangothini ezi-3.
// Ukuxhuma ku-Mega: VCC -> 5V, GND -> GND, SDA -> 20, SCL -> 21
#include <Wire.h>
#include <isiXhosa.h>

engatshintshiyo inani IKHELI_LE_MPU = 0x68;

inani16 funda_amabhayithi_amabili() {
    inani16 phezulu = Ucingo.funda_ibhayithi();
    buyisa (phezulu << 8) | Ucingo.funda_ibhayithi();
}

ize qalisa() {
    Isiriyali.ukuqala(9600);
    Ucingo.ukuqala();
    Ucingo.qala_ukuthumela(IKHELI_LE_MPU);
    Ucingo.bhala_ibhayithi(0x6B);          // irejista yamandla
    Ucingo.bhala_ibhayithi(0);             // vusa i-MPU-6050
    Ucingo.gqiba_ukuthumela(inyani);
}

ize phinda_phinda() {
    Ucingo.qala_ukuthumela(IKHELI_LE_MPU);
    Ucingo.bhala_ibhayithi(0x3B);          // qala kurejista ye-accelerometer
    Ucingo.gqiba_ukuthumela(ubuxoki);
    Ucingo.cela_ku(IKHELI_LE_MPU, 14, inyani);
    inani16 ax = funda_amabhayithi_amabili(), ay = funda_amabhayithi_amabili(), az = funda_amabhayithi_amabili();
    inani16 ukushisa = funda_amabhayithi_amabili();
    inani16 gx = funda_amabhayithi_amabili(), gy = funda_amabhayithi_amabili(), gz = funda_amabhayithi_amabili();

    Isiriyali.bonisa("Ukusheshisa X/Y/Z: ");
    Isiriyali.bonisa(ax); Isiriyali.bonisa(" "); Isiriyali.bonisa(ay); Isiriyali.bonisa(" "); Isiriyali.bonisa(az);
    Isiriyali.bonisa("   Ukujika X/Y/Z: ");
    Isiriyali.bonisa(gx); Isiriyali.bonisa(" "); Isiriyali.bonisa(gy); Isiriyali.bonisa(" "); Isiriyali.bonisa(gz);
    Isiriyali.bonisa("   Ukushisa: ");
    Isiriyali.bonisa_umgca(ukushisa / 340.0 + 36.53);
    linda(500);
}
