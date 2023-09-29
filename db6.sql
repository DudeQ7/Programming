-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 29, 2023 at 01:30 PM
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
-- Database: `db6`
--

-- --------------------------------------------------------

--
-- Table structure for table `karta`
--

CREATE TABLE `karta` (
  `nr_karty` int(11) NOT NULL,
  `id_k_FK` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `karta`
--

INSERT INTO `karta` (`nr_karty`, `id_k_FK`) VALUES
(0, NULL),
(3, 1);

-- --------------------------------------------------------

--
-- Table structure for table `uczen`
--

CREATE TABLE `uczen` (
  `id` int(11) NOT NULL,
  `imie` varchar(35) DEFAULT NULL,
  `nazwisko` varchar(45) DEFAULT NULL,
  `profil` varchar(4) DEFAULT NULL,
  `rok_przystapienia` year(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `uczen`
--

INSERT INTO `uczen` (`id`, `imie`, `nazwisko`, `profil`, `rok_przystapienia`) VALUES
(1, 'Szymon', 'Gawel', '4TiP', '2025'),
(5, 'Jan', 'Kowalski', '2TiP', '2024'),
(6, 'Dawid', 'Gradowski', '4TiP', '2025'),
(7, 'Lukasz', 'Borkowski', 'TiP', '2025'),
(8, 'Jan', 'Kowal', '2TiP', '2024'),
(9, 'Maria', 'Lukaszowa', '2TiP', '2025');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `karta`
--
ALTER TABLE `karta`
  ADD PRIMARY KEY (`nr_karty`),
  ADD UNIQUE KEY `id_k_FK` (`id_k_FK`);

--
-- Indexes for table `uczen`
--
ALTER TABLE `uczen`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `uczen`
--
ALTER TABLE `uczen`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `karta`
--
ALTER TABLE `karta`
  ADD CONSTRAINT `karta_ibfk_1` FOREIGN KEY (`id_k_FK`) REFERENCES `uczen` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
