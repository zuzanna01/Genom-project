# Genom-project

Celem zadania jest analiza genomu pod kątem częstości powtórzeń n-gramów nukleotydów.
Poprzez pojęcie n-gramu rozumiemy n-elementowy podciąg jakiegoś ciągu.

Przykładowo dla ciągu TTAAAGGTTTATACCTTCCCAGGT pierwsze 5-gramy to kolejno
TTAAA, TAAAG, AAAGG, AAGGT, AGGTT

Program podzielony jest na dwie części:
## Część 1 – funkcjonalność generowania i zliczania n-gramów:

• przyjmuje dwa parametry długość n-gramu - N i nazwę pliku w formacie FASTA z danymi genomu,

• czyta plik FASTA,

• wyznacza wszystkie n-gramy – UWAGA: symbol maskujący „N” jest pomiany,

• zapisuje wynik do pliku tekstowego (swojej „bazy danych”),

• działa w pełni nieinteraktywnie.

## Część 2 – odczyt bazy danych n-gramów i wyświetlanie wyników

• program jest interaktywny,

• w momencie uruchomienia wczytuje plik z policzonymi n-gramami (po wczytaniu sortuje wg częstości),

• podaje jaki procent możliwej przestrzeni dla N-gramów jest obecna w genotypie,

• umożliwia interaktywne wyszukanie wskazanego n-gramu i podaje jego częstość,

• umożliwia wyświetlenie wszystkich n-gramów o częstości występowania od A do B,

• umożliwia wyświetlenie całej bazy n-gramów posortowanej wg częstości.
