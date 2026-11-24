// GY-521 MPU-6050: ifunda ukusheshisa (accelerometer) nokujika (gyroscope) ezinhlangothini ezi-3.
// Ukuxhuma ku-Mega: VCC -> 5V, GND -> GND, SDA -> 20, SCL -> 21
#include <Wire.h>
#include <isiNdebele.h>

okungatjhugulukiko inomboro IKHELI_LE_MPU = 0x68;

inomboro16 funda_amabhayithi_amabili() {
    inomboro16 phezulu = Ucingo.funda_ibhayithi();
    buyisa (phezulu << 8) | Ucingo.funda_ibhayithi();
}

ilize thoma() {
    Isiriyali.ukuthoma(9600);
    Ucingo.ukuthoma();
    Ucingo.thoma_ukuthumela(IKHELI_LE_MPU);
    Ucingo.tlola_ibhayithi(0x6B);          // irejista yamandla
    Ucingo.tlola_ibhayithi(0);             // vusa i-MPU-6050
    Ucingo.qeda_ukuthumela(iqiniso);
}

ilize phinda_phinda() {
    Ucingo.thoma_ukuthumela(IKHELI_LE_MPU);
    Ucingo.tlola_ibhayithi(0x3B);          // qala kurejista ye-accelerometer
    Ucingo.qeda_ukuthumela(amala);
    Ucingo.bawa_ku(IKHELI_LE_MPU, 14, iqiniso);
    inomboro16 ax = funda_amabhayithi_amabili(), ay = funda_amabhayithi_amabili(), az = funda_amabhayithi_amabili();
    inomboro16 ukushisa = funda_amabhayithi_amabili();
    inomboro16 gx = funda_amabhayithi_amabili(), gy = funda_amabhayithi_amabili(), gz = funda_amabhayithi_amabili();

    Isiriyali.khombisa("Ukusheshisa X/Y/Z: ");
    Isiriyali.khombisa(ax); Isiriyali.khombisa(" "); Isiriyali.khombisa(ay); Isiriyali.khombisa(" "); Isiriyali.khombisa(az);
    Isiriyali.khombisa("   Ukujika X/Y/Z: ");
    Isiriyali.khombisa(gx); Isiriyali.khombisa(" "); Isiriyali.khombisa(gy); Isiriyali.khombisa(" "); Isiriyali.khombisa(gz);
    Isiriyali.khombisa("   Ukushisa: ");
    Isiriyali.khombisa_umugqa(ukushisa / 340.0 + 36.53);
    lindela(500);
}
