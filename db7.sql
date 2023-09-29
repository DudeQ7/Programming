-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 29, 2023 at 02:11 PM
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
-- Database: `db7`
--

-- --------------------------------------------------------

--
-- Table structure for table `klienci`
--

CREATE TABLE `klienci` (
  `id` int(10) UNSIGNED NOT NULL,
  `Typy_id` int(10) UNSIGNED NOT NULL,
  `imie` text DEFAULT NULL,
  `nazwisko` text DEFAULT NULL,
  `zdjecie` varchar(20) DEFAULT NULL,
  `punkty` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `klienci`
--

INSERT INTO `klienci` (`id`, `Typy_id`, `imie`, `nazwisko`, `zdjecie`, `punkty`) VALUES
(1, 2, 'Anna', 'Kowalska', 'anna.jpg', 2000),
(2, 2, 'Ewa', 'Nowakowska', 'ewa.jpg', 2045),
(3, 1, 'Krystyna', 'Nowakowska', 'krycha.jpg', 100),
(4, 3, 'Jan', 'Nowak', 'janek.jpg', 3305),
(5, 2, 'John', 'Smith', 'john.jpg', 2005),
(6, 3, 'Judy', 'Beck', 'judy.jpg', 3055),
(7, 1, 'Marcin', 'Kowalski', 'marcin.jpg', 1045),
(8, 1, 'Kris', 'Smith', 'Kris.jpg', 0),
(9, 1, 'Jacek', 'Jackowski', 'jacek.jpg', 45);

-- --------------------------------------------------------

--
-- Table structure for table `opinie`
--

CREATE TABLE `opinie` (
  `id` int(10) UNSIGNED NOT NULL,
  `Klienci_id` int(10) UNSIGNED NOT NULL,
  `opinia` text DEFAULT NULL,
  `ocena` tinyint(3) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `opinie`
--

INSERT INTO `opinie` (`id`, `Klienci_id`, `opinia`, `ocena`) VALUES
(1, 1, 'Dobra współpraca, zawsze świeże towary i miła obsługa', 6),
(2, 2, 'Polecam hurtownię za profesjonalne podejście do klienta', 6),
(3, 3, 'Wszystkie transakcje przebiegły sprawnie', 5),
(4, 4, 'Polecam hurtownię za profesjonalne podejście do klienta', 5),
(5, 5, 'Wszystkie transakcje przebiegły sprawnie', 5),
(6, 6, 'Truskawki, które zakupiłam były nieświeże, poza tym wszystko ok', 4);

-- --------------------------------------------------------

--
-- Table structure for table `typy`
--

CREATE TABLE `typy` (
  `id` int(10) UNSIGNED NOT NULL,
  `nazwa` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `typy`
--

INSERT INTO `typy` (`id`, `nazwa`) VALUES
(1, 'zwykły'),
(2, 'złoty'),
(3, 'platynowy');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `klienci`
--
ALTER TABLE `klienci`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `opinie`
--
ALTER TABLE `opinie`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `typy`
--
ALTER TABLE `typy`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `klienci`
--
ALTER TABLE `klienci`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `opinie`
--
ALTER TABLE `opinie`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `typy`
--
ALTER TABLE `typy`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
