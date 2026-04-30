#!/bin/bash
new_user=$1
user_home_path=$2
haslo=$3
if test -z "$new_user" || test -z "$user_home_path"; then
    printf "Jeden z podanych argumentów jest pusty, proszę podać odpowiedzi jeszcze raz!\n"
else
    printf "Odpowiedzi podane przez ciebie nie są puste\n"
    printf "Przechodze dalej\n"
    printf "Sprawdzenie czy folder domowy uzytkownika juz istnieje:\n"
    if test -d "$user_home_path"; then
        printf "Podany folder juz istnieje\n"
    else
        printf "Podany folder jeszcze nie instnieje\n"
        mkdir -p "$user_home_path"
        printf "Podany folder został utworzony\n"
    fi
    printf "Sprawdzenie czy dany uzytkownik przypadkiem juz nie istnieje w systemie\n"
    if id "$new_user" &>/dev/null; then
        printf "Podany uzytkownik istnieje juz w naszym systemie\n"
    else
        printf "Podany uzytkownik nie istnieje w systemie\n"
        printf "Zaczynam proces tworzenia uzytkownika z tymi parametrami:\nNazwa uzytkownika: %s\nSciezka do katalogu domowego to: %s\n" "$new_user" "$user_home_path"
        useradd -d "$user_home_path" "$new_user"
        printf "Uzytkownik zostal utworzony!\n"
        printf "Twoje haslo to: %s\n" "$haslo"
        printf "$new_user:$haslo" |sudo chpasswd
        printf "Stworzono uzytkownika: %s z haslem %s!\n" "$new_user" "$haslo"
        printf "Zmieniam przynaleznosc folderu domowego dla uzytkownika: %s\n" "$new_user"
        chown -R "$new_user" "$user_home_path"
        if grep -q "^$new_user:" /etc/shadow
        then
                printf "Haslo uzytkownika już jest w pliku /etc/shadow\n"
        else
                printf "Haslo uzytkownika nie znajduje sie w pliku /etc/shadow\n"
                sudo pwconv
                printf "Haslo uzytkownika zostalo przeniesione do pliku /etc/shadow\n"
        fi
    fi
fi