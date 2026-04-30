#! /bin/bash
printf "Podaj lokalizacje folderu zrodlowego np. /home/adminlinux/Pulpit/folder0:\n "
read start_lokalizacja
printf "Podales poczatkowa lokalizacje folderu: %s \n" "$start_lokalizacja" 
if [ ! -d "$start_lokalizacja" ];
        then 
                printf "Podany folder nie istnieje!"
                exit 1
else 
                printf "Hura, ten folder istnieje!"
fi
printf "\nPodaj lokalizacje folderu docelowego dla archiwum np. /home/adminlinux/Pulpit:\n"
read new_lokalizacja
printf "Podales docelowa lokalizacje: %s \n" "$new_lokalizacja" 
printf "\niPodaj stopien kompresji jaki ciebie interesuje: \n fast = najnizszy stopien kompresji \n medium = posredni \n best = najwyzszy stopien kompresji \n"
read compression_level
printf "Wybrany przez ciebie stopien kompresji to: %s \n" "$compression_level"
printf "Wybrales te parametry: \n Poczatkowa lokalizacja: %s \n Docelowa lokalizacja: %s \n Stopien kompresji: %s \n " "$start_lokalizacja" "$new_lokalizacja" "$compression_level" 
printf "\nCzy to sie zgadza?\n tak lub nie: \n"
read confirmation
if  [ "$confirmation" = "tak" ];
then
        printf "Super,przechodzimy dalej\n"
        if [ "$compression_level" = "fast" ]; 
                then
                       tar --use-compress-program="gzip -1" -cvf "$new_lokalizacja/archiwum.tar.gz" -C"$start_lokalizacja" .
                                       
        elif [ "$compression_level" = "medium" ]; 
                then 
                        tar --use-compress-program="gzip -6" -cvf "$new_lokalizacja/archiwum.tar.gz" -C "$start_lokalizacja" .
        elif [ "$compression_level" = "best" ];
                then
                        tar --use-compress-program="gzip -9" -cvf "$new_lokalizacja/archiwum.tar.gz" -C "$start_lokalizacja" .
        else
                printf "Wybrano nieznany poziom kompresji \n Sprobuj jeszcze raz!"

        fi
else
        printf "Przekaz parametry jeszcze raz"
fi