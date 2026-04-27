TYPE=VIEW
query=select `db8`.`pacjent`.`imie_pac` AS `imie_pac`,`db8`.`specjalista`.`nazwisko_lekarza` AS `nazwisko_lekarza` from (`db8`.`pacjent` join `db8`.`specjalista` on(`db8`.`pacjent`.`id_pac` = `db8`.`specjalista`.`id_sp`))
md5=4f61e9d7a54158a39ce06519e44208b2
updatable=1
algorithm=0
definer_user=root
definer_host=localhost
suid=2
with_check_option=0
timestamp=0001699618553330205
create-version=2
source=SELECT pacjent.imie_pac  , specjalista.nazwisko_lekarza FROM pacjent INNER JOIN specjalista ON pacjent.id_pac=specjalista.id_sp
client_cs_name=utf8mb4
connection_cl_name=utf8mb4_unicode_ci
view_body_utf8=select `db8`.`pacjent`.`imie_pac` AS `imie_pac`,`db8`.`specjalista`.`nazwisko_lekarza` AS `nazwisko_lekarza` from (`db8`.`pacjent` join `db8`.`specjalista` on(`db8`.`pacjent`.`id_pac` = `db8`.`specjalista`.`id_sp`))
mariadb-version=100428
