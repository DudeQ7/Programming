TYPE=TRIGGERS
triggers='CREATE DEFINER=`root`@`localhost` TRIGGER `pensja_roczna_n` AFTER UPDATE ON `pracownik` FOR EACH ROW UPDATE pracownik\nSET pensja_roczna = (stawka_godzinowa * 2080)'
sql_modes=1098907648
definers='root@localhost'
client_cs_names='utf8mb4'
connection_cl_names='utf8mb4_unicode_ci'
db_cl_names='utf8mb4_general_ci'
created=1701773487746516
