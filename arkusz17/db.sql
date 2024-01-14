-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sty 11, 2024 at 10:00 AM
-- Wersja serwera: 10.4.28-MariaDB
-- Wersja PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `florists`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `discounts`
--

CREATE TABLE `discounts` (
  `id` int(11) NOT NULL,
  `flower_id` int(11) DEFAULT NULL,
  `percent_off` tinyint(4) DEFAULT NULL,
  `date_start` timestamp NULL DEFAULT NULL,
  `date_end` timestamp NULL DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `discounts`
--

INSERT INTO `discounts` (`id`, `flower_id`, `percent_off`, `date_start`, `date_end`) VALUES
(1, 1, 10, '2023-12-31 23:00:00', '2024-01-31 22:59:59'),
(2, 1, 20, '2023-12-31 23:00:00', '2024-01-31 22:59:59'),
(3, 2, 15, '2023-12-31 23:00:00', '2024-01-31 22:59:59'),
(4, 1, 10, '2023-11-27 23:00:00', '2023-11-29 22:59:59'),
(5, 3, 5, '2024-01-01 22:15:01', '2024-01-31 22:59:59'),
(6, 5, 7, '2023-12-31 23:00:00', '2024-01-31 22:59:59'),
(7, 4, 10, '2024-02-01 19:00:00', '2024-02-02 22:59:59'),
(8, 5, 20, '2024-02-07 23:00:00', '2024-02-08 23:00:00');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `flowers`
--

CREATE TABLE `flowers` (
  `id` int(11) NOT NULL,
  `name` varchar(255) DEFAULT NULL,
  `price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `flowers`
--

INSERT INTO `flowers` (`id`, `name`, `price`) VALUES
(1, 'stokrotka', 1999),
(2, 'bratek', 4000),
(3, 'przebiśnieg', 2000),
(4, 'chryzantema', 30000),
(5, 'krukus', 2500),
(6, 'tulipan', 2999);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `orders`
--

CREATE TABLE `orders` (
  `id` int(11) NOT NULL,
  `flower_id` int(11) DEFAULT NULL,
  `count` int(11) DEFAULT NULL,
  `cost` int(11) DEFAULT NULL,
  `address` varchar(255) DEFAULT NULL,
  `phone` varchar(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`id`, `flower_id`, `count`, `cost`, `address`, `phone`) VALUES
(1, 4, 3, 90000, 'ul. Nadbystrzycka 36B', '+48 123123123'),
(2, 2, 5, 17000, 'ul. Głowackiego 2', '+48 333444555'),
(3, 6, 10, 29990, 'ul. Długa 6', '+48 777555666'),
(4, 5, 1, 2500, 'al. Warszawskie 43a', '+49 987987987'),
(5, 4, 30, 900000, 'al. Jerozolimskie 12', '+48 135246357'),
(6, 3, 11, 22000, 'za cukrownią 15', '+14 246966536'),
(7, 6, 3, 8997, 'ul. Szkolna 17', '+18 987567243'),
(8, 2, 40, 136000, 'ul. Spadochroniarzy 32B', '+48 684742683'),
(9, 5, 12, 30000, 'ul. Czwartek 2', '+48 857496836'),
(10, 3, 14, 28000, 'ul. Bronowicka 4', '+48 503802186');

--
-- Wyzwalacze `orders`
--
DELIMITER $$
CREATE TRIGGER `insert` BEFORE INSERT ON `orders` FOR EACH ROW BEGIN
DECLARE discount tinyint;
SET discount = 1*(SELECT MAX(percent_off) FROM discounts WHERE flower_id=NEW.flower_id);
SET NEW.cost = NEW.count * (SELECT price FROM flowers WHERE id=NEW.flower_id);
IF discount IS NOT NULL THEN
	SET NEW.cost = NEW.cost * (100-discount) / 100;
END IF;
END
$$
DELIMITER ;

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `discounts`
--
ALTER TABLE `discounts`
  ADD PRIMARY KEY (`id`),
  ADD KEY `flower` (`flower_id`) USING BTREE;

--
-- Indeksy dla tabeli `flowers`
--
ALTER TABLE `flowers`
  ADD PRIMARY KEY (`id`);

--
-- Indeksy dla tabeli `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`id`),
  ADD KEY `flower` (`flower_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `discounts`
--
ALTER TABLE `discounts`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `flowers`
--
ALTER TABLE `flowers`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `orders`
--
ALTER TABLE `orders`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `discounts`
--
ALTER TABLE `discounts`
  ADD CONSTRAINT `discounts_ibfk_1` FOREIGN KEY (`flower_id`) REFERENCES `flowers` (`id`);

--
-- Constraints for table `orders`
--
ALTER TABLE `orders`
  ADD CONSTRAINT `flower` FOREIGN KEY (`flower_id`) REFERENCES `flowers` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
