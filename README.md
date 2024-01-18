-----------------
 MRÓWKA LANGTONA
-----------------
Opis programu:

  Program obliczaja kolejne etapy mrówki Langtona i zapisuje je do plików lub na standardowe wyjście jeśli nie zostanie podana nazwa pliku. 
  Ideą programu jest symulowanie ruchu mrówki na dwuwymiarowej siatce komórek, co może prowadzić do utworzenia skomplikowanych i interesujących wzorów. 



Sposób korzystania:

  Program należy na początku skompilować poleceniem „make”.
  Następnie uruchamiamy go używając nazwy pliku wykonywalnego „program” oraz podanie następujących parametrów:
  
    •	-m <liczba wierszy>
    
    •	-n <liczba kolumn>
    
    •	-i <liczba iteracji>
    
    •	-o <przedrostek plików wynikowych> (parametr opcjonalny, gdy niepodany - stdout)
    
    •	-d <początkowy kierunek mrówki> (podajemy jako N [góra], S [dół], E [prawo] lub W [lewo])
    
    •	-l <nazwa pliku z siatką, „czarnymi polami” i aktualną pozycją mrówki> (parametr opcjonalny)
    
    •	-p <procentowe (liczba zmiennoprzecinkowa)  zapełnienie planszy „czarnymi” polami> (parametr opcjonalny)
    
  Przykład wywołania: ./program -m 51 -n 101 -i 1100 -o plik -d N
  
