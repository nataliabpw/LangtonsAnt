-----------------
# MRÓWKA LANGTONA
-----------------

## Cel projektu:
  Program obliczaja kolejne etapy mrówki Langtona i zapisuje je do plików lub na standardowe wyjście jeśli nie zostanie podana nazwa pliku. 
  
  Ideą programu jest symulowanie ruchu mrówki na dwuwymiarowej siatce komórek, co może prowadzić do utworzenia skomplikowanych i interesujących wzorów. 


## Zasady działania
- Mrówka porusza się po dwuwymiarowej siatce komórek.
- Każda komórka może mieć jeden z dwóch stanów: biały lub czarny.
- Mrówka może poruszać się w jednym z czterech kierunków: góra, dół, lewo lub prawo.
- Początkowy kierunek mrówki podawany jest przez użytkownika.

Zasady ruchu:

- Jeśli mrówka znajduje się w **białej komórce**, wykonuje:
  - obrót o 90° w prawo,
  - zmianę koloru komórki na przeciwny,
  - przesunięcie o jedną komórkę do przodu.

- Jeśli mrówka znajduje się w **czarnej komórce**, wykonuje:
  - obrót o 90° w lewo,
  - zmianę koloru komórki na przeciwny,
  - przesunięcie o jedną komórkę do przodu.

Ruch mrówki powtarzany jest przez liczbę iteracji podaną przez użytkownika.


## Sposób korzystania:

 Program należy skompilować poleceniem 
  ```bash
make
```
  Następnie uruchamiamy go używając nazwy pliku wykonywalnego `program` oraz podanie następujących parametrów:
 ```
•	-m <liczba wierszy>

•	-n <liczba kolumn>

•	-i <liczba iteracji>

•	-o <przedrostek plików wynikowych> (parametr opcjonalny, gdy niepodany - stdout)

•	-d <początkowy kierunek mrówki> (podajemy jako N [góra], S [dół], E [prawo] lub W [lewo])

•	-l <nazwa pliku z siatką, „czarnymi polami” i aktualną pozycją mrówki> (parametr opcjonalny)

•	-p <procentowe (liczba zmiennoprzecinkowa)  zapełnienie planszy „czarnymi” polami> (parametr opcjonalny)
```
    
Przykład:
```bash
./program -m 51 -n 101 -i 1100 -o plik -d N
```

## Wnioski
Program oblicza kolejne etapy mrówki Langtona zgodnie z przyjętymi zasadami i umożliwia generowanie interesujących wzorów. Już przy około 11000 iteracji można zauważyć charakterystyczny wzór powstający podczas symulacji.
