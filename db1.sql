-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 24, 2023 at 12:27 AM
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
-- Table structure for table `abc`
--

CREATE TABLE `abc` (
  `id` int(11) NOT NULL,
  `marka` char(20) DEFAULT 'FORD',
  `model` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

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

-- --------------------------------------------------------

--
-- Table structure for table `pojazd`
--

CREATE TABLE `pojazd` (
  `id_p` int(11) NOT NULL,
  `Marka` enum('Volvo','Toyota','Hyundai','VW','Opel','Audi','Ford','Sedan') DEFAULT NULL,
  `Model` varchar(30) DEFAULT NULL,
  `Rocznik` year(4) DEFAULT NULL,
  `Przebieg` double(12,2) DEFAULT NULL,
  `typ_nadwozia` enum('Kombi','Coupe','Dostawczy','SUV','Sedan') DEFAULT NULL,
  `Cena` int(6) DEFAULT NULL,
  `prowizja` float(6,2) DEFAULT NULL,
  `kolory` set('czarny','bialy','czerwony','zielony') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `abc`
--
ALTER TABLE `abc`
  ADD PRIMARY KEY (`id`);

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
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `klient`
--
ALTER TABLE `klient`
  MODIFY `id_k` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `pojazd`
--
ALTER TABLE `pojazd`
  MODIFY `id_p` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
