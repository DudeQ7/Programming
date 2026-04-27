-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 06, 2023 at 02:35 PM
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
-- Database: `db9`
--

-- --------------------------------------------------------

--
-- Table structure for table `odloty`
--

CREATE TABLE `odloty` (
  `id` int(11) NOT NULL,
  `samoloty_id` int(11) DEFAULT NULL,
  `nr_rejsu` varchar(8) DEFAULT NULL,
  `kierunek` varchar(10) DEFAULT NULL,
  `czas` time DEFAULT NULL,
  `dzien` date DEFAULT NULL,
  `status_lotu` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `odloty`
--

INSERT INTO `odloty` (`id`, `samoloty_id`, `nr_rejsu`, `kierunek`, `czas`, `dzien`, `status_lotu`) VALUES
(0, NULL, 'RYN0001', 'Berlin', '10:00:00', '2023-10-06', 'O_czasie'),
(1, NULL, 'RYN0002', 'Warszawa', '12:30:05', '2023-10-07', 'Opozniony'),
(2, NULL, 'RYN0003', 'Szczecin', '15:00:00', '2024-05-09', 'Zaplanowany');

-- --------------------------------------------------------

--
-- Table structure for table `przyloty`
--

CREATE TABLE `przyloty` (
  `id` int(11) NOT NULL,
  `samoloty_id` int(11) DEFAULT NULL,
  `nr_rejsu` varchar(8) DEFAULT NULL,
  `kierunek` varchar(10) DEFAULT NULL,
  `czas` time DEFAULT NULL,
  `dzien` date DEFAULT NULL,
  `status_lotu` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `samoloty`
--

CREATE TABLE `samoloty` (
  `id` int(11) NOT NULL,
  `typ` varchar(20) DEFAULT NULL,
  `linie` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `odloty`
--
ALTER TABLE `odloty`
  ADD PRIMARY KEY (`id`),
  ADD KEY `samoloty_id` (`samoloty_id`);

--
-- Indexes for table `przyloty`
--
ALTER TABLE `przyloty`
  ADD PRIMARY KEY (`id`),
  ADD KEY `samoloty_id` (`samoloty_id`);

--
-- Indexes for table `samoloty`
--
ALTER TABLE `samoloty`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `odloty`
--
ALTER TABLE `odloty`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `przyloty`
--
ALTER TABLE `przyloty`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `samoloty`
--
ALTER TABLE `samoloty`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `odloty`
--
ALTER TABLE `odloty`
  ADD CONSTRAINT `odloty_ibfk_1` FOREIGN KEY (`samoloty_id`) REFERENCES `samoloty` (`id`);

--
-- Constraints for table `przyloty`
--
ALTER TABLE `przyloty`
  ADD CONSTRAINT `przyloty_ibfk_1` FOREIGN KEY (`samoloty_id`) REFERENCES `samoloty` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
