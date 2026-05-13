% --- FAKTY ---
% rodzic(Rodzic, Dziecko)
rodzic(jan, marek).
rodzic(jan, anna).
rodzic(maria, marek).
rodzic(maria, anna).
rodzic(marek, kasia).
rodzic(marek, staszek).

% plec(Osoba)
mezczyzna(jan).
mezczyzna(marek).
mezczyzna(staszek).
kobieta(maria).
kobieta(anna).
kobieta(kasia).

% --- REGUŁY ---
% Rodzeństwo ma wspólnego rodzica i nie jest tą samą osobą
rodzenstwo(X, Y) :- 
    rodzic(Z, X), 
    rodzic(Z, Y), 
    X \= Y.

% Dziadek to ojciec rodzica
dziadek(D, W) :- 
    mezczyzna(D), 
    rodzic(D, R), 
    rodzic(R, W).

% Siostra to kobieta, która jest rodzeństwem
siostra(X, Y) :- 
    kobieta(X), 
    rodzenstwo(X, Y).