#! /bin/bash
sciezka=$1
new_user=$2
echo "rozpoczynam dzialanie skryptu"
if id -u $new_user;
        then chown -R  $new_user $sciezka;
echo "skrypt wykonal sie poprawnie" 
else 
        echo "nie ma takiego usera";
fi