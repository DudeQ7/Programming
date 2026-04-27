-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 03, 2023 at 04:33 PM
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
-- Database: `db1`
--

-- --------------------------------------------------------

--
-- Table structure for table `klient`
--

CREATE TABLE `klient` (
  `id_k` int(11) NOT NULL,
  `nazwisko` varchar(30) DEFAULT NULL,
  `imie` varchar(20) DEFAULT NULL,
  `telefon` varchar(17) DEFAULT NULL,
  `email` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `klient`
--

INSERT INTO `klient` (`id_k`, `nazwisko`, `imie`, `telefon`, `email`) VALUES
(1, 'Kowalski', 'Jan', '111222333', 'kowal@gmail.com'),
(12, 'Borek', 'Lucas', '552522111', 'borek1@gmail.com'),
(13, 'Bansiek', 'Adrian', '551222111', 'banasiek2@gmail.com'),
(14, 'Oskar', 'Prus', '144231522', 'oskar.prus@gmail.com'),
(15, 'Irek', 'dziewietnasty', '144231542', 'john4.doe@gufum.com'),
(16, 'Ewa', 'Nowak', '123456789', 'ewa5.nowak@gmail.com'),
(17, 'Alice', 'Smith', '987654321', 'alice6.smith@gmail.com'),
(18, 'Mark', 'Johnson', '555555555', 'mark7.johnson@gmail.com'),
(19, 'Laura', 'Williams', '111111111', 'laura8.williams@gmail.com'),
(20, 'Robert', 'Brown', '999999999', 'robert9.brown@gmail.com'),
(21, 'Sarah', 'Lee', '888888888', 'sarah10.lee@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `pojazd`
--

CREATE TABLE `pojazd` (
  `id_p` int(11) NOT NULL,
  `Marka` enum('Volvo','Toyota','Hyundai','VW','Opel','Audi','Ford') DEFAULT NULL,
  `Model` varchar(30) DEFAULT NULL,
  `Rocznik` year(4) DEFAULT NULL,
  `Przebieg` double(12,2) DEFAULT NULL,
  `typ_nadwozia` enum('Kombi','Coupe','Dostawczy','SUV','Sedan') DEFAULT NULL,
  `Cena` int(6) DEFAULT NULL,
  `prowizja` float(6,2) DEFAULT NULL,
  `kolory` set('czarny','bialy','czerwony','zielony') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pojazd`
--

INSERT INTO `pojazd` (`id_p`, `Marka`, `Model`, `Rocznik`, `Przebieg`, `typ_nadwozia`, `Cena`, `prowizja`, `kolory`) VALUES
(1, 'VW', 'Golf_V', '2008', 250000.00, 'Coupe', 25000, 2500.00, 'czarny'),
(2, 'Toyota', 'Avensis', '2010', 215000.00, 'Sedan', 18000, 1800.00, 'bialy'),
(6, 'Ford', 'MustangGT', '2023', 10.00, 'Coupe', 250000, 9999.99, 'czerwony'),
(7, 'Toyota', 'Supra', '1978', 300000.00, 'Coupe', 150000, 9999.99, 'czerwony'),
(8, 'VW', 'Touran', '2003', 300000.00, 'Kombi', 15000, 1500.00, 'czarny'),
(9, 'Toyota', 'Camry', '2010', 100000.00, 'Sedan', 20000, 2000.00, 'czarny'),
(10, 'Ford', 'Focus', '2015', 80000.00, 'Sedan', 18000, 1800.00, 'czarny'),
(11, 'VW', 'Civic', '2012', 90000.00, 'Sedan', 17000, 1700.00, 'czarny'),
(12, 'VW', 'Altima', '2018', 60000.00, 'Sedan', 22000, 2200.00, 'czarny'),
(13, 'VW', 'Malibu', '2014', 75000.00, 'Sedan', 19000, 1900.00, 'czerwony'),
(14, 'VW', '3 Series', '2019', 50000.00, 'Sedan', 25000, 2500.00, 'czarny'),
(15, 'Hyundai', 'Elantra', '2017', 70000.00, 'Sedan', 16000, 1600.00, 'czarny'),
(16, 'VW', 'C-Class', '2016', 85000.00, 'Sedan', 23000, 2300.00, 'czarny'),
(17, 'VW', 'A4', '2013', 95000.00, 'Sedan', 21000, 2100.00, 'czarny');

-- --------------------------------------------------------

--
-- Table structure for table `sprzedaz`
--

CREATE TABLE `sprzedaz` (
  `id` int(11) NOT NULL,
  `id_k_FK` int(11) DEFAULT NULL,
  `id_p_FK` int(11) DEFAULT NULL,
  `prowizja` float(5,2) DEFAULT NULL,
  `data_zamkniecia` year(4) DEFAULT NULL,
  `data_otwarcia` year(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `klient`
--
ALTER TABLE `klient`
  ADD PRIMARY KEY (`id_k`),
  ADD UNIQUE KEY `telefon` (`telefon`),
  ADD UNIQUE KEY `email` (`email`);

--
-- Indexes for table `pojazd`
--
ALTER TABLE `pojazd`
  ADD PRIMARY KEY (`id_p`);

--
-- Indexes for table `sprzedaz`
--
ALTER TABLE `sprzedaz`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_k_FK` (`id_k_FK`),
  ADD KEY `id_p_FK` (`id_p_FK`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `klient`
--
ALTER TABLE `klient`
  MODIFY `id_k` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT for table `pojazd`
--
ALTER TABLE `pojazd`
  MODIFY `id_p` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `sprzedaz`
--
ALTER TABLE `sprzedaz`
  ADD CONSTRAINT `sprzedaz_ibfk_1` FOREIGN KEY (`id_k_FK`) REFERENCES `klient` (`id_k`),
  ADD CONSTRAINT `sprzedaz_ibfk_2` FOREIGN KEY (`id_p_FK`) REFERENCES `pojazd` (`id_p`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
