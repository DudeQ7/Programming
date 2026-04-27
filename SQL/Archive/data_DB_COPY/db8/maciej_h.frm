TYPE=VIEW
query=select `db8`.`pacjent`.`nazwisko_pac` AS `nazwisko_pac`,`db8`.`pacjent`.`imie_pac` AS `imie_pac`,`db8`.`data_porady`.`id_por` AS `id_por`,`db8`.`data_porady`.`data_porady` AS `data_porady`,`db8`.`data_porady`.`id_pac` AS `id_pac`,`db8`.`specjalista`.`specjalizacja` AS `specjalizacja`,`db8`.`specjalista`.`nazwisko_lekarza` AS `nazwisko_lekarza`,`db8`.`specjalista`.`imie_lekarza` AS `imie_lekarza`,`db8`.`specjalista`.`numer_gabinetu` AS `numer_gabinetu`,`db8`.`specjalista`.`cena_porady` AS `cena_porady` from ((`db8`.`data_porady` join `db8`.`pacjent` on(`db8`.`data_porady`.`id_pac` = `db8`.`pacjent`.`id_pac`)) join `db8`.`specjalista` on(`db8`.`data_porady`.`id_sp` = `db8`.`specjalista`.`id_sp`))
md5=83fed88dfdc7f26ae7fc7ef2d9da5237
updatable=1
algorithm=0
definer_user=root
definer_host=localhost
suid=2
with_check_option=0
timestamp=0001699614300544685
create-version=2
source=SELECT pacjent.nazwisko_pac , pacjent.imie_pac , data_porady.id_por , data_porady.data_porady , data_porady.id_pac , specjalista.specjalizacja , specjalista.nazwisko_lekarza , specjalista.imie_lekarza , specjalista.numer_gabinetu , specjalista.cena_porady FROM data_porady INNER JOIN pacjent ON data_porady.id_pac=pacjent.id_pac INNER JOIN specjalista ON data_porady.id_sp=specjalista.id_sp
client_cs_name=utf8mb4
connection_cl_name=utf8mb4_unicode_ci
view_body_utf8=select `db8`.`pacjent`.`nazwisko_pac` AS `nazwisko_pac`,`db8`.`pacjent`.`imie_pac` AS `imie_pac`,`db8`.`data_porady`.`id_por` AS `id_por`,`db8`.`data_porady`.`data_porady` AS `data_porady`,`db8`.`data_porady`.`id_pac` AS `id_pac`,`db8`.`specjalista`.`specjalizacja` AS `specjalizacja`,`db8`.`specjalista`.`nazwisko_lekarza` AS `nazwisko_lekarza`,`db8`.`specjalista`.`imie_lekarza` AS `imie_lekarza`,`db8`.`specjalista`.`numer_gabinetu` AS `numer_gabinetu`,`db8`.`specjalista`.`cena_porady` AS `cena_porady` from ((`db8`.`data_porady` join `db8`.`pacjent` on(`db8`.`data_porady`.`id_pac` = `db8`.`pacjent`.`id_pac`)) join `db8`.`specjalista` on(`db8`.`data_porady`.`id_sp` = `db8`.`specjalista`.`id_sp`))
mariadb-version=100428
