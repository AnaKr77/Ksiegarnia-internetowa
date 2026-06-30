# Ksiegarnia-internetowa
Projekt przedstawia prostą księgarnię internetową w języku C++, działającą w trybie konsolowym. Aplikacja umożliwia przeglądanie dostępnych książek, ich zakup, wyszukiwanie, edycję zamówień oraz anulowanie zakupów.

# 📚 Księgarnia Internetowa w C++

## 🚀 Funkcje aplikacji

Aplikacja umożliwia:

- 📖 Wyświetlanie dostępnych książek
- 🛒 Zakup książek
- 🔎 Wyszukiwanie książek po tytule
- 📋 Podgląd zakupionych książek
- ❌ Anulowanie wszystkich zakupów
- ✏️ Edycję zamówienia (usuwanie lub zamiana książek)
- 💰 Obliczanie sumy wydatków

## 💾 Struktura plików

- `dostepne_ksiazki.txt` – lista dostępnych książek  
- `kupione_ksiazki.txt` – historia zakupów  

Każda linia pliku ma format:
id tytul cena


## ▶️ Jak uruchomić

1. Skompiluj program:
```bash
g++ main.cpp -o ksiegarnia

1. Wyswietl liste dostepnych ksiazek
2. Kup ksiazke
3. Szukaj ksiazki
4. Pokaz zakupione ksiazki
5. Anuluj zakupy
6. Edytuj zamowienie
0. Wyjdz

⚙️ Wymagania
Kompilator C++ (np. g++, MinGW, clang)
System obsługujący pliki tekstowe
