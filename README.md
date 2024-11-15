
# KediGör 🐾

**KediGör**, Arduino tabanlı bir sensör sistemi ile pencerelerinize yaklaşan kedileri algılayan ve görsel/işitsel uyarılar veren bir proje. Bu uygulama, birden fazla sensör kullanarak pencerelerinizi izler ve her pencereye özel LED göstergesi ile hangi pencerede hareket olduğunu bildirir.

---

## Özellikler ✨
- **Ultrasonik Sensör Tabanlı Algılama**: HC-SR04 sensörleri ile mesafe ölçümü yaparak kedileri algılar.
- **İki Pencere Desteği**: Her iki pencereye özel sensör ve LED ile ayrı ayrı uyarı verebilir.
- **Akıllı Uyarı Sistemi**:
  - Mesafe, 75 cm'nin altına düştüğünde ve %8'den fazla değişiklik algılandığında uyarı verir.
  - LED'ler hangi pencerede hareket olduğunu gösterir.
  - Buzzer, rahatsız etmeyen bir melodi ile uyarı sağlar.
- **Geçersiz Ölçümleri Filtreleme**: 75 cm'nin üzerindeki ölçümler geçersiz sayılır ve uyarı tetiklenmez.

---

## Kullanılan Donanım 🛠️
- **Arduino Nano** (veya herhangi bir Arduino modeli)
- **2x HC-SR04 Ultrasonik Sensör**
- **2x LED** (Her pencere için bir LED)
- **1x Piezo Buzzer**
- Dirençler ve bağlantı kabloları

---

## Çalışma Mantığı ⚙️
1. Sistem, her iki pencereye yerleştirilen ultrasonik sensörlerle mesafeyi ölçer.
2. Eğer herhangi bir sensör, 75 cm'nin altındaki mesafede %8'den fazla bir değişiklik algılarsa:
   - **LED**: İlgili pencere için LED yanar.
   - **Buzzer**: Kibar bir melodi çalar.
3. Mesafe tekrar normal aralığa döndüğünde (75 cm ve üstü), sistem uyarıları kapatır.
4. Geçersiz ölçümler (75 cm'nin üstü) otomatik olarak filtrelenir.

---

## Kod Detayları 📜
- **Aktif LED Gösterimi**: 2. pin (LED 1 - Birinci pencere) ve 3. pin (LED 2 - İkinci pencere) LED kontrolü için kullanılır.
- **Melodi Uyarısı**: Piezo buzzer, kullanıcı dostu bir melodi ile uyarı verir.
- **Bağımsız Sensör Yönetimi**: Her sensör kendi ölçümlerine göre bağımsız çalışır.

---

## Nasıl Kullanılır? 🚀
1. **Donanım Bağlantıları**:
   - HC-SR04 sensörlerini ve LED'leri belirtilen pinlere bağlayın.
   - Buzzer'ı ilgili pine bağlayın.
2. **Kodu Yükleyin**:
   - Arduino IDE ile kodu yükleyin.
3. **Test Edin**:
   - Kediler veya hareketli cisimler ile sensörleri test edin.

---

## Geliştirme Fırsatları 🌟
- Daha fazla sensör ekleyerek üç veya daha fazla pencereyi desteklemek.
- Uyarılar için farklı melodiler veya LED renk kodları eklemek.
- Wi-Fi modülü ekleyerek uyarıları bir mobil uygulama ile bildirmek.

---

## Lisans 📄
Bu proje açık kaynak olarak paylaşılmaktadır. Kullanımda herhangi bir kısıtlama yoktur. Katkıda bulunmak isteyenler için PR'lar açıktır! 😊

---

**KediGör: Kediler için, sizin için, huzurlu bir pencere sistemi. 🐱** 
