
Kesikli Mod (Burst Mode) Özellikli 8-Bit R-2R DAC Sinyal Jeneratörü

Bu proje, Arduino Mega kullanarak Doğrudan Dijital Sentez (DDS) yöntemiyle 100Hz Sinüs Dalgası üreten bir gömülü sistem uygulamasıdır. Sistem, hesaplanan dijital veriyi analog voltaja çevirmek için 8-bitlik paralel bir arayüz ve harici bir R-2R Direnç Merdiveni (DAC) kullanır.

Yazılım, sürekli sinyal üretmek yerine Zaman Bölüşümlü (Time-Division) bir mantıkla çalışır: 500ms boyunca aktif sinüs sinyali üretirken, takip eden 500ms boyunca sabit DC gerilim (Idle) basar.

-Projenin Teknik Hedefleri
Matematiksel Sinyal Üretimi: Sinyal tablosu (Look-up Table) kullanmak yerine, işlemci gücüyle gerçek zamanlı sin() fonksiyonu hesaplamak.

Paralel Veri İletimi: 8 adet dijital pini senkronize bir şekilde sürerek 8-bit çözünürlük elde etmek.

Zamanlama Yönetimi: delay() fonksiyonu kullanmadan, millis() tabanlı kesintisiz (non-blocking) bir zamanlayıcı mimarisi kurmak.

- Donanım Gereksinimleri
Mikrodenetleyici: Arduino Mega 2560 (Pin 22-29 aralığındaki port yapısı için seçilmiştir).

DAC Devresi: 8-Bit R-2R Direnç Ağı (10kΩ ve 20kΩ hassas dirençler).

Görüntüleme: Osiloskop (Sinyal analizi için).

- Matematiksel Model ve Sinyal İşleme
Sistem, ayrık zamanlı (discrete-time) sinyal denklemini şu formülle işler:
Vout​(t)=Vref/2​​+Vref/2*​​sin(2π⋅f⋅t)


Örnekleme Hızı: 1 kHz (Her 1ms'de bir yeni değer).
Sinyal Frekansı ($f$): 100 Hz.
Çözünürlük: 8-Bit ($0 - 255$ arası dijital değer).
DC Ofset: 127.5 (Sinyali 0-5V aralığının tam ortasına, yani 2.5V merkezine oturtur).
