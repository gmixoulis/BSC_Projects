-- phpMyAdmin SQL Dump
-- version 4.7.7
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 06, 2018 at 02:39 PM
-- Server version: 10.1.30-MariaDB
-- PHP Version: 7.2.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `car_rental`
--

-- --------------------------------------------------------

--
-- Table structure for table `car`
--

CREATE TABLE `car` (
  `car_id` int(11) NOT NULL,
  `type` varchar(40) NOT NULL,
  `fuel` varchar(40) NOT NULL,
  `seats_num` int(11) NOT NULL,
  `doors` int(11) NOT NULL,
  `conventional` varchar(40) NOT NULL,
  `price` double NOT NULL,
  `shop_id` int(11) NOT NULL,
  `reserved` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `car`
--

INSERT INTO `car` (`car_id`, `type`, `fuel`, `seats_num`, `doors`, `conventional`, `price`, `shop_id`, `reserved`) VALUES
(1, 'Small', 'Gas', 2, 2, 'Yes', 20, 1, 0),
(2, 'Medium', 'Gas', 6, 4, 'Yes', 70, 2, 1),
(3, 'Big ', 'Oil', 8, 4, 'Yes', 120, 6, 1),
(4, 'Small', 'Gas', 2, 4, 'No', 35, 5, 1),
(5, 'Big', 'Oil', 9, 4, 'Yes', 145, 4, 1),
(6, 'Medium', 'Oil', 5, 4, 'No', 60, 3, 1),
(7, 'Big', 'Gas', 9, 4, 'Yes', 150, 3, 1);

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `customer_id` int(11) NOT NULL,
  `surname` varchar(60) NOT NULL,
  `name` varchar(60) NOT NULL,
  `email` varchar(40) NOT NULL,
  `cellphone` varchar(11) NOT NULL,
  `home_phone` varchar(11) NOT NULL,
  `drivers_license` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`customer_id`, `surname`, `name`, `email`, `cellphone`, `home_phone`, `drivers_license`) VALUES
(1, 'Papadopoulos', 'Nikos', 'papad@gmail.com', '6912234556', '2140225599', '12345678');

-- --------------------------------------------------------

--
-- Table structure for table `information`
--

CREATE TABLE `information` (
  `info_id` int(11) NOT NULL,
  `type` varchar(40) NOT NULL,
  `pickup_id` varchar(40) NOT NULL,
  `pickup_date` date NOT NULL,
  `pickup_time` time(6) NOT NULL,
  `drop_id` varchar(40) NOT NULL,
  `drop_date` date NOT NULL,
  `drop_time` time(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `information`
--

INSERT INTO `information` (`info_id`, `type`, `pickup_id`, `pickup_date`, `pickup_time`, `drop_id`, `drop_date`, `drop_time`) VALUES
(1, '', '6', '2018-01-01', '18:00:00.000000', '3', '2018-01-05', '20:00:00.000000');

-- --------------------------------------------------------

--
-- Table structure for table `reservation`
--

CREATE TABLE `reservation` (
  `reservation_id` int(11) NOT NULL,
  `total_price` double NOT NULL,
  `car_car_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reservation`
--

INSERT INTO `reservation` (`reservation_id`, `total_price`, `car_car_id`) VALUES
(1, 480, 3);

-- --------------------------------------------------------

--
-- Table structure for table `search`
--

CREATE TABLE `search` (
  `information_info_id` int(11) NOT NULL,
  `car_car_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `search`
--

INSERT INTO `search` (`information_info_id`, `car_car_id`) VALUES
(1, 3);

-- --------------------------------------------------------

--
-- Table structure for table `shop`
--

CREATE TABLE `shop` (
  `shop_id` int(11) NOT NULL,
  `city` varchar(40) NOT NULL,
  `place` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `shop`
--

INSERT INTO `shop` (`shop_id`, `city`, `place`) VALUES
(1, 'Athens', 'Penteli'),
(2, 'Athens', 'Aigaleo'),
(3, 'Thessaloniki', 'Kalamaria'),
(4, 'Larisa', 'Kentro'),
(5, 'Lamia', 'Kentro'),
(6, 'Giannena', 'Kentro');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `car`
--
ALTER TABLE `car`
  ADD PRIMARY KEY (`car_id`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`customer_id`);

--
-- Indexes for table `information`
--
ALTER TABLE `information`
  ADD PRIMARY KEY (`info_id`);

--
-- Indexes for table `reservation`
--
ALTER TABLE `reservation`
  ADD PRIMARY KEY (`reservation_id`),
  ADD KEY `reservation_car_fk` (`car_car_id`);

--
-- Indexes for table `search`
--
ALTER TABLE `search`
  ADD PRIMARY KEY (`information_info_id`,`car_car_id`),
  ADD KEY `search_car_fk` (`car_car_id`);

--
-- Indexes for table `shop`
--
ALTER TABLE `shop`
  ADD PRIMARY KEY (`shop_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `car`
--
ALTER TABLE `car`
  MODIFY `car_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `customer_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `information`
--
ALTER TABLE `information`
  MODIFY `info_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `reservation`
--
ALTER TABLE `reservation`
  MODIFY `reservation_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `search`
--
ALTER TABLE `search`
  MODIFY `information_info_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `shop`
--
ALTER TABLE `shop`
  MODIFY `shop_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
