-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 24, 2023 at 12:26 AM
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
-- Database: `db0`
--

-- --------------------------------------------------------

--
-- Table structure for table `klient`
--

CREATE TABLE `klient` (
  `id_k` int(11) NOT NULL,
  `id_k_FK` int(11) DEFAULT NULL,
  `imie_i_nazwisko` varchar(60) DEFAULT NULL,
  `nr_telefonu` varchar(17) DEFAULT NULL,
  `email` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `nieruchomosc`
--

CREATE TABLE `nieruchomosc` (
  `id_n` int(11) NOT NULL,
  `typ_nieruchomosci` set('dom','garaz','mieszkanie','dzialka') DEFAULT NULL,
  `cena` int(8) DEFAULT NULL,
  `miasto` varchar(25) DEFAULT NULL,
  `ulica` varchar(40) DEFAULT NULL,
  `nr_domu` varchar(5) DEFAULT NULL,
  `nr_lokalu` varchar(5) DEFAULT NULL,
  `powierzchnia` int(11) DEFAULT NULL,
  `ilosc_pokoji` int(11) DEFAULT NULL,
  `pietro` int(3) DEFAULT NULL,
  `prowizja` int(8) DEFAULT NULL CHECK (`prowizja` < `cena`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

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
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `klient`
--
ALTER TABLE `klient`
  MODIFY `id_k` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `nieruchomosc`
--
ALTER TABLE `nieruchomosc`
  MODIFY `id_n` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
