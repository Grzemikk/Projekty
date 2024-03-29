//1. Projket systemu dla prywatnej szkoly( czesc I )
//
//W szkole pracuja nauczyciele oraz pracownicy administracji.Do szkoly chodzi mlodziez
//do roznych klas.Kazda osoba w szkole jest identyfikowana przez nazwisko i imienie( razem ) oraz wiek
//Ponadto ka�dy ucze� jest identyfikowany identyfikatorem ID.
//ID ma byc dotepny z klasy opisujacej dowolnego ucznia( Pupil ) - aby mozna go drukowac
//majac tylko uczniow.
//ID jest tworzony na podstawie wartosci startowej( baseID - liczba pieciocyfrowa, poczatkowo 10000 ) w klasie Pupil
//i modyfikowany w klasach pochodnych reprezentujacych ucznia( chlopak - SchoolBoy ) oraz uczennice( dziewczyna - SchoolGirl )
//Do ID dodawany jest : .
//- przedrostek F_ dla dziewczyn( F_12345 )
//- przedrostek M_ dla chlopcow( M_00100 )
//
//Wartosc startowa baseID musi byc wspolna dla kazdego obiektu klasy.Po dodaniu kolejnego obiektu baseID jest inkrementowane,
//tak aby kazdy uczen mial unikalny bazowy ID.
//
//Dla kazdego ucznia( bez wzgledu czy uczen czy uczennica )
//- pamietamy oceny z przedmitow :
//POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI( typ wyliczneiowy )
//
//Pupil zawiera :
//-metode do drukowania danych ucznia :
//-ID
//- Nazwisko i imie
//- w nawiasach klase
//- wiek
//- srednia ocen
//- drukowac ubior - wywolana metoda printOutfit() ( tu nie moze byc implementacji bo zalezy czy dziewczyna czy chlopak ) - funkcja wirtualna
//- mozliwosc ustawiania ocen dla danego przedmiotu.Oceny polowkowe tez moga byc oraz zakres ocen od 2..5
//- mozliwosc obliczanai sredniej( jak nie ma oceny z danego przemdiotu to pamitacac 0 - mozna zdefinowac stala tablice ),
//-mozliwosc wyczyszczenia wszystkich ocen
//
//Kazdy uczen moze miec rozna ilosc ocen( nie z kazdego przedmiotu ) - jak nie ma to wartosc 0
//
//W kazdej klasie reprezentujacej ucznia lub uczennice oprocz konstruktora ma byc metoda - implementacja drukowanie ubioru :
//uczennica: biala bluzka z krawatem, szkolna marynarka, granatowa / czarna spodniczka, plaskie obuwie
//uczen : biala / niebieska koszula z krawatem, szkolna marynarka, polbuty, granatowa / czarna spodnie.
//
////==========================================================================
//
//W szkole pracuj� nauczyciele( Teacher ) oraz pracownicy administarcyjni( Admin )
//Dla kazdego pracownika pamietac : nawisko i imie, wiek oraz pensja brutto, sta� pracy w latach.
//Dla pracownika administracyjnego pamietac na jakim stanowisku pracuje( mozliwosci : mlodszy specjalista, specjalista, starszy specjalista )
//Dla nauczyciela pamietac jakiego przedmiotu uczy i czy jest wychowawca a jesli tak to jakiej klasy( np "2b" )
//
//MA byc mozliwosc wydrukowania listy pracownikow( nazwisko i imie, stanowisko - jesli nauczyciel wydrukowac jaki przedmiot uczy )
//oraz obliczenia pensji( na wydruku pensja brutto, podatek i pensja netto ) przy czym :
//-dla admina podatek oblicza sie( ( kwota brutto - koszty uzysku ) * 18 % podatku - kwota wolna ),
//( kwota netto to brutto minus obliczony podatek )
//Jesli podatek wychodzi ujemny to go wyzerowac
//kwoty ponizej
//- dla nauczycieli od 80 % pensji naliczac 50 % koszty uzysku a od reszty tak jak dla admina przy czym uwzglednic w kwocie brutto
//wysluge lat( w zakresie od 5 do 20 lat pracy doliczac do kwoty brutto odpowiednio od 5 do 20 % kwoty brutto ) oraz jesli jest wychowawca
//dodac dodatek 400 zl
//np dla 10 stazu pracy od 5000 brutto doliczyc 500 czyli lacznie jest 5500 brutto( bez wychowacy ).
//Powyzej 20 lat stazowe sie nie zwieksza)
//
//- koszty uzykania przychodu : 111.25 / miesiac
//- kwota wolna 556.02
//
//- w programie glownym stowrzyc 6 - miu nauczycieli oraz 3 pracownikow administr.
//Napisac funkcje majaca na wejsciu tablice wskaznikow do pracownikow i drukujaca liste pracownikow

