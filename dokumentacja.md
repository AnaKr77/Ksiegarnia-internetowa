# 📘 Dokumentacja – Księgarnia Internetowa (C++)

## 📌 1. Opis projektu

Projekt przedstawia konsolową księgarnię internetową napisaną w języku C++.

Aplikacja umożliwia:
- przeglądanie dostępnych książek
- zakup książek
- wyszukiwanie książek po tytule
- przegląd zakupionych książek
- anulowanie zakupów
- edycję zamówienia
- obliczanie sumy wydatków

Projekt działa w oparciu o pliki tekstowe, które symulują prostą bazę danych.

---

## 💾 2. Struktura plików

W projekcie wykorzystywane są dwa główne pliki:

### 📄 `dostepne_ksiazki.txt`
Zawiera listę dostępnych książek.

Format danych: id tytul cena

Przykład:
1 Hobbit 40
2 Wiedźmin 60
3 Metro2033 50

---

### 📄 `kupione_ksiazki.txt`
Zawiera listę zakupionych książek.

Format danych:
id tytul cena

---

## ⚙️ 3. Technologie

Projekt został napisany w języku C++ z wykorzystaniem bibliotek:

- `iostream` – obsługa wejścia i wyjścia
- `fstream` – obsługa plików
- `vector` – przechowywanie danych w pamięci

---

## 📚 4. Funkcje programu

### 📖 4.1 `dostepne()`
Wyświetla listę dostępnych książek z pliku `dostepne_ksiazki.txt`.

---

### 🛒 4.2 `kupowanie()`
Umożliwia zakup książki:
- użytkownik podaje ID książki
- książka zostaje przeniesiona do pliku `kupione_ksiazki.txt`
- zostaje usunięta z listy dostępnych książek

---

### 🔎 4.3 `szukanie()`
Wyszukuje książki po początku tytułu (prefiks).

---

### 📋 4.4 `podsumowanie()`
Wyświetla wszystkie zakupione książki oraz sumę wydatków.

---

### ❌ 4.5 `anulowanie()`
Anuluje wszystkie zakupy:
- przywraca książki do listy dostępnych
- czyści plik zakupionych książek

---

### ✏️ 4.6 `edycja()`
Umożliwia edycję zamówienia:
- usunięcie książki z zamówienia
- zamiana książki na inną

---

### 📋 4.7 `wyswietlenie()`
Główne menu programu, które obsługuje wybór użytkownika.

---

### 🚀 4.8 `main()`
Uruchamia program i wyświetla ekran powitalny.

---

## 🧠 5. Zasada działania programu

1. Program uruchamia menu główne
2. Użytkownik wybiera akcję
3. Dane są odczytywane z plików tekstowych
4. W zależności od operacji pliki są modyfikowane
5. Program działa w pętli aż do zakończenia

---

## 🧾 6. Model danych

Każda książka posiada:
- `id` – identyfikator książki
- `tytul` – nazwa książki
- `cena` – cena książki

---



