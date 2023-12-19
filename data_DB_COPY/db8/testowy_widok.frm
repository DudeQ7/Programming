TYPE=VIEW
query=select `db8`.`pacjent`.`id_pac` AS `id_pac`,`db8`.`pacjent`.`nazwisko_pac` AS `nazwisko_pac`,`db8`.`pacjent`.`imie_pac` AS `imie_pac`,`db8`.`pacjent`.`adres_pac` AS `adres_pac`,`db8`.`pacjent`.`telefon_pac` AS `telefon_pac`,`db8`.`specjalista`.`id_sp` AS `id_sp`,`db8`.`specjalista`.`specjalizacja` AS `specjalizacja`,`db8`.`specjalista`.`nazwisko_lekarza` AS `nazwisko_lekarza`,`db8`.`specjalista`.`imie_lekarza` AS `imie_lekarza`,`db8`.`specjalista`.`numer_gabinetu` AS `numer_gabinetu`,`db8`.`specjalista`.`cena_porady` AS `cena_porady` from (`db8`.`pacjent` join `db8`.`specjalista` on(`db8`.`pacjent`.`id_pac` = `db8`.`specjalista`.`id_sp`))
md5=2efe60af46478233827b1fe3b145246a
updatable=1
algorithm=0
definer_user=root
definer_host=localhost
suid=2
with_check_option=0
timestamp=0001699618187634341
create-version=2
source=SELECT pacjent.* , specjalista.* FROM pacjent INNER JOIN specjalista ON pacjent.id_pac=specjalista.id_sp
client_cs_name=utf8mb4
connection_cl_name=utf8mb4_unicode_ci
view_body_utf8=select `db8`.`pacjent`.`id_pac` AS `id_pac`,`db8`.`pacjent`.`nazwisko_pac` AS `nazwisko_pac`,`db8`.`pacjent`.`imie_pac` AS `imie_pac`,`db8`.`pacjent`.`adres_pac` AS `adres_pac`,`db8`.`pacjent`.`telefon_pac` AS `telefon_pac`,`db8`.`specjalista`.`id_sp` AS `id_sp`,`db8`.`specjalista`.`specjalizacja` AS `specjalizacja`,`db8`.`specjalista`.`nazwisko_lekarza` AS `nazwisko_lekarza`,`db8`.`specjalista`.`imie_lekarza` AS `imie_lekarza`,`db8`.`specjalista`.`numer_gabinetu` AS `numer_gabinetu`,`db8`.`specjalista`.`cena_porady` AS `cena_porady` from (`db8`.`pacjent` join `db8`.`specjalista` on(`db8`.`pacjent`.`id_pac` = `db8`.`specjalista`.`id_sp`))
mariadb-version=100428
