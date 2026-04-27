-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 06, 2023 at 02:36 PM
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
-- Database: `db8`
--

-- --------------------------------------------------------

--
-- Table structure for table `data_porady`
--

CREATE TABLE `data_porady` (
  `id_por` int(11) NOT NULL,
  `data_porady` date NOT NULL,
  `id_pac` int(11) NOT NULL,
  `id_sp` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `data_porady`
--

INSERT INTO `data_porady` (`id_por`, `data_porady`, `id_pac`, `id_sp`) VALUES
(1, '2020-10-30', 9, 1),
(5, '2020-10-29', 4, 1),
(6, '2020-10-30', 9, 2),
(7, '2020-10-30', 9, 8);

-- --------------------------------------------------------

--
-- Table structure for table `pacjent`
--

CREATE TABLE `pacjent` (
  `id_pac` int(11) NOT NULL,
  `nazwisko_pac` varchar(30) NOT NULL,
  `imie_pac` varchar(20) NOT NULL,
  `adres_pac` text NOT NULL,
  `telefon_pac` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pacjent`
--

INSERT INTO `pacjent` (`id_pac`, `nazwisko_pac`, `imie_pac`, `adres_pac`, `telefon_pac`) VALUES
(2, 'Nowak', 'Jan', 'Szczecin ul. Pomorska 1m4', 234789465),
(3, 'Kowalski', 'Adam', 'Szczecin ul. Struga 4', 239807653),
(4, 'Puda', 'Anna', 'Szczecin ul. Zapomniana 77', 765902134),
(5, 'Dabrowski', 'Marek', 'Koszalin ul. Inna 5', 0),
(6, 'Zawada', 'Antoni', 'Police ul. Chemiczna 6 m9', 765689043),
(7, 'Wocer', 'Andrzej', 'Szczecin ul. Szybowcowa 15', 0),
(8, 'Inert', 'Małgorzata', 'Goleniów ul. Smocza 1', 670912347),
(9, 'Nowak', 'Ewa', 'Szczecin ul. Kolarska 2', 0),
(10, 'Jordon', 'Mateusz', 'Pniewy ul. Polna 8 m8', 980126466),
(11, 'Zawada', 'Jan', 'Police ul. Prosta 3', 998054678);

-- --------------------------------------------------------

--
-- Table structure for table `specjalista`
--

CREATE TABLE `specjalista` (
  `id_sp` int(11) NOT NULL,
  `specjalizacja` varchar(20) NOT NULL,
  `nazwisko_lekarza` varchar(30) NOT NULL,
  `imie_lekarza` varchar(20) NOT NULL,
  `numer_gabinetu` int(3) NOT NULL,
  `cena_porady` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `specjalista`
--

INSERT INTO `specjalista` (`id_sp`, `specjalizacja`, `nazwisko_lekarza`, `imie_lekarza`, `numer_gabinetu`, `cena_porady`) VALUES
(1, 'otolaryngolog', 'Michalski', 'Waclaw', 21, 120),
(2, 'okulista', 'Adamczyk', 'Krzysztof', 22, 110),
(3, 'gastrolog', 'Bobrowski', 'Jan', 3, 100),
(4, 'gastrolog', 'Kowalska', 'Anna', 3, 100),
(5, 'laryngolog', 'Zielinska', 'Bozena', 4, 90),
(6, 'chirurg', 'Mazur', 'Marian', 5, 110),
(7, 'chirurg', 'Grabowski', 'Jan', 5, 110),
(8, 'urolog', 'Piotrowska', 'Joanna', 6, 80),
(9, 'neurolog', 'Grabowska', 'Ewa', 7, 90),
(10, 'neurolog', 'Kaczmarek', 'Jan', 10, 90);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `data_porady`
--
ALTER TABLE `data_porady`
  ADD PRIMARY KEY (`id_por`),
  ADD KEY `id_pac` (`id_pac`),
  ADD KEY `id_sp` (`id_sp`);

--
-- Indexes for table `pacjent`
--
ALTER TABLE `pacjent`
  ADD PRIMARY KEY (`id_pac`);

--
-- Indexes for table `specjalista`
--
ALTER TABLE `specjalista`
  ADD PRIMARY KEY (`id_sp`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `data_porady`
--
ALTER TABLE `data_porady`
  MODIFY `id_por` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `pacjent`
--
ALTER TABLE `pacjent`
  MODIFY `id_pac` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `specjalista`
--
ALTER TABLE `specjalista`
  MODIFY `id_sp` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `data_porady`
--
ALTER TABLE `data_porady`
  ADD CONSTRAINT `data_porady_ibfk_1` FOREIGN KEY (`id_pac`) REFERENCES `pacjent` (`id_pac`),
  ADD CONSTRAINT `data_porady_ibfk_2` FOREIGN KEY (`id_sp`) REFERENCES `specjalista` (`id_sp`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
