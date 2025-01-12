# Snake Game - README

## Opcenito:
Ovo je konzolna aplikacija Snake game implemntirana u C++ programskom jeziku dizajnirana za Windows operativni sustav. 
Cilj igre je upravljati zmijom izbjegavajuci sudar sa zidom ili sa tijelom zmije i skupljajuci hranu postici sto veci rezultat.
Igra zavrsava sudarom zmije sa zidom ili sa vlastitim tijelom.

## Svojstva:
- Grafička reprezentacija igre bazirana na ASCII simbolima
- Upravljanje zmijom pritiscima na tipke na tastaturi (`w`, `a`, `s`, `d`, 0 za kraj)
- Slučajno generiranje hrane na području igrališta
- Detekcija sudara:
  - sa zidom
  - sa vlastitim tijelom
- Prikaz rezultata u realnom vremenu

## Potrebno:
- **Operativni sustav:** Windows 10 ili noviji
- **Compiler/IDE:** Visual Studio 2022
- **Dodatno:** "Desktop development with C++" workload instaliran u Visual Studio.

- ## Upute za pokretanje:

### Korak 1: Kopiraj kod ili download file
1. Ako je kod kopiran, otvori novi file u text editoru po svom izboru. Zalijepi kod i spremi ga kao imepozelji.cpp na svoje računalo u direktorij po želji.
   Kreiraj novi projekt i desnim klikom na ime projekta u solution exploreru.

### Korak 2: Otvaranje projekta u Visual Studio 2022:
1. Otvori Visual Studio 2022.
2. Kreiraj novi projekt:
   - Izaberi ** (C++)**
   - Unesi ime projekta (npr `SnakeGame`)
3. Zalijepi sadrzaj `Source.cpp` datoteke kodom koji si kopirao iz `snake.cpp` datoteke.
4. Klikni Build Solution i onda pritisni CTRL+F% na tipkovnici za pokretanje.

## Pravila igre
1. **Tipke:**
   - `w`: Kreći se prema gornjoj strani ekrana
   - `a`: Kreći se prema lijevoj strani ekrana
   - `s`: Kreći se prema donjoj strani ekrana
   - `d`: Kreći se prema desnoj strani ekrana
   - `x`: Kraj igre
2. Izbjegavaj sudare sa zidovima ili tijelom zmije
3. Skupljaj hranu (*) i povećaj rezultat što je više moguće
4. Igra završava sudarom glave zmije sa zidom ili vlastitim tijelom
## Struktura projekta
- **SnakeGame:** Klasa koja implementira logiku igre
- **Pixel:** Bazna klasa za različite tipove pixela u igri (npr zid, hrana, glava zmije, tijelo zmije).
- **Iznimke:**
  - `HitTheWallEx`: Indikator sudara zmije sa zidom
  - `SelfCollisionEx`: Indikator sudara zmije sa vlastitim tijelom

## Prilagodba dimenzija igrališta
- Igra se može prilagoditi  promjenom 'visina' i 'sirina' varijabli u klasi SnakeGame koje označavaju dimenzije igrališta
- Za prilagodbu brzine igre promijeni vrijednost u argumentu `Sleep()` funkcije u `Run()` metodi

## Moguci problemi
- **Problem:** "definicija funkcije `_getch()` nije pronađena."
  - **Rješenje:** Provjeri je li `<conio.h>` header file uključen u projekt.
- **Problem:** "Kod nije izvediv na Linux i macOS"
  - **Napomena:** Kod je dizajniran da radi na Windows platformi i koristi `<windows.h>`.

## Moguca poboljšanja koda
- Instalacija PDCurses biblioteke radi poboljšanja grafičkih značajki igre
- Razdvajanje centraliziranog koda u pojedine .h i .cpp datoteke
  
## Moguca nadogradnja igre
Uvođenje dodatnih lakših i težih nivoa igrališta, npr propusni zidovi kao lakši nivo i prepreke na igralištu kao teži nivo
