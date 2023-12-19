TYPE=TRIGGERS
triggers='CREATE DEFINER=`root`@`localhost` TRIGGER godzinowa\nAFTER INSERT ON pracownik \nFOR EACH ROW\nUPDATE pracownik\nSET new.pensja = (new.stawka_godzinowa * 20480)' 'CREATE DEFINER=`root`@`localhost` TRIGGER BEFORE_update \nBEFORE UPDATE ON pracownik\nFOR each ROW\nset new.pensja = (new.stawka_godzinowa * 2080)'
sql_modes=1098907648 1098907648
definers='root@localhost' 'root@localhost'
client_cs_names='utf8mb4' 'utf8mb4'
connection_cl_names='utf8mb4_unicode_ci' 'utf8mb4_unicode_ci'
db_cl_names='utf8mb4_general_ci' 'utf8mb4_general_ci'
created=1701772182191544 1701772358051563
