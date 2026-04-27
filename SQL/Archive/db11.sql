-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 13, 2023 at 12:57 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db11`
--

-- --------------------------------------------------------

--
-- Table structure for table `klient`
--

CREATE TABLE `klient` (
  `id_k` int(11) NOT NULL,
  `imie` varchar(20) NOT NULL,
  `nazwisko` varchar(30) NOT NULL,
  `telefon` int(9) DEFAULT NULL,
  `email` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `klient`
--

INSERT INTO `klient` (`id_k`, `imie`, `nazwisko`, `telefon`, `email`) VALUES
(1, 'jan', 'Nowak', 345789234, 'nowak@gmail.com'),
(2, 'Andrzej', 'Kowalski', 456654456, NULL),
(3, 'Adam', 'Wolski', 344485534, 'wolski@gmail.com'),
(4, 'Wlodzimierz', 'Potowski', 765456876, 'potos@wp.pl'),
(5, 'krzysztof', 'Powolski', 345234123, NULL),
(6, 'Waclaw', 'Kips', 345234123, 'klips@op.ue'),
(7, 'Zdzislaw', 'Arct', 456345765, 'atos@ll.om'),
(8, 'Seweryn', 'Sosik', 236743234, NULL),
(9, 'Adam', 'Laskowik', 341234987, 'laska@xx.yy'),
(10, 'Adam', 'Nowak', 889766111, NULL),
(11, 'Tadeusz', 'Nowak', NULL, 'nowak@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `nieruchomosc`
--

CREATE TABLE `nieruchomosc` (
  `id_n` int(11) NOT NULL,
  `rodzaj` set('grunt','dom','mieszkanie','wolnostojacy','zabudowa szeregowa','inny','garaż','zabudowania gospodarcze') NOT NULL,
  `rok_budowy` year(4) DEFAULT NULL,
  `miasto` varchar(40) NOT NULL,
  `ulica` varchar(50) NOT NULL,
  `cena` float NOT NULL,
  `prowizja` float NOT NULL,
  `stan` enum('sprzedany','zarezerwowany','wolny','') NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `nieruchomosc`
--

INSERT INTO `nieruchomosc` (`id_n`, `rodzaj`, `rok_budowy`, `miasto`, `ulica`, `cena`, `prowizja`, `stan`) VALUES
(1, 'dom', '1955', 'Szczecin', 'Zapomniana 1', 1000000, 50000, 'wolny'),
(2, 'dom', '2000', 'Szczecin', 'Waska 5', 500000, 20000, 'wolny'),
(3, 'dom', '2010', 'Police', 'Szeroka 22', 700000, 80000, 'wolny'),
(4, 'dom', '2000', 'Goleniow', 'Pomorska 3', 1100000, 85000, 'wolny'),
(5, 'mieszkanie', '1966', 'Szczecin', 'Struga 5/1', 250000, 45000, 'wolny'),
(6, 'mieszkanie', '1910', 'Szczecin', 'Niemierzynska 55/5', 450000, 15000, 'wolny'),
(7, 'grunt', NULL, 'Police', 'Chemiczna 33', 150000, 10000, 'zarezerwowany'),
(8, 'grunt', NULL, 'Stargard', 'Pogodna 67', 250000, 55000, 'sprzedany'),
(9, 'dom,wolnostojacy,garaż', '1999', 'Szczecin', 'Zapadla 9', 15000000, 100000, 'wolny'),
(10, 'grunt,zabudowania gospodarcze', '0000', 'Goleniow', 'Szczecinska 76', 500000, 95000, 'sprzedany'),
(11, 'garaż', '0000', 'Szczecin', 'Arkonska', 55000, 5000, 'wolny');

-- --------------------------------------------------------

--
-- Table structure for table `sprzedaz`
--

CREATE TABLE `sprzedaz` (
  `id_s` int(11) NOT NULL,
  `data_rezerwacji` date NOT NULL,
  `data_sprzedazy` date DEFAULT NULL,
  `id_k_FK` int(11) NOT NULL,
  `id_n_FK` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `sprzedaz`
--

INSERT INTO `sprzedaz` (`id_s`, `data_rezerwacji`, `data_sprzedazy`, `id_k_FK`, `id_n_FK`) VALUES
(1, '2021-03-01', '2021-03-08', 9, 4),
(3, '2021-02-04', NULL, 5, 11),
(4, '2021-02-09', NULL, 9, 7),
(5, '2021-03-02', '2021-03-05', 5, 8);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `klient`
--
ALTER TABLE `klient`
  ADD PRIMARY KEY (`id_k`);

--
-- Indexes for table `nieruchomosc`
--
ALTER TABLE `nieruchomosc`
  ADD PRIMARY KEY (`id_n`);

--
-- Indexes for table `sprzedaz`
--
ALTER TABLE `sprzedaz`
  ADD PRIMARY KEY (`id_s`),
  ADD KEY `FK_sk` (`id_k_FK`),
  ADD KEY `FK_sn` (`id_n_FK`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `klient`
--
ALTER TABLE `klient`
  MODIFY `id_k` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `nieruchomosc`
--
ALTER TABLE `nieruchomosc`
  MODIFY `id_n` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `sprzedaz`
--
ALTER TABLE `sprzedaz`
  MODIFY `id_s` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `sprzedaz`
--
ALTER TABLE `sprzedaz`
  ADD CONSTRAINT `FK_sk` FOREIGN KEY (`id_k_FK`) REFERENCES `klient` (`id_k`),
  ADD CONSTRAINT `FK_sn` FOREIGN KEY (`id_n_FK`) REFERENCES `nieruchomosc` (`id_n`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
