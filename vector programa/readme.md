# ___DARBO APRAŠYMAS___
__Sistemos parametrai__


__CPU:__ AMD Ryzen 7 1700 Eight-Core Processor             3.00 GHz  
__RAM:__ 16 GB 3200 Mhz  
__Storage__: SSD 240GB

----------------------------------------------

__***V.01 Aprašymas***__

Programa leidžia pasirinkti iš kur nuskaityti failą, iš dokumento ar parašyti ranka. Surašymas ranka   
leidzia įvesti studentų kiekį, jų vardas bei pavardes ir skaiciavima pagal vidurki arba mediana (kadangi pazymiai yra generuojami atsitiktinai)  
Nuskaityme iš dokumento realizuotas išimčių valdymas. Rezultatai suruošuoti ir išvedamas vidurkis su mediana.

----------------------------------------------------------------------------------------
__***V.02 Aprašymas***__

Programa generuoja txt failus su pazymiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų.  
(Generavimo algoritmas pacioje programoje gali būti užkommentuotas)  
Studentai yra dalinami į dvi kategorijas: kietiakai ir vargšiukai  
Ir taip pat yra matuotas:
failu generavimas;
irasu nuskaitymo laikas;
irasu dalijimo i dvigrupes laikas; 
irasu keteku irasymo i faila laikas;
irasu vargsiuku irasymo i faila laikas;
irasu testo laikas.  
Laiko matavimas įdėtas "testavimorezultatai.txt" faile.

----------------------------------------------------------------------------------------------------------------------
__***V.03 Aprašymas***__

2 versijos realizacija, tiktais su list konteinerių ir tam tikrais patobulinimais (Gražinti 1 versijos medijanos, rusiavimo funkcijos),  
taip pat pridėtas irašų rusiavimo laikas, kuris praeitoj versijoj nebuvo skaiciuojamas.  
---------------------------------------------------------------------------------------------------------------

__***V.1 Aprašymas***__  
Pridėtas kelių testų skaičiavimo vidurkis(kurio nebuvo prieš tai) ir analizuojamo failo pasirinkimas  
Buvo realizuotos 3 skirtingos strategijos ir rezultatai pateikiami žemiau (rezultatas - triju testu vidurkis; laikas pateikiamas sekundemis) :

Vid. failo skaitymo laikas:    


### __1 strategija ( V.03 versijos palyginimai)__

  
**VECTOR:**


|          Operacijos          |  1000.txt   |  10000.txt  | 100000.txt  | 1000000.txt | 10000000.txt |
|:----------------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|
|       Failo skaitymas        | 0.005075 s  | 0.0450994 s | 0,431851 s  |  4,15142 s  |  41,8055 s   |
|          Rušiavimas          | 0.0005294 s | 0.0067292 s | 0,0756355 s |  1,84669 s  |  23,6747 s   |
| Irasu dalijimas i dvi grupes | 0.0078451 s | 0.0956223 s | 0,654173 s  |  6,52163 s  |  65,7627 s   |
|  Vargsiuku irasymas i faila  | 0.0033578 s | 0.0311457 s | 0,308371 s  |  3,04033 s  |  30,6326 s   |
|   Keteku irasymas i faila    | 0.0033477 s | 0.030609 s  | 0,312952 s  |  3,1265 s   |  30,9259 s   |
|     Ap. Bendras laikas       |     0,02    |   0,18 s    |    1,7 s    |    18 s     |    187 s     |

![memory.PNG](..%2FDesktop%2Fmemory.PNG)
**LIST:**


|          Operacijos          |  1000.txt   |  10000.txt  | 100000.txt  | 1000000.txt | 10000000.txt |
|:----------------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|
|       Failo skaitymas        | 0.0094861 s | 0.0899376 s | 0,846862 s  |  7,82471 s  |  76,2173 s   |
|          Rušiavimas          | 0.000244 s  | 0.0032689 s | 0,0426869 s | 0,868557 s  |  11,1065 s   |
| Irasu dalijimas i dvi grupes | 0.0095533 s | 0.0780479 s | 0,775562 s  |  7,55291 s  |  96,7365 s   |
|  Vargsiuku irasymas i faila  | 0.0038039 s | 0.0310747 s | 0,317524 s  |  3,07512 s  |   33,348 s   |
|   Keteku irasymas i faila    | 0.0032556 s | 0.0308358 s | 0,310499 s  |  3,05175 s  |  31,5768 s   |
|      Ap. Bendras laikas      |   0.25 s    |   0,28 s    |    2,1 s    |    22 s     |    247 s     |


![img_2.png](img_2.png)

### __2 strategija__

**VECTOR:**


|          Operacijos          |    1000.txt    |   10000.txt    |   100000.txt    | 1000000.txt | 10000000.txt |
|:----------------------------:|:--------------:|:--------------:|:---------------:|:-----------:|:------------:|
|       Failo skaitymas        |   0.00502 s    |    0.045 s     |   0.431851  s   |      -      |      -       |
|          Rušiavimas          | 0.0001945333 s | 0.0022975000 s | 0.0233175667 s  |      -      |      -       |
| Irasu dalijimas i dvi grupes | 0.0177319667 s | 0.7348393667 s | 68.4236039000 s |      -      |      -       |
|  Vargsiuku irasymas i faila  | 0.0040144333 s | 0.0300530000 s | 0.3067810667 s  |      -      |      -       |
|     Ap. Bendras laikas       |     0.02s      |     0.8 s      |      69 s       |      -      |      -       |

![img_1.png](img_1.png)

**LIST:**


|          Operacijos          |    1000.txt    |   10000.txt    |   100000.txt   |   1000000.txt   |  10000000.txt   |
|:----------------------------:|:--------------:|:--------------:|:--------------:|:---------------:|:---------------:|
|       Failo skaitymas        |   0,009481 s   |   0,089932 s   |   0,83772 s    |    7,7956 s     |    79,2173 s    |
|         Rušiavimas           | 0.0000859333 s | 0.0010742333 s | 0.0129792000 s | 0.2699172667 s  | 3.7054655667 s  |
| Irasu dalijimas i dvi grupes | 0.0040391333 s | 0.0322328333 s | 0.3320418000 s | 3.4544312000 s  | 34.016518000 s  |
|  Vargsiuku irasymas i faila  | 0.0033669000 s | 0.0287727000 s | 0.3030058333 s | 3.1266212000  s | 30.7133328667 s |
|      Ap. Bendras laikas      |    0.016 s     |     0,12 s     |     1,4 s      |      14 s       |      147 s      |



![img_3.png](img_3.png)

### __3 strategija__  

**VECTOR:**


|          Operacijos          |  1000.txt  | 10000.txt  | 100000.txt | 1000000.txt | 10000000.txt |
|:----------------------------:|:----------:|:----------:|:----------:|:-----------:|:------------:|
|       Failo skaitymas        | 0.00502 s  |  0.045 s   | 0.431851 s |  4.15153 s  |   41.784 s   |
|          Rušiavimas          | 0.00058 s  | 0.006718 s | 0.074329 s | 1.297035 s  | 16.069415  s |
| Irasu dalijimas i dvi grupes | 0.000071 s | 0.000659 s | 0.298240 s | 0.071632 s  |  0.690790 s  |
|  Vargsiuku irasymas i faila  | 0.003413 s | 0.028728 s | 0.298240 s | 3.026089 s  | 29.585923 s  |
|      Ap. Bendras laikas      |   0.009s   |   0.08 s   |   1 s    |     9 s     |     87 s     |


![img.png](img.png)


**LIST:**


|          Operacijos          |    1000.txt    |   10000.txt    |   100000.txt   |  1000000.txt   |  10000000.txt   |
|:----------------------------:|:--------------:|:--------------:|:--------------:|:--------------:|:---------------:|
|       Failo skaitymas        |   0,009623 s   |  0,0455967 s   |    0,8372 s    |   7,83432 s    |    77.9771 s    |
|         Rušiavimas           | 0.0003542000 s | 0.0041453000 s | 0.0531998333 s | 0.9141556000 s | 12.7142803667 s |
| Irasu dalijimas i dvi grupes | 0.0001046667 s | 0.0041453000 s | 0.0127835667 s | 0.1399131667 s | 1.4424101333 s  |
|  Vargsiuku irasymas i faila  | 0.0034410000 s | 0.0041453000 s | 0.2904211333 s | 3.0259688667 s |  30.85139063 s  |
|      Ap. Bendras laikas      |    0,013 s     |     0,06 s     |     1,3 s      |      11 s      |      120 s      |


![img_4.png](img_4.png)
-------------------------------------------------------------------------------------------------------------

   

## __Rusiavimo greitis__



**VECTOR:**


| Strategija |    1000.txt    |    10000.txt    |   100000.txt    | 1000000.txt | 10000000.txt |
|:----------:|:--------------:|:---------------:|:---------------:|:-----------:|:------------:|
|     1      |  0.0078451 s   |   0.0956223 s   |   0,654173 s    |  6,52163 s  |  65,7627 s   |
|     2      | 0.0177319667 s | 0.7348393667 s  | 68.4236039000 s |      -      |      -       |
|     3      |   0.000071 s   |   0.000659 s    |    0.006900     | 0.071632 s  |  0.690790 s  |




**LIST:**


| Strategija |     1000.txt     |   10000.txt    |    100000.txt    |  1000000.txt   |  10000000.txt  |
|:----------:|:----------------:|:--------------:|:----------------:|:--------------:|:--------------:|
|     1      |   0.0095533 s    |  0.0780479 s   |    0,775562 s    |   7,55291 s    |   96,7365 s    |
|     2      |  0.0040391333 s  | 0.0322328333 s |  0.3320418000 s  |  3.4544312000  | 34.016518000 s |
|     3      |  0.0001046667 s  | 0.0041453000 s |  0.0127835667 s  | 0.1399131667 s | 1.4424101333 s |




Galime matyti, kad efektyviausia strategija pagal naudojimo atminties ir greicio parametrus yra 3 strategija su vektoriumi, kadangi  
jinai veikia greiciau nei visos ir naudoja maziau atminties resurso negu 1 strategija. (nuotraukose yra naud. atminties kiekis 10 mln eiluciu atv.)


--------------------------------------------------------------------------------------------------------------

### __Naudojimo instrukcija__ 

Visu pirma, programa paprasys pasirinkti is kur pasiimti duomenis, is failo ar is ivedimo. Irašymas ranka   
leidzia įvesti studentų kiekį, jų vardas bei pavardes ir skaiciavima pagal vidurki arba mediana (kadangi pazymiai yra generuojami atsitiktinai)  
Nuskaityme iš dokumento realizuotas išimčių valdymas. Rezultatai suruošuoti ir išvedamas vidurkis su mediana.   
Pasirinkus duomenys nuskaityti is dokumentu, programa paprasys pasirinkti duomenu faila analizei (laiko matavimui)  
ju galite pasirinkti is 1000,10000,100000,1000000,10000000 eiluciu.  
Tada programa paprasys pasirinkti kokia strategija norite pritaikyti ir matavimo duomenis isves i konsole. 





# __V1.1__


Versija v1.0 buvo realizuota su class'emis, todėl tikslas buvo palyginti abiejų programų: naudojančios struct   
iš v1.0 ir class tipo Studentus iš dabartinės realizacijos veikimo laiką, naudojant vieną fiksuotą kontenerį (vector)  
Kadangi greičiausia strategija buvo Nr3, todėl palyginimai buvo atlikti naudojant būtent strategiją Nr3.

-----------------------------------------------------------------------------------------------------------

__Struct: __

|          Operacijos          | 100000.txt | 1000000.txt |
|:----------------------------:|:----------:|:-----------:|
|       Failo skaitymas        | 0.571593 s | 5.989166 s  |
|          Rušiavimas          | 0.076395 s | 1.943283 s  |
| Irasu dalijimas i dvi grupes | 0.007118 s | 0.077971 s  |
|  Vargsiuku irasymas i faila  | 0.309592 s | 3.315348 s  |
|   Keteku irasymas i faila    | 0.309998 s | 3.361488 s  |
|     Ap. Bendras laikas       | 1.274695 s | 14.687256 s |

__Class:__

|          Operacijos          |   100000.txt    | 1000000.txt |
|:----------------------------:|:---------------:|:-----------:|
|       Failo skaitymas        |   0.547799 s    | 5.543150 s  |
|          Rušiavimas          |   0.733446 s    | 5.980395 s  |
| Irasu dalijimas i dvi grupes |   0.016154 s    | 0.189791 s  |
|  Vargsiuku irasymas i faila  |   0.315359 s    | 3.237792 s  |
|   Keteku irasymas i faila    |   0.319776 s    | 3.300957 s  |
|     Ap. Bendras laikas       |   1.932535 s    | 18.252086 s |

-----------------------------------------------------------------------------------------------------------
### ___FLAG 01___  
__Struct:__

|          Operacijos          | 100000.txt | 1000000.txt |
|:----------------------------:|:----------:|:-----------:|
|       Failo skaitymas        | 0.529299 s | 5.299737 s  |
|          Rušiavimas          | 0.077640 s | 1.836603 s  |
| Irasu dalijimas i dvi grupes | 0.007297 s | 0.075269 s  |
|  Vargsiuku irasymas i faila  | 0.314385 s | 3.131496 s  |
|   Keteku irasymas i faila    | 0.310402 s | 3.187624 s  |
|     Ap. Bendras laikas       | 1.239022 s | 13.530729 s |

__Class:__

|          Operacijos          | 100000.txt | 1000000.txt |
|:----------------------------:|:----------:|:-----------:|
|       Failo skaitymas        | 0.548622 s | 5.466082 s  |
|          Rušiavimas          | 0.717433 s | 5.853845 s  |
| Irasu dalijimas i dvi grupes | 0.018312 s | 0.192530 s  |
|  Vargsiuku irasymas i faila  | 0.314118 s | 3.191929 s  |
|   Keteku irasymas i faila    | 0.323983 s | 3.228211 s  |
|     Ap. Bendras laikas       | 1.922468 s | 17.932597 s |

-----------------------------------------------------------------------------------------------------------

### ___FLAG 02___

__Struct:__

|          Operacijos          | 100000.txt | 1000000.txt |
|:----------------------------:|:----------:|:-----------:|
|       Failo skaitymas        | 0.533263 s | 5.274458 s  |
|          Rušiavimas          | 0.078503 s | 1.852389 s  |
| Irasu dalijimas i dvi grupes | 0.007294 s | 0.073171 s  |
|  Vargsiuku irasymas i faila  | 0.309397 s | 3.147381 s  |
|   Keteku irasymas i faila    | 0.316356 s | 3.171818 s  |
|     Ap. Bendras laikas       | 1.244813 s | 13.519218 s |

__Class:__

|          Operacijos          | 100000.txt | 1000000.txt |
|:----------------------------:|:----------:|:-----------:|
|       Failo skaitymas        | 0.545427 s | 5.496153 s  |
|          Rušiavimas          | 0.727605 s | 5.769566 s  |
| Irasu dalijimas i dvi grupes | 0.016126 s | 0.187719 s  |
|  Vargsiuku irasymas i faila  | 0.310042 s | 3.181238 s  |
|   Keteku irasymas i faila    | 0.319782 s | 3.222326 s  |
|     Ap. Bendras laikas       | 1.918982 s | 17.857002 s |

-----------------------------------------------------------------------------------------------------------

### ___FLAG 03___

__Struct:__

|          Operacijos          | 100000.txt |  1000000.txt   |
|:----------------------------:|:----------:|:--------------:|
|       Failo skaitymas        | 0.536109 s | 5.281998 s     |
|          Rušiavimas          | 0.078029 s |   1.845768 s   |
| Irasu dalijimas i dvi grupes | 0.007426 s |   0.080346 s   |
|  Vargsiuku irasymas i faila  | 0.312184 s |   3.132923 s   |
|   Keteku irasymas i faila    | 0.315715 s |   3.170846 s   |
|     Ap. Bendras laikas       | 1.249463 s |   13.511881    |

__Class:__

|          Operacijos          | 100000.txt | 1000000.txt |
|:----------------------------:|:----------:|:-----------:|
|       Failo skaitymas        | 0.541885 s | 5.500045 s  |
|          Rušiavimas          | 0.719613 s | 5.839997 s  |
| Irasu dalijimas i dvi grupes | 0.015724 s | 0.192832 s  |
|  Vargsiuku irasymas i faila  | 0.319889 s | 3.160602 s  |
|   Keteku irasymas i faila    | 0.319154 s | 3.161902 s  |
|     Ap. Bendras laikas       | 1.916265 s | 17.855378 s |

-----------------------------------------------------------------------------------------------------------

Kaip matome iš rezultatų, geriausią laiką parodė FLAG 03 Struct. Class'ės yra šiek tiek letesnes, nepriklausomai nuo  
FLAG'ų, dirba beveik vienodai, bet verta pastebėti, kad FLAG'ai vistiek paspartina programos veikimo greitį.