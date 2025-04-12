# 🔐 illbeyyofficial CryptoVault

**CryptoVault**, şifrelerinizi AES-256 şifreleme ile güvenle saklayan minimalist bir C++ uygulamasıdır.  
Projede aynı zamanda sembolik olarak `.mal` uzantılı bir **Malbolge kriptografi totemi** yer almaktadır.

## 📁 Proje Yapısı

```
illbeyyofficial_CryptoVault/
├── src/
│   └── main.cpp                # AES-256 şifreleme içeren kaynak kod
├── illbeyyofficial_totem.mal   # Malbolge formatında kripto totem dosyası
```

## 🚀 Özellikler

- AES-256 CBC mod ile şifreleme (OpenSSL kullanır)
- Komut satırından kullanıcı girdisi alır
- Şifre defteri `vault.defter` dosyasına ikili (binary) olarak kaydedilir
- Malbolge ile yazılmış sembolik bir .mal dosyası içerir

## ⚙️ Derleme

Uygulamayı derlemek için OpenSSL kütüphanesi kurulu olmalıdır.

**Linux:**

```bash
g++ src/main.cpp -o cryptovault -lssl -lcrypto
```

**Windows (MSYS2 / MinGW):**

```bash
g++ src/main.cpp -o cryptovault.exe -lssl -lcrypto
```

## 💾 Kullanım

```bash
./cryptovault
```

Sonrasında:
- Master key girilir
- Web site adı ve parola girilir
- Bilgiler şifrelenmiş olarak `vault.defter` dosyasına yazılır

## 🔐 Malbolge Totem

`illbeyyofficial_totem.mal` dosyası, sembolik olarak projeye kriptografik anlam yüklemek üzere eklenmiştir.  
Dosya, Malbolge dilinde yazılmış Hello World benzeri bir yapıdır.

## 📜 Lisans

MIT Lisansı

---

✨ **Developed by illbeyyofficial**  
> Kod susar, güvenlik konuşur.
