# RFC 9213 Uyumlu API Gateway İstek Zamanlayıcısı

Bu proje, modern API Gateway mimarilerinde kullanılan **RFC 9213 (Extensible HTTP Priorities)** standardına uygun bir öncelikli kuyruk zamanlayıcısı simülasyonudur. Sistem, C dilinin modülerlik prensipleriyle inşa edilmiş olup, performans kritik operasyonlar için **Min-Heap** veri yapısını kullanmaktadır.

## 👤 Öğrenci Bilgileri
* **Ad Soyad:** Nilsu Güven
* **Öğrenci No:** 1250505069
* **Bölüm:** Yazılım Mühendisliği (1. Sınıf)

## 🛠 Teknik Mimari ve Modülerlik
Proje, yazılımın sürdürülebilirliği ve okunabilirliği için katmanlı bir yapıda tasarlanmıştır:
* **types.h**: Veri modelleri.
* **priority_queue.h**: Algoritma arayüzü.
* **priority_queue.c**: Min-Heap implementasyonu.
* **main.c**: RFC 9213 Parser ve simülasyon.

## 🚀 Algoritmik Verimlilik
* **Erişim Hızı:** $O(1)$ (En öncelikli eleman köktedir).
* **İşlem Karmaşıklığı:** $O(\log n)$ (Ekleme ve çıkarma işlemleri).

## 📊 Bellek Yönetimi
* Dinamik bellek tahsisi (`malloc`) ve tam temizlik (`free`) prensipleriyle "Zero Memory Leak" hedeflenmiştir.
