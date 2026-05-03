#! /bin/bash
sciezka=/home/adminlinux/Pulpit/test
echo "Podaj nazwe uzytkownika! np. stud"
read new_user
echo $new_user
echo "rozpoczynam dzialanie skryptu"
if id -u $new_user;
        then chown -R  $new_user $sciezka;
echo "skrypt wykonal sie poprawnie" 
else 
        echo "nie ma takiego usera";
fi