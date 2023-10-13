-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 13, 2023 at 10:12 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.0.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db12`
--

-- --------------------------------------------------------

--
-- Table structure for table `karty_wedkarskie`
--

CREATE TABLE `karty_wedkarskie` (
  `id` int(10) UNSIGNED NOT NULL,
  `imie` text DEFAULT NULL,
  `nazwisko` text DEFAULT NULL,
  `adres` text DEFAULT NULL,
  `data_zezwolenia` date DEFAULT NULL,
  `punkty` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `karty_wedkarskie`
--

INSERT INTO `karty_wedkarskie` (`id`, `imie`, `nazwisko`, `adres`, `data_zezwolenia`, `punkty`) VALUES
(1, 'Jan', 'Kowalski', 'Warszawa, Aleje Jerozolimskie 65/4', '2018-02-15', 23),
(2, 'Andrzej', 'Nowak', 'Poznan, Dabowskiego 16/4', '2018-03-12', 3);

-- --------------------------------------------------------

--
-- Table structure for table `lowisko`
--

CREATE TABLE `lowisko` (
  `id` int(10) UNSIGNED NOT NULL,
  `Ryby_id` int(10) UNSIGNED NOT NULL,
  `akwen` text DEFAULT NULL,
  `wojewodztwo` text DEFAULT NULL,
  `rodzaj` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `lowisko`
--

INSERT INTO `lowisko` (`id`, `Ryby_id`, `akwen`, `wojewodztwo`, `rodzaj`) VALUES
(1, 2, 'Zalew Wegrowski', 'Mazowieckie', 4),
(2, 3, 'Zbiornik Bukowka', 'Dolnoslaskie', 2),
(3, 2, 'Jeziorko Bartbetowskie', 'Warminsko-Mazurskie', 2),
(4, 1, 'Warta-Obrzycko', 'Wielkopolskie', 3),
(5, 2, 'Stawy Milkow', 'Podkarpackie', 5),
(6, 7, 'Przemsza k. Okradzinowa', 'Slaskie', 3);

-- --------------------------------------------------------

--
-- Table structure for table `matematycy`
--

CREATE TABLE `matematycy` (
  `id` int(10) UNSIGNED NOT NULL,
  `imie` text DEFAULT NULL,
  `nazwisko` text DEFAULT NULL,
  `rok_urodzenia` int(10) DEFAULT NULL,
  `liczba_publikacji` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `matematycy`
--

INSERT INTO `matematycy` (`id`, `imie`, `nazwisko`, `rok_urodzenia`, `liczba_publikacji`) VALUES
(1, 'Stefan', 'Banach', 1892, 20),
(2, 'Leonardo', 'Fibonacci', 1175, 15),
(3, 'Augustin', 'Cauchy', 1789, 10),
(4, 'Leonard', 'Euler', 1707, 30),
(5, 'Gotfried', 'Leibniz', 1646, 40);

-- --------------------------------------------------------

--
-- Table structure for table `miasta`
--

CREATE TABLE `miasta` (
  `id` int(10) UNSIGNED NOT NULL,
  `nazwa` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `miasta`
--

INSERT INTO `miasta` (`id`, `nazwa`) VALUES
(1, 'Wroclaw'),
(2, 'Poznan'),
(3, 'Warszawa'),
(4, 'Gdansk'),
(5, 'Zielona Góra'),
(6, 'Lublin'),
(7, 'Tychy'),
(8, 'Katowice'),
(9, 'Opole'),
(10, 'Zakopane'),
(11, 'Kraków'),
(12, 'Szczecin'),
(13, 'Gdynia'),
(14, 'Koszalin'),
(15, 'Malbork');

-- --------------------------------------------------------

--
-- Table structure for table `okres_ochronny`
--

CREATE TABLE `okres_ochronny` (
  `id` int(10) UNSIGNED NOT NULL,
  `Ryby_id` int(10) UNSIGNED NOT NULL,
  `od_miesiaca` int(10) UNSIGNED DEFAULT NULL,
  `do_miesiaca` int(10) UNSIGNED DEFAULT NULL,
  `wymiar_ochronny` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `okres_ochronny`
--

INSERT INTO `okres_ochronny` (`id`, `Ryby_id`, `od_miesiaca`, `do_miesiaca`, `wymiar_ochronny`) VALUES
(1, 1, 1, 4, 50),
(2, 2, 0, 0, 30),
(3, 3, 1, 5, 50),
(4, 4, 0, 0, 15),
(5, 5, 11, 6, 70),
(6, 6, 0, 0, 0),
(7, 7, 0, 0, 0),
(8, 8, 0, 0, 25);

-- --------------------------------------------------------

--
-- Table structure for table `pogoda`
--

CREATE TABLE `pogoda` (
  `id` int(10) UNSIGNED NOT NULL,
  `miasta_id` int(10) UNSIGNED NOT NULL,
  `data_prognozy` date DEFAULT NULL,
  `temperatura_noc` int(11) DEFAULT NULL,
  `temperatura_dzien` int(11) DEFAULT NULL,
  `opady` int(10) UNSIGNED DEFAULT NULL,
  `cisnienie` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `pogoda`
--

INSERT INTO `pogoda` (`id`, `miasta_id`, `data_prognozy`, `temperatura_noc`, `temperatura_dzien`, `opady`, `cisnienie`) VALUES
(1, 1, '2019-05-31', 15, 23, 33, 1020),
(2, 1, '2019-05-10', 15, 23, 0, 1020),
(3, 1, '2019-05-11', 14, 22, 0, 1020),
(4, 1, '2019-05-12', 10, 14, 0, 1020),
(5, 1, '2019-05-13', 6, 15, 0, 1020),
(6, 1, '2019-05-14', 5, 11, 7, 1000),
(7, 1, '2019-05-15', 6, 11, 33, 1000),
(8, 1, '2019-05-16', 6, 15, 32, 997),
(9, 1, '2019-05-17', 12, 20, 11, 997),
(10, 2, '2019-05-11', 11, 23, 0, 1020),
(11, 2, '2019-05-12', 5, 20, 0, 1020),
(12, 2, '2019-05-13', 5, 20, 0, 1020),
(13, 2, '2019-05-14', 8, 23, 4, 1000),
(14, 2, '2019-05-15', 8, 19, 4, 1000),
(15, 2, '2019-05-16', 11, 17, 30, 995),
(16, 2, '2019-05-17', 11, 15, 30, 995),
(17, 2, '2019-05-18', 12, 15, 30, 996);

-- --------------------------------------------------------

--
-- Table structure for table `publikacje`
--

CREATE TABLE `publikacje` (
  `id` int(11) NOT NULL,
  `tytul` text DEFAULT NULL,
  `rok` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `ryby`
--

CREATE TABLE `ryby` (
  `id` int(10) UNSIGNED NOT NULL,
  `nazwa` text DEFAULT NULL,
  `wystepowanie` text DEFAULT NULL,
  `styl_zycia` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `ryby`
--

INSERT INTO `ryby` (`id`, `nazwa`, `wystepowanie`, `styl_zycia`) VALUES
(1, 'Szczupak', 'stawy, rzeki', 1),
(2, 'Karp', 'stawy, jeziora', 2),
(3, 'Sandacz', 'stawy, jeziora, rzeki', 1),
(4, 'Okon', 'rzeki', 1),
(5, 'Sum', 'jeziora, rzeki', 1),
(6, 'Dorsz', 'morza, oceany', 1),
(7, 'Leszcz', 'jeziora', 2),
(8, 'Lin', 'jeziora', 2);

-- --------------------------------------------------------

--
-- Table structure for table `uzytkownik`
--

CREATE TABLE `uzytkownik` (
  `id` int(10) UNSIGNED NOT NULL,
  `imie` text DEFAULT NULL,
  `nazwisko` text DEFAULT NULL,
  `telefon` text DEFAULT NULL,
  `email` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `uzytkownik`
--

INSERT INTO `uzytkownik` (`id`, `imie`, `nazwisko`, `telefon`, `email`) VALUES
(1, 'Anna', 'Kowalska', '601601601', 'anna@poczta.pl'),
(2, 'Jan', 'Nowak', '608608608', 'jan@poczta.pl'),
(3, 'Jolanta', 'Jasny', '606606606', 'jolanta@poczta.pl'),
(4, 'qqq', 'www', '345', 'dsfsdklfs@daskl');

-- --------------------------------------------------------

--
-- Table structure for table `wyniki`
--

CREATE TABLE `wyniki` (
  `id` int(10) UNSIGNED NOT NULL,
  `dyscyplina_id` int(10) UNSIGNED NOT NULL,
  `sportowiec_id` int(10) UNSIGNED NOT NULL,
  `wynik` decimal(5,2) DEFAULT NULL,
  `dataUstanowienia` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `wyniki`
--

INSERT INTO `wyniki` (`id`, `dyscyplina_id`, `sportowiec_id`, `wynik`, `dataUstanowienia`) VALUES
(1, 1, 1, 12.40, '2015-10-14'),
(2, 1, 1, 12.00, '2015-10-06'),
(3, 1, 2, 11.80, '2015-10-14'),
(4, 1, 2, 11.90, '2015-10-06'),
(5, 1, 3, 11.50, '2015-10-14'),
(6, 1, 3, 11.56, '2015-10-06'),
(7, 1, 4, 11.70, '2015-10-14'),
(8, 1, 4, 11.67, '2015-10-06'),
(9, 1, 5, 11.30, '2015-10-14'),
(10, 1, 5, 11.52, '2015-10-06'),
(11, 1, 6, 12.10, '2015-10-14'),
(12, 1, 6, 12.00, '2015-10-06'),
(13, 3, 1, 63.00, '2015-11-11'),
(14, 3, 1, 63.60, '2015-10-13'),
(15, 3, 2, 64.00, '2015-11-11'),
(16, 3, 2, 63.60, '2015-10-13'),
(17, 3, 3, 60.00, '2015-11-11'),
(18, 3, 3, 61.60, '2015-10-13'),
(19, 3, 4, 63.50, '2015-11-11'),
(20, 3, 4, 63.60, '2015-10-13'),
(21, 3, 5, 70.00, '2015-10-07'),
(22, 3, 6, 68.00, '2015-10-07');

-- --------------------------------------------------------

--
-- Table structure for table `zamowienia`
--

CREATE TABLE `zamowienia` (
  `id` int(10) UNSIGNED NOT NULL,
  `Samochody_id` int(10) UNSIGNED NOT NULL,
  `Klient` text DEFAULT NULL,
  `telefon` text DEFAULT NULL,
  `dataZam` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `zamowienia`
--

INSERT INTO `zamowienia` (`id`, `Samochody_id`, `Klient`, `telefon`, `dataZam`) VALUES
(1, 3, 'Anna Kowalska', '111222333', '2016-02-15'),
(2, 6, 'Jan Nowakowski', '222111333', '2016-02-15'),
(3, 8, 'Marcin Kolwal', '333111222', '2016-02-15');

-- --------------------------------------------------------

--
-- Table structure for table `zawody_wedkarskie`
--

CREATE TABLE `zawody_wedkarskie` (
  `id` int(10) UNSIGNED NOT NULL,
  `Karty_wedkarskie_id` int(10) UNSIGNED NOT NULL,
  `Lowisko_id` int(10) UNSIGNED NOT NULL,
  `data_zawodow` date DEFAULT NULL,
  `sedzia` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `zawody_wedkarskie`
--

INSERT INTO `zawody_wedkarskie` (`id`, `Karty_wedkarskie_id`, `Lowisko_id`, `data_zawodow`, `sedzia`) VALUES
(1, 1, 3, '2018-04-12', 'Jan Kowalewski'),
(2, 1, 5, '2018-05-01', 'Jan Kowalewski'),
(3, 1, 2, '2018-06-01', 'Jan Kowalewski'),
(4, 2, 1, '2018-06-21', 'Krzysztof Dobrowolski');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `karty_wedkarskie`
--
ALTER TABLE `karty_wedkarskie`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `lowisko`
--
ALTER TABLE `lowisko`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `matematycy`
--
ALTER TABLE `matematycy`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `miasta`
--
ALTER TABLE `miasta`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `okres_ochronny`
--
ALTER TABLE `okres_ochronny`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `pogoda`
--
ALTER TABLE `pogoda`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `publikacje`
--
ALTER TABLE `publikacje`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `ryby`
--
ALTER TABLE `ryby`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `uzytkownik`
--
ALTER TABLE `uzytkownik`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `wyniki`
--
ALTER TABLE `wyniki`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `zamowienia`
--
ALTER TABLE `zamowienia`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `zawody_wedkarskie`
--
ALTER TABLE `zawody_wedkarskie`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `karty_wedkarskie`
--
ALTER TABLE `karty_wedkarskie`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `lowisko`
--
ALTER TABLE `lowisko`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `matematycy`
--
ALTER TABLE `matematycy`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `miasta`
--
ALTER TABLE `miasta`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `okres_ochronny`
--
ALTER TABLE `okres_ochronny`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `pogoda`
--
ALTER TABLE `pogoda`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT for table `publikacje`
--
ALTER TABLE `publikacje`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `ryby`
--
ALTER TABLE `ryby`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `uzytkownik`
--
ALTER TABLE `uzytkownik`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `wyniki`
--
ALTER TABLE `wyniki`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT for table `zamowienia`
--
ALTER TABLE `zamowienia`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `zawody_wedkarskie`
--
ALTER TABLE `zawody_wedkarskie`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
